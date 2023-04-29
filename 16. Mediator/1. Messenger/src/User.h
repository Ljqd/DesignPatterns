#pragma once

#include <vector>

#include "AbstractUser.h"
#include "AbstractChat.h"

class User : public AbstractUser
{
public:
    User(int id, const std::string& name);

    virtual int getUserId() const override;
    virtual const std::string& getName() const override;

    virtual void recordParticipation(std::shared_ptr<AbstractChat> chat) override;
    virtual void eraseParticipation(std::shared_ptr<AbstractChat> chat) override;

private:
    int id;
    std::string name;

    std::vector<std::shared_ptr<AbstractChat>> chats;
};