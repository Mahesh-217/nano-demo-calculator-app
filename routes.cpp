// #include "crow_all.h"

// crow::response greet()
// {
//     return crow::response{""};
// }
// crow::response add(const crow::request &req)
// {
//     auto input = crow::json::load(req.body);
//     return crow::response{""};
// }
// crow::response subtract(const crow::request &req)
// {
//     auto input = crow::json::load(req.body);
//     return crow::response{""};
// }
#include "crow_all.h"
// #include<bits/stdc++.h>

crow::response greet()
{
    return crow::response{"Hello, welcome to the Crow C++ microframework example!"};
}

crow::response add(const crow::request &req)
{
    auto input = crow::json::load(req.body);
    if (!input)
    {
        return crow::response(400, "Invalid JSON");
    }

    int a = input["a"].i();
    int b = input["b"].i();
    int result = a + b;

    crow::json::wvalue response_json;
    response_json["result"] = result;

    return crow::response{response_json};
}

crow::response subtract(const crow::request &req)
{
    auto input = crow::json::load(req.body);
    if (!input)
    {
        return crow::response(400, "Invalid JSON");
    }

    int a = input["first"].i();
    int b = input["second"].i();
    int result = a - b;

    crow::json::wvalue response_json;
    response_json["result"] = result;

    return crow::response{response_json};
}

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/greet")
    ([] {
        return greet();
    });

    CROW_ROUTE(app, "/add")
    ([](const crow::request &req) {
        return add(req);
    });

    CROW_ROUTE(app, "/subtract")
    ([](const crow::request &req) {
        return subtract(req);
    });

    app.port(8080).multithreaded().run();
}
