#pragma once
#include "Field.h"
#include <string>

class Manager {
private:
    std::string PersoneName;
    int CurrentLevel;

    Field* gameField;

    int DiceRoll();
    void createField(int fieldWidth, int fieldHeight, int obstacles, int monster);
    void generationObjects(int obst, int monst);

public:
    Manager();
    ~Manager();

};