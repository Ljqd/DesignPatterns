#pragma once

#include <iostream>
#include <string>

class Monster
{
public:
    virtual void attack() = 0;

    virtual std::string getLevelAsString() const {
        return std::to_string(level);
    }

    virtual int getLevel() const {
        return level;
    }

    virtual void setLevel(int newLevel) {
        if (level <= 0)
            throw("Error: Monster::setLevel: new level < 1.");

        level = newLevel;
    }

protected:
    int level;
};

