#include <iostream>

#include "src/Pirate.h"
#include "src/Troll.h"

int main()
{
    Pirate pirate = {};
    Troll troll = {};

    pirate.defendAgainstAttack();
    std::cout << std::endl;
    troll.defendAgainstAttack();
}