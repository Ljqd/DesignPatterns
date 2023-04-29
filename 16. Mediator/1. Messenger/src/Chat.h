#pragma once

#include <memory>
#include <unordered_map>
#include <iostream>

#include "AbstractChat.h"
#include "AbstractUser.h"
#include "AbstractChatParticipant.h"
#include "AbstractChatMediator.h"

class Chat : public AbstractChat
{
public:
    Chat(int id, std::shared_ptr<AbstractUser> creator);

    virtual void addUserAsParticipant(std::shared_ptr<AbstractUser> user) override;

    virtual void removeParticipant(int userId) override;
    virtual void removeParticipant(std::shared_ptr<AbstractChatParticipant> participant) override;

    virtual std::shared_ptr<AbstractChatParticipant> getParticipant(int id) override;
    virtual std::vector<std::shared_ptr<AbstractChatParticipant>> getParticipants() override;

    virtual std::shared_ptr<AbstractChatParticipant> getAdmin() override;

    virtual void printMessage(std::shared_ptr<AbstractChatParticipant> sender, const std::string& message) override;
    virtual void printMessageTo(std::shared_ptr<AbstractChatParticipant> sender, const std::string& message, std::shared_ptr<AbstractChatParticipant> recepient) override;

    virtual std::shared_ptr<AbstractChatMediator> getEntryPoint() override;

protected:
    int id;
    std::shared_ptr<AbstractChatMediator> mediator;

    std::shared_ptr<AbstractChatParticipant> admin;
    std::unordered_map<int, std::shared_ptr<AbstractChatParticipant>> participants;
};