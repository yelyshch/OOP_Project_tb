#ifndef OOP_LAB_CHARACTER_H
#define OOP_LAB_CHARACTER_H

#include <iostream>
#include <stdlib.h> //рандомайз
#include <ctime>
#include <windows.h>

class Character {
private:
    int health;
    int damage;
    int protection;
    int distance;

protected:
    void setHealth(int value);
    void setDamage(int value);
    void setProtection(int value);
    void setDistance(int value);

    int getHealth() const;
    int getDamage() const;
    int getProtection() const;
    int getDistance() const;

public:
    const int maxValue = 6;
    Character(int health, int damage, int protection, int distance);

    void increaseHealth(int amount);
    void increaseDamage(int amount);
    void increaseProtection(int amount);
    void increaseDistance(int amount);
};

class Hero : public Character {
private:
    int speed;

public:
    using Character::Character;
    void diceResults(int firstRoll, int secondRoll, int thirdRoll);
    void restoreHealth();
};

class Monster : public Character {
private:
    bool active;

public:
    using Character::Character;
    void setActive(bool active);
};

#endif //OOP_LAB_CHARACTER_H
