#pragma once

#include <string>
#include <vector>
#include <memory>

#include "User.h"

#include "LoginHandler.h"
#include "PasswordHandler.h"



class Database
{
public:
    Database();

    void addUser(const User& user);

    void addUser(const std::shared_ptr<User> sharedUser);

    std::string get(const Request& request);

    bool hasLogin(std::string login) const;

    bool isPasswordValid(std::string login, std::string password) const;

private:
    std::vector<std::shared_ptr<User>> users;
    std::shared_ptr<Handler> authenticationHandler;
};