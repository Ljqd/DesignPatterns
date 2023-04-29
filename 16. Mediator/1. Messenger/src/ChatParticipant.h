#pragma once

#include <memory>

class AbstractChat;
class AbstractChatParticipant;
class AbstractChatMediator;

#include "AbstractChat.h"
#include "AbstractChatParticipant.h"
#include "AbstractChatMediator.h"
#include "Privilege.h"

class ChatParticipant : public AbstractChatParticipant
{
public:
    ChatParticipant(std::shared_ptr<AbstractChatMediator> mediator, std::shared_ptr<AbstractUser> user, Privilege privilege = Privilege::CASUAL);

    // AbstractUser interface
    virtual int getUserId() const override;
    virtual const std::string& getName() const override;

    virtual void recordParticipation(std::shared_ptr<AbstractChat> chat) override;
    virtual void eraseParticipation(std::shared_ptr<AbstractChat> chat) override;

    // AbstractChatParticipant interface
    virtual void assign(const Privilege& privilege) override;
    virtual void demote() override;
    virtual Privilege getPrivilege() const override;

    virtual void sendMessage(int senderId, const std::string& message) override;
    virtual void sendMessageTo(int senderId, int recipientId, const std::string& message) override;

protected:
    std::shared_ptr<AbstractChatMediator> mediator;
    std::shared_ptr<AbstractUser> user;
    Privilege privilege;
};