#include "Field.h"
#include <cstdlib> // for rand()

bool Field::isWithinBounds(int x, int y) const {
    return x >= 0 && x < width && y >= 0 && y < height;
}

bool Field::isCellFreeAroundHero(int heroX, int heroY) const {
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            int x = heroX + dx;
            int y = heroY + dy;

            if (isWithinBounds(x, y) && (cells[y][x].hasObstacle() || cells[y][x].hasUnitPresent()))
                return false;
        }
    }
    return true;
}

Field::Field(int m, int n) : width(m), height(n) {
    cells = new Cell * [height];
    for (int i = 0; i < height; ++i) {
        cells[i] = new Cell[width];
    }
}

void Field::placeHero() {
    int x = width / 2;
    int y = 1;
    cells[y][x].setUnitPresent(true);
}

void Field::placeObstacles(int obstacleCount) {
    for (int i = 0; i < obstacleCount; ++i) {
        int x, y;
        do {
            x = rand() % width;
            y = rand() % height;
        } while (!isCellFreeAroundHero(x, y));

        cells[y][x].setObstacle(true);
    }
}

void Field::placeMonsters(int monsterCount) {
    for (int i = 0; i < monsterCount; ++i) {
        int x, y;
        do {
            x = rand() % width;
            y = rand() % height;
        } while (!isCellFreeAroundHero(x, y));

        cells[y][x].setUnitPresent(true);
    }
}

Field::~Field() {
    for (int i = 0; i < height; ++i) {
        delete[] cells[i];
    }
    delete[] cells;
}