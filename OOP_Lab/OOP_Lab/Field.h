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
    // Copy Constructor
    Field(const Field& other);
    // Copy Assignment Operator
    Field& operator=(const Field& other);
    // Move Constructor
    Field(Field&& other) noexcept;
    // Move Assignment Operator
    Field& operator=(Field&& other) noexcept;
    ~Field();
};