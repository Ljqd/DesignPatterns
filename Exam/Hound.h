#pragma once

#include <iostream>
#include "Monster.h"

class Hound : public Monster
{
public:
    Hound() {
        level = 1;
    }
    Hound(int level) {
        this->level = level;
    }
    void attack() override {
        std::cout << "Creature: Hound (" << level << "), action: bite\n";
    }
};

