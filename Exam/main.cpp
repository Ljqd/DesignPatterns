#include <iostream>
#include <memory>

#include "GameScene.h"

#include "Monster.h"
#include "MonsterFactory.h"

#include "DemonFactory.h"
#include "HoundFactory.h"
#include "ImpFactory.h"
#include "ZombieFactory.h"


int main()
{
    std::shared_ptr<MonsterFactory> demonFactory = std::make_shared<DemonFactory>();
    std::shared_ptr<MonsterFactory> houndFactory = std::make_shared<HoundFactory>();
    std::shared_ptr<MonsterFactory> impFactory = std::make_shared<ImpFactory>();
    std::shared_ptr<MonsterFactory> zombieFactory = std::make_shared<ZombieFactory>();

    std::shared_ptr<GameScene> gameScene = GameScene::getInstance();

    gameScene->addMonster(demonFactory->createLowLevel());
    gameScene->addMonster(demonFactory->createLowLevel());
    gameScene->addMonster(demonFactory->createHighLevel());

    gameScene->addMonster(houndFactory->createAverageLevel());

    gameScene->addMonster(impFactory->createLowLevel());
    gameScene->addMonster(impFactory->createLowLevel());
    gameScene->addMonster(impFactory->createLowLevel());

    gameScene->addMonster(zombieFactory->createLowLevel());
    gameScene->addMonster(zombieFactory->createAverageLevel());

    gameScene->start();
}



