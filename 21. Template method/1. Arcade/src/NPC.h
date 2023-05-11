#pragma once

class NPC
{
public:
    virtual void pickUpWeapon() = 0;
    virtual void defenseAction() = 0;
    virtual void moveToSafety() = 0;

    virtual void defendAgainstAttack() {
        pickUpWeapon();
        defenseAction();
        moveToSafety();
    }
};