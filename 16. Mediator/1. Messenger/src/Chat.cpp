#include "Chat.h"

#include "ChatMediator.h"
#include "ChatParticipant.h"


Chat::Chat(int id, std::shared_ptr<AbstractUser> creator) : id(id)
{
    mediator = std::make_shared<ChatMediator>(this);
    admin = std::make_shared<ChatParticipant>(mediator, creator);
}

void Chat::addUserAsParticipant(std::shared_ptr<AbstractUser> user)
{
    std::shared_ptr<AbstractChatParticipant> newbie = std::make_shared<ChatParticipant>(mediator, user);
    participants[newbie->getUserId()] = newbie;
}

void Chat::removeParticipant(int userId)
{
    if (participants.find(userId) != participants.end())
        participants.erase(userId);
}

void Chat::removeParticipant(std::shared_ptr<AbstractChatParticipant> participant)
{
    removeParticipant(participant->getUserId());
}


std::shared_ptr<AbstractChatParticipant> Chat::getParticipant(int id)
{
    return participants[id];
}

std::vector<std::shared_ptr<AbstractChatParticipant>> Chat::getParticipants()
{
    std::vector<std::shared_ptr<AbstractChatParticipant>> values;
    for (const auto& pair : participants) {
        values.push_back(pair.second);
    }
    return values;
}

std::shared_ptr<AbstractChatParticipant> Chat::getAdmin()
{
    return admin;
}

void Chat::printMessage(std::shared_ptr<AbstractChatParticipant> sender, const std::string& message)
{
    std::string senderName = sender->getName();

    std::cout << "Chat #" << std::to_string(id) << " ";
    std::cout << senderName << ": " << message << '\n';
}

void Chat::printMessageTo(std::shared_ptr<AbstractChatParticipant> sender, const std::string& message, std::shared_ptr<AbstractChatParticipant> recepient)
{
    std::string senderName = sender->getName();
    std::string recepientName = recepient->getName();

    std::cout << "Chat #" << std::to_string(id) << " ";
    std::cout << senderName << " to " << recepientName << ": " << message << '\n';
}

std::shared_ptr<AbstractChatMediator> Chat::getEntryPoint()
{
    return mediator;
}