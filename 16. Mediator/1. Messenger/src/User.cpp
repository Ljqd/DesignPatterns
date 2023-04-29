#include "User.h"

User::User(int id, const std::string& name) : id(id), name(name) {}

int User::getUserId() const
{
    return id;
}

const std::string& User::getName() const 
{
    return name;
}

void User::recordParticipation(std::shared_ptr<AbstractChat> chat)
{
    chats.push_back(chat);
}

void User::eraseParticipation(std::shared_ptr<AbstractChat> chat)
{
    //auto iter = std::find(chats.begin(), chats.end(), chats);
    //if (iter != chats.end())
    //    chats.erase(iter);
}