#pragma once

#include <string>
#include <memory>

class AbstractUser;

#include "AbstractUser.h"
#include "Privilege.h"

class AbstractChatMediator
{
public:
    // Communication: User -> Chat
    virtual void sendMessage(int senderId, const std::string& message) = 0;
    virtual void sendMessageTo(int senderId, int recipientId, const std::string& message) = 0;

    // Communication: User -> Chat
    virtual void addUser(std::shared_ptr<AbstractUser> user) = 0;
    virtual void removeUser(std::shared_ptr<AbstractUser> user) = 0;

    // Communication: User (admin/moderator) -> Chat -> User
    virtual void assign(int userId, const Privilege& privilege) = 0;
    virtual void demote(int userId) = 0;
};