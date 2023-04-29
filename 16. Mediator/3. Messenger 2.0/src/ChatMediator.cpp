#include "ChatMediator.h"

#include "Privilege.h"


ChatMediator::ChatMediator(AbstractChat* chat) : chat(chat) {}


void ChatMediator::sendMessage(int senderId, const std::string& message)
{
    auto user1 = chat->getParticipant(senderId);
    chat->printMessage(user1, message);
}

void ChatMediator::sendMessageTo(int senderId, int recipientId, const std::string& message)
{
    auto user1 = chat->getParticipant(senderId);
    auto user2 = chat->getParticipant(recipientId);

    chat->printMessageTo(user1, message, user2);

}

void ChatMediator::addUser(std::shared_ptr<AbstractUser> user)
{
    chat->addUserAsParticipant(user);
}

void ChatMediator::removeUser(std::shared_ptr<AbstractUser> user)
{
    chat->removeParticipant(user->getUserId());
}

void ChatMediator::assign(int userId, const Privilege& privilege)
{
    auto participant = chat->getParticipant(userId);
    if (participant->getPrivilege() != Privilege::ADMIN)
        participant->assign(privilege);
}

void ChatMediator::demote(int userId)
{
    auto participant = chat->getParticipant(userId);
    if (participant->getPrivilege() != Privilege::ADMIN)
        participant->assign(Privilege::CASUAL);
}

void ChatMediator::notifyEmpowered(const std::string& message)
{
    auto participants = chat->getParticipants();
    for (auto participant : participants)
    {
        if (participant->getPrivilege() != Privilege::CASUAL)
            chat->printMessage(participant, "NOTIFICATION: " + message);
    }
}