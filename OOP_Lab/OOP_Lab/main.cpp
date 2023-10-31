#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <windows.h>

using std::string;

class Character
{
private:
    int health;
    int damage;
    int protection;
    int distance;

protected:
    void setHealth(int value) { health = value; }
    void setDamage(int value) { damage = value; }
    void setProtection(int value) { protection = value; }
    void setDistance(int value) { distance = value; }

    int getHealth() const { return health; }
    int getDamage() const { return damage; }
    int getProtection() const { return protection; }
    int getDistance() const { return distance; }

public:
    const int maxValue = 6;
    Character(int health, int damage, int protection, int distance)
        : health(health), damage(damage), protection(protection), distance(distance) {}

    void increaseHealth(int amount) { setHealth(getHealth() + amount); }
    void increaseDamage(int amount) { setDamage(getDamage() + amount); }
    void increaseProtection(int amount) { setProtection(getProtection() + amount); }
    void increaseDistance(int amount) { setDistance(getDistance() + amount); }
};


class Hero : public Character {
private:
    int speed;
public:
    using Character::Character;
    void diceResults(int firstRoll, int secondRoll, int thirdRoll) {
        speed += firstRoll;
        setDamage(getDamage() + secondRoll);
        setProtection(getProtection() + thirdRoll);
    }
    void restoreHealth() { setHealth(maxValue); }
};

class Monster : public Character {
private:
    bool active;
public:
    using Character::Character;
    void setActive(bool active) { active = active; }
};

class Cell
{
private:
    bool isObstacle;
    bool isUnitPresent;

public:

    Cell()
    {
        isObstacle = false;
        isUnitPresent = false;
    }

    void setObstacle(bool obstacle)
    {
        isObstacle = obstacle;
    }
    void setUnitPresent(bool unitPresent)
    {
        isUnitPresent = unitPresent;
    }

    bool hasObstacle() const
    {
        return isObstacle;
    }
    bool hasUnitPresent() const
    {
        return isUnitPresent;
    }

    ~Cell()
    {}
};

class Field
{
private:
    int width;
    int height;
    Cell** cells;

    bool isWithinBounds(int x, int y) const
    {
        return x >= 0 && x < width && y >= 0 && y < height;
    }

    bool isCellFreeAroundHero(int heroX, int heroY) const
    {
        for (int dx = -1; dx <= 1; ++dx)
        {
            for (int dy = -1; dy <= 1; ++dy)
            {
                int x = heroX + dx;
                int y = heroY + dy;

                if (isWithinBounds(x, y) && (cells[y][x].hasObstacle() || cells[y][x].hasUnitPresent()))
                    return false;
            }
        }
        return true;
    }

public:

    Field(int m, int n)
    {
        width = m;
        height = n;

        cells = new Cell * [height];
        for (int i = 0; i < height; ++i)
        {
            cells[i] = new Cell[width];
        }
    }

    void placeHero()
    {
        int x = width / 2;
        int y = 1;
        cells[y][x].setUnitPresent(true);
    }

    void placeObstacles(int obstacleCount)
    {
        for (int i = 0; i < obstacleCount; ++i)
        {
            int x, y;
            do
            {
                x = rand() % width;
                y = rand() % height;
            } while (!isCellFreeAroundHero(x, y));

            cells[y][x].setObstacle(true);
        }
    }

    void placeMonsters(int monsterCount)
    {
        for (int i = 0; i < monsterCount; ++i)
        {
            int x, y;
            do
            {
                x = rand() % width;
                y = rand() % height;
            } while (!isCellFreeAroundHero(x, y));

            cells[y][x].setUnitPresent(true);
        }
    }

    ~Field()
    {
        for (int i = 0; i < height; ++i)
        {
            delete[] cells[i];
        }
        delete[] cells;
    }
};

class Manager
{
private:
    string PersoneName;
    int CurrentLevel;
    Character MainCharacter;
    Monster Monsters[3];

    Field* gameField;

    void createField(int fieldWidth, int fieldHeight, int obstacles, int monster)
    {
        gameField = new Field(fieldWidth, fieldHeight);
        generationObjects(obstacles, monster);
    }

    void generationObjects(int obst, int monst)
    {
        gameField->placeHero();

        gameField->placeObstacles(obst);
        gameField->placeMonsters(monst);
    }

public:
    //void setPersoneName();
    //void setNewLevel(int CurentLevel);

    Manager();

    ~Manager()
    {
        delete gameField;
    }
};

int DiceRoll(int type_of_roll)
{
    return rand() % 6 + 1;
}

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    return 0;
}