#pragma once

#include <iostream>
#include "Monster.h"

class Demon : public Monster
{
public:
    Demon() {
        level = 1;
    }
    Demon(int level) {
        this->level = level;
    }
    void attack() override {
        std::cout << "Creature: Demon (" << level << "), action: hit\n";
    }
};
