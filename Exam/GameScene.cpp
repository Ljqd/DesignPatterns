#include "GameScene.h"

std::shared_ptr<GameScene> GameScene::scene = nullptr;

GameScene::GameScene()
{}


std::shared_ptr<GameScene> GameScene::getInstance()
{
    if (scene == nullptr)
        scene = std::shared_ptr<GameScene>(new GameScene());
    return scene;
}

void GameScene::addMonster(std::shared_ptr<Monster> newMonster)
{
    monsters.push_back(newMonster);
}

void GameScene::start()
{
    for (std::shared_ptr<Monster> monster : monsters)
        monster->attack();
}
