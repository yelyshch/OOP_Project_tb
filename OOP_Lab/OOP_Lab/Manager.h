#pragma once
#include "Character.h"
#include "Field.h"
#include <string>

class Manager {
private:
    std::string PersoneName;
    int CurrentLevel;
    Hero Player;
    Field* gameField;

    int DiceRoll();
    void createField(int fieldWidth, int fieldHeight, int obstacles, int monster);
    void generationObjects(int obst, int monst);
    friend void TestLab1(Manager);

public:
    Manager();
    ~Manager();

};
