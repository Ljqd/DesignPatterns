#pragma once

#include <iostream>
#include "NPC.h"

class Troll : public NPC
{
public:
    virtual void pickUpWeapon() override {
        std::cout << "Pick up club" << std::endl;
    }

    virtual void defenseAction() override {
        std::cout << "Defend with club" << std::endl;
    }

    virtual void moveToSafety() override {
        std::cout << "Return to the mountain" << std::endl;
    }
};