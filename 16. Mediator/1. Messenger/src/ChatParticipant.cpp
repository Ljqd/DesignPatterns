#include "ChatParticipant.h"

ChatParticipant::ChatParticipant(std::shared_ptr<AbstractChatMediator> mediator, std::shared_ptr<AbstractUser> user, Privilege privilege)
    : mediator(mediator), user(user), privilege(privilege) {}


int ChatParticipant::getUserId() const
{
    return user->getUserId();
}

const std::string& ChatParticipant::getName() const
{
    return user->getName();
}

void ChatParticipant::recordParticipation(std::shared_ptr<AbstractChat> chat)
{
    user->recordParticipation(chat);
}

void ChatParticipant::eraseParticipation(std::shared_ptr<AbstractChat> chat)
{
    user->eraseParticipation(chat);
}

void ChatParticipant::assign(const Privilege& privilege)
{
    this->privilege = privilege;
}

void ChatParticipant::demote()
{
    privilege = Privilege::CASUAL;
}

Privilege ChatParticipant::getPrivilege() const
{
    return privilege;
}

void ChatParticipant::sendMessage(int senderId, const std::string& message)
{
    mediator->sendMessage(senderId, message);
}

void ChatParticipant::sendMessageTo(int senderId, int recipientId, const std::string& message)
{
    mediator->sendMessageTo(senderId, recipientId, message);
}