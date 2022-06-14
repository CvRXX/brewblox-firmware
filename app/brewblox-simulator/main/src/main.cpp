#include "RecurringTask.hpp"
#include "SimulatorSystem.hpp"
#include "blox_hal/hal_network.hpp"
#include "cbox/Box.hpp"
#include "dynamic_gui/dynamicGui.hpp"
#include "dynamic_gui/util/test_screen.hpp"
#include "gui.hpp"
#include "lvgl.h"
#include "network/cbox_server.hpp"
#include "simulator/virtualScreen.hpp"
#include "simulator/virtualTouchScreen.hpp"
#include "simulator/websocketserver.hpp"
#include <boost/asio.hpp>
#include <boost/asio/dispatch.hpp>
#include <boost/asio/strand.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/program_options.hpp>
#include <thread>

std::shared_ptr<listener> webSocketServer;
net::io_context ioc{1};

int main(int argc, char* argv[])
{
    namespace po = boost::program_options;
    namespace http = boost::beast::http;
    namespace websocket = boost::beast::websocket;
    namespace asio = boost::asio;
    namespace chrono = boost::asio::chrono;
    namespace ip = boost::asio::ip;

    auto desc = po::options_description("Brewblox Simulator");
    desc.add_options()("device_id", po::value<std::string>(), "Spark Device ID");

    po::variables_map argmap;
    po::store(po::command_line_parser(argc, argv).options(desc).run(), argmap);
    po::notify(argmap);

    setDeviceId(argmap["device_id"].as<std::string>());

    webSocketServer = std::make_shared<listener>(ioc, ip::tcp::endpoint{net::ip::make_address("0.0.0.0"), 7377});
    webSocketServer->run();

    setupSystemBlocks();

    using screen = Gui<VirtualScreen, VirtualTouchScreen, gui::dynamic_interface::DynamicGui>;
    screen::init();
    auto testScreen = gui::dynamic_interface::testScreen();
    if (testScreen) {
        screen::interface->setNewScreen(std::move(*testScreen));
    }

    static auto timeSetter = RecurringTask(
        ioc, chrono::milliseconds(20),
        RecurringTask::IntervalType::FROM_EXPIRY,
        []() {
            auto tickMinutes = chrono::system_clock::now().time_since_epoch() / chrono::minutes(1);
            auto minutes = tickMinutes % (60);

            auto tickHours = chrono::system_clock::now().time_since_epoch() / chrono::hours(1);
            auto hours = tickHours % (24) + 2;
            //    gui.bar.setTime(hours, minutes);
        });

    static auto graphicsLooper = RecurringTask(
        ioc, chrono::milliseconds(10),
        RecurringTask::IntervalType::FROM_EXECUTION,
        []() {
            screen::update();
        });

    static auto displayTick = RecurringTask(
        ioc, chrono::milliseconds(10),
        RecurringTask::IntervalType::FROM_EXPIRY,
        []() {
            screen::tick(10);
        });

    static auto updater = RecurringTask(
        ioc, chrono::milliseconds(10),
        RecurringTask::IntervalType::FROM_EXECUTION,
        []() {
            static const auto start = chrono::steady_clock::now().time_since_epoch() / chrono::milliseconds(1);
            const auto now = chrono::steady_clock::now().time_since_epoch() / chrono::milliseconds(1);
            uint32_t millisSinceBoot = now - start;
            cbox::update(millisSinceBoot);
            return true;
        });

    CboxServer cboxServer(ioc, 8332);

    timeSetter.start();
    graphicsLooper.start();
    displayTick.start();
    cbox::loadBlocksFromStorage();
    updater.start();

    cbox::discoverBlocks();
    network::connect();
    // mdns::start();
    ioc.run();
}
