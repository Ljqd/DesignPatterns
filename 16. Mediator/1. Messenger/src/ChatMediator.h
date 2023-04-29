#pragma once

#include <string>
#include <unordered_map>

class AbstractChatMediator;
class AbstractChat;
class AbstractUser;

#include "AbstractChatMediator.h"
#include "AbstractChat.h"
#include "AbstractUser.h"

class ChatMediator : public AbstractChatMediator
{
public:
    ChatMediator(AbstractChat* chat);

    virtual void sendMessage(int senderId, const std::string& message) override;
    virtual void sendMessageTo(int senderId, int recipientId, const std::string& message) override;

    virtual void addUser(std::shared_ptr<AbstractUser> user) override;
    virtual void removeUser(std::shared_ptr<AbstractUser> user) override;

    virtual void assign(int userId, const Privilege& privilege) override;
    virtual void demote(int userId) override;

protected:
    AbstractChat* chat;
};