#pragma once

#include <iostream>
#include "Monster.h"

class Imp : public Monster
{
public:
    Imp() {
        level = 1;
    }
    Imp(int level) {
        this->level = level;
    }
    void attack() override {
        std::cout << "Creature: Imp (" << level << "), action: shoot\n";
    }
};

