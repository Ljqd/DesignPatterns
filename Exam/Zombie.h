#pragma once

#include <iostream>
#include "Monster.h"

class Zombie : public Monster
{
public:
    Zombie() {
        level = 1;
    }
    Zombie(int level) {
        this->level = level;
    }
    void attack() override {
        std::cout << "Creature: Zombie (" << level << "), action: grabs\n";
    }
};
