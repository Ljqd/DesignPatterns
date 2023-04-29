#pragma once

#include <string>

class AbstractUser;

#include "Privilege.h"
#include "AbstractUser.h"

class AbstractChatParticipant : public AbstractUser
{
public:
    virtual void assign(const Privilege& privilege) = 0;
    virtual void demote() = 0;
    virtual Privilege getPrivilege() const = 0;

    virtual void sendMessage(int senderId, const std::string& message) = 0;
    virtual void sendMessageTo(int senderId, int recipientId, const std::string& message) = 0;
};