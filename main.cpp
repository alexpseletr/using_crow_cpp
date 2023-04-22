#include "crow.h"
//#include "crow_all.h"

int main()
{
    crow::SimpleApp app;

    //define your endpoint at the root directory
   CROW_ROUTE(app, "/<string>")([](std::string name){ // 
        auto page = crow::mustache::load("index.html"); // 
        crow::mustache::context ctx ({{"person", name}}); // 
        return page.render(ctx); //
    });

    app.port(8080).multithreaded().run();
}