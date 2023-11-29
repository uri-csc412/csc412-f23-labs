#include "crow.h"
#include <unordered_set>
#include <mutex>

#define IPADDRESS 9095

int main() {
    crow::SimpleApp app;

    std::mutex mtx;;
    std::unordered_map<crow::websocket::connection*, std::string> userMap;

    CROW_ROUTE(app, "/ws")
        .websocket()
        .onopen([&](crow::websocket::connection& conn){
            CROW_LOG_INFO << "New websocket connection";
            std::lock_guard<std::mutex> _(mtx);
            // TODO: assign a default username, maybe an IP or something from the client?
            userMap[&conn] = "Anonymous"; 
        })
        .onclose([&](crow::websocket::connection& conn, const std::string& /*reason*/){
            CROW_LOG_INFO << "Websocket connection closed";
            std::lock_guard<std::mutex> _(mtx);
            userMap.erase(&conn);
        })
        .onmessage([&](crow::websocket::connection& /*conn*/, const std::string& data, bool is_binary){
            std::lock_guard<std::mutex> _(mtx);
            for(auto& user : userMap) {
                if (is_binary)
                    user.first->send_binary(data);
                else
                    // broadcast username along with the message
                    user.first->send_text(user.second + ": " + data);
            }
        });

    CROW_ROUTE(app, "/")
    ([]{
        char name[256];
        gethostname(name, 256);
        crow::mustache::context x;
        x["servername"] = name;
        auto page = crow::mustache::load("ws.html");
        return page.render(x);
    });

    /*
    *   TODO: add a route that loads the htmx.html web-page
    */
   // CROW_ROUTE(app, "/htmx")


   /*
    *   TODO: add a route that return an HTML string that says `hello from server`
    *   How can Crow just return a string and not a full HTML page?
    */
   // CROW_ROUTE(app, "/send-message")

    app.port(IPADDRESS)
        .multithreaded()
        .run();
}