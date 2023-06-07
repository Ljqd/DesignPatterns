#pragma once

#include "Monster.h"

#include <memory>
#include <vector>

class GameScene
{
public:
    static std::shared_ptr<GameScene> getInstance();

    void addMonster(std::shared_ptr<Monster> newMonster);
    void start();

private:
    GameScene();

    std::vector<std::shared_ptr<Monster>> monsters;
    static std::shared_ptr<GameScene> scene;
};

