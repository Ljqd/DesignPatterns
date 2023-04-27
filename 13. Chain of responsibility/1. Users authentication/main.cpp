#include <iostream>

#include "src/Request.h"
#include "src/User.h"
#include "src/Database.h"

int main()
{
    Database database = {};

    User user1 = { 1, "LoginAlice", "78634823" };
    User user2 = { 2, "LoginBob", "qwerty" };
    User user3 = { 3, "LoginEve", "admin" };

    database.addUser(user1);
    database.addUser(user2);
    database.addUser(user3);

    Request request1 = { "Login", "Password" };
    Request request2 = { "LoginAlice", "qwerty" };
    Request request3 = { "LoginEve", "admin" };

    std::cout << database.get(request1) << std::endl;
    std::cout << database.get(request2) << std::endl;
    std::cout << database.get(request3) << std::endl;
}