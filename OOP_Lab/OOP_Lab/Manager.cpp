#include "Manager.h"

Manager::Manager() : CurrentLevel(1), gameField(nullptr) {}

void Manager::createField(int fieldWidth, int fieldHeight, int obstacles, int monster) {
    gameField = new Field(fieldWidth, fieldHeight);
    generationObjects(obstacles, monster);
}

void Manager::generationObjects(int obst, int monst) {
    gameField->placeHero();
    gameField->placeObstacles(obst);
    gameField->placeMonsters(monst);
}

Manager::~Manager() {
    delete gameField;
}