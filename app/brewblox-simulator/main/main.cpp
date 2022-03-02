
#include "FT6236.hpp"
#include "RecurringTask.hpp"
#include "dynamic_gui/dynamicGui.hpp"
#include "graphics.hpp"
#include "lvgl.h"
#include "virtualScreen.hpp"
#include "websocketserver.hpp"
#include <boost/asio.hpp>
#include <boost/asio/dispatch.hpp>
#include <boost/asio/strand.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>

#include <thread>
std::shared_ptr<listener> webSocketServer;
net::io_context ioc{1};

int main()
{
    namespace beast = boost::beast;         // from <boost/beast.hpp>
    namespace http = beast::http;           // from <boost/beast/http.hpp>
    namespace websocket = beast::websocket; // from <boost/beast/websocket.hpp>
    namespace net = boost::asio;            // from <boost/asio.hpp>
    using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

    webSocketServer = std::make_shared<listener>(ioc, tcp::endpoint{net::ip::make_address("0.0.0.0"), 7377});
    webSocketServer->run();

    using graphics = Graphics<VirtualScreen, FT6236, DynamicGui>;
    graphics::init();

    static auto timeSetter = RecurringTask(ioc, boost::asio::chrono::milliseconds(1000),
                                           RecurringTask::IntervalType::FROM_EXPIRY,
                                           []() {
                                               auto tickMinutes = boost::asio::chrono::system_clock::now().time_since_epoch() / asio::chrono::minutes(1);
                                               auto minutes = tickMinutes % (60);

                                               auto tickHours = boost::asio::chrono::system_clock::now().time_since_epoch() / asio::chrono::hours(1);
                                               auto hours = tickHours % (24) + 2;
                                               //    graphics.bar.setTime(hours, minutes);
                                           });
    timeSetter.start();

    static auto graphicsLooper = RecurringTask(ioc, boost::asio::chrono::milliseconds(10),
                                               RecurringTask::IntervalType::FROM_EXPIRY,
                                               []() {
                                                   lv_task_handler();
                                               });
    graphicsLooper.start();

    static auto displayTick = RecurringTask(ioc, boost::asio::chrono::milliseconds(10),
                                            RecurringTask::IntervalType::FROM_EXPIRY,
                                            []() {
                                                lv_tick_inc(10);
                                            });
    displayTick.start();

    ioc.run();
}
