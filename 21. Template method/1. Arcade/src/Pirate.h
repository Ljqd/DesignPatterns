#pragma once

#include <iostream>
#include "NPC.h"

class Pirate : public NPC
{
public:
    virtual void pickUpWeapon() override {
        std::cout << "Pick up sword" << std::endl;
    }

    virtual void defenseAction() override {
        std::cout << "Defend with sword" << std::endl;
    }

    virtual void moveToSafety() override {
        std::cout << "Return to the ship" << std::endl;
    }
};