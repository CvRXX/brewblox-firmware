#include "RecurringTask.hpp"
#include "SimulatorSystem.hpp"
#include "blox_hal/hal_network.hpp"
#include "cbox/Box.hpp"
#include "dynamic_gui/dynamicGui.hpp"
#include "dynamic_gui/util/2x3grid.hpp"
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

static constexpr uint16_t WEBSOCKET_PORT = 7377;
static constexpr uint16_t CBOX_PORT = 8332;
static constexpr uint32_t TICK_INTERVAL = 10;

// declared as extern by virtualTouchScreen.hpp
// TODO(Carlos): refactor
std::shared_ptr<listener> webSocketServer;

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

    net::io_context ioc{1};

    webSocketServer = std::make_shared<listener>(ioc, ip::tcp::endpoint{net::ip::make_address("0.0.0.0"), WEBSOCKET_PORT});
    webSocketServer->run();

    setupSystemBlocks();

    using screen = Gui<VirtualScreen, VirtualTouchScreen, gui::dynamic_interface::DynamicGui>;
    screen::init();

    static auto timeSetter = RecurringTask(
        ioc, chrono::milliseconds(TICK_INTERVAL),
        RecurringTask::IntervalType::FROM_EXPIRY,
        []() {
            // TODO(Carlos): implement
            // auto tickMinutes = chrono::system_clock::now().time_since_epoch() / chrono::minutes(1);
            // auto minutes = tickMinutes % (60);

            // auto tickHours = chrono::system_clock::now().time_since_epoch() / chrono::hours(1);
            // auto hours = tickHours % (24) + 2;
            // gui.bar.setTime(hours, minutes);
        });

    static auto graphicsLooper = RecurringTask(
        ioc, chrono::milliseconds(TICK_INTERVAL),
        RecurringTask::IntervalType::FROM_EXECUTION,
        []() {
            screen::update();
        });

    static auto displayTick = RecurringTask(
        ioc, chrono::milliseconds(TICK_INTERVAL),
        RecurringTask::IntervalType::FROM_EXPIRY,
        []() {
            screen::tick(TICK_INTERVAL);
        });

    static auto updater = RecurringTask(
        ioc, chrono::milliseconds(TICK_INTERVAL),
        RecurringTask::IntervalType::FROM_EXECUTION,
        []() {
            static const auto start = chrono::steady_clock::now().time_since_epoch() / chrono::milliseconds(1);
            const auto now = chrono::steady_clock::now().time_since_epoch() / chrono::milliseconds(1);
            uint32_t millisSinceBoot = now - start;
            cbox::update(millisSinceBoot);
            return true;
        });

    static auto configupdate = RecurringTask(
        ioc, chrono::seconds(10),
        RecurringTask::IntervalType::FROM_EXECUTION,
        []() {
            auto testScreen = gui::dynamic_interface::grid();
            if (testScreen) {
                screen::interface->setNewScreen(std::move(*testScreen));
            }
        });

    CboxServer cboxServer(ioc, CBOX_PORT);

    timeSetter.start();
    graphicsLooper.start();
    displayTick.start();
    cbox::loadBlocksFromStorage();
    updater.start();
    configupdate.start();

    cbox::discoverBlocks();
    network::connect();
    // mdns::start();

    ioc.run();
}
