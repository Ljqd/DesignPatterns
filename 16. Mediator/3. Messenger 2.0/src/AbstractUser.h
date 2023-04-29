#pragma once

#include <string>
#include <memory>

class AbstractChat;

class AbstractUser
{
public:
    virtual int getUserId() const = 0;
    virtual const std::string& getName() const = 0;

    virtual void recordParticipation(std::shared_ptr<AbstractChat> chat) = 0;
    virtual void eraseParticipation(std::shared_ptr<AbstractChat> chat) = 0;
};