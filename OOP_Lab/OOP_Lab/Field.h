#pragma once
#include "Cell.h"

class Field {
private:
    int width;
    int height;
    Cell** cells;

    bool isWithinBounds(int x, int y) const;
    bool isCellFreeAroundHero(int heroX, int heroY) const;

public:
    Field(int m, int n);
    void placeHero();
    void placeObstacles(int obstacleCount);
    void placeMonsters(int monsterCount);
    ~Field();
};