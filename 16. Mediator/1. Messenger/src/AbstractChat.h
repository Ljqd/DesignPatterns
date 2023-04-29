#pragma once

#include <memory>
#include <string>
#include <vector>

class AbstractUser;
class AbstractChatParticipant;
class AbstractChatMediator;

#include "AbstractUser.h"
#include "AbstractChatParticipant.h"
#include "AbstractChatMediator.h"

class AbstractChat
{
public:
    virtual void addUserAsParticipant(std::shared_ptr<AbstractUser> user) = 0;

    virtual std::shared_ptr<AbstractChatParticipant> getAdmin() = 0;

    virtual void removeParticipant(int userId) = 0;
    virtual void removeParticipant(std::shared_ptr<AbstractChatParticipant> participant) = 0;
    virtual std::shared_ptr<AbstractChatParticipant> getParticipant(int id) = 0;

    virtual std::vector<std::shared_ptr<AbstractChatParticipant>> getParticipants() = 0;

    virtual void printMessage(std::shared_ptr<AbstractChatParticipant> sender, const std::string& message) = 0;
    virtual void printMessageTo(std::shared_ptr<AbstractChatParticipant> sender, const std::string& message, std::shared_ptr<AbstractChatParticipant> recepient) = 0;

    virtual std::shared_ptr<AbstractChatMediator> getEntryPoint() = 0;
};