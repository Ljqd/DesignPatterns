#pragma once

#include <string>

class User
{
public:
    User(int id, std::string login, std::string password) :
        id(id), login(login), password(password) {}

    int getId() const {
        return id;
    }
    std::string getLogin() const {
        return login;
    }
    std::string getPassword() const {
        return password;
    }

    void setId(int id) {
        this->id = id;
    }
    void setLogin(const std::string login) {
        this->login = login;
    }
    void setPassword(const std::string password) {
        this->password = password;
    }

private:
    int id;
    std::string login;
    std::string password;
};