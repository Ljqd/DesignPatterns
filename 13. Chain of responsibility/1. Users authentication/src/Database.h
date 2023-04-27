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
    Database() {
        std::shared_ptr<LoginHandler> loginHandler = std::make_shared<LoginHandler>(this);
        std::shared_ptr<PasswordHandler> passwordHandler = std::make_shared<PasswordHandler>(this);

        loginHandler->setNext(passwordHandler);

        authenticationHandler = loginHandler;
    }

    void addUser(const User& user) {
        std::shared_ptr<User> ptr = std::make_shared<User>(user);
        users.emplace_back(ptr);
    }

    void addUser(const std::shared_ptr<User> sharedUser) {
        users.emplace_back(sharedUser);
    }

    std::string get(const Request& request) {
        if (authenticationHandler->handle(request))
            return "You successfully passed login and password check";
        return "Auhentication check failed.";
    }

    bool hasLogin(std::string login) const {
        for (const std::shared_ptr<User> user : users)
            if (user->getLogin() == login)
                return true;
        return false;
    }

    bool isPasswordValid(std::string login, std::string password) const {
        for (const std::shared_ptr<User> user : users)
            if (user->getLogin() == login)
                if (user->getPassword() == password)
                    return true;
    }

private:
    std::vector<std::shared_ptr<User>> users;
    std::shared_ptr<Handler> authenticationHandler;
};