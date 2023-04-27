#include "Database.h"

Database::Database()
{
    std::shared_ptr<LoginHandler> loginHandler = std::make_shared<LoginHandler>(this);
    std::shared_ptr<PasswordHandler> passwordHandler = std::make_shared<PasswordHandler>(this);

    loginHandler->setNext(passwordHandler);

    authenticationHandler = loginHandler;
}

void Database::addUser(const User& user)
{
    std::shared_ptr<User> ptr = std::make_shared<User>(user);
    users.emplace_back(ptr);
}

void Database::addUser(const std::shared_ptr<User> sharedUser) {
    users.emplace_back(sharedUser);
}

std::string Database::get(const Request& request)
{
    if (authenticationHandler->handle(request))
        return "You successfully passed login and password check";
    return "Auhentication check failed.";
}

bool Database::hasLogin(std::string login) const
{
    for (const std::shared_ptr<User> user : users)
        if (user->getLogin() == login)
            return true;
    return false;
}

bool Database::isPasswordValid(std::string login, std::string password) const
{
    for (const std::shared_ptr<User> user : users)
        if (user->getLogin() == login)
            if (user->getPassword() == password)
                return true;
    return false;
}