#pragma once
#ifndef OOP_LAB_CHARACTER_H
#define OOP_LAB_CHARACTER_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Field.h"

const int maxValue = 6;
const int startValue = 1;

class Character {
private:
    int char_x, char_y;
    int health;
    int protection;

protected:
    void setHealth(int value);

public:
    int getHealth() const;
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);

    void setProtection(int value);
    int getProtection() const;
    void increaseHealth(int amount);
};

class Monster : public Character {
private:
    bool active;

public:
    using Character::Character;
    void setActive(bool active);
    using Character::getHealth;
    using Character::setHealth;
};

class Hero : public Character {
private:
    int speed;
    int damage;

    int distance;

public:
    using Character::Character;
    Hero() noexcept;

    void setDamage(int value);
    void setDistance(int value);
    void setSpeed(int value);

    int getDamage() const;
    int getDistance() const;
    int getSpeed() const;

    void increaseDamage(int amount);
    void increaseProtection(int amount);
    void increaseDistance(int amount);

    Hero(int health, int damage, int protection, int distance);
    void diceResults(int firstRoll, int secondRoll, int thirdRoll);
    void restoreHealth();
    int move(int pos_X, int pos_Y, Field& gameField);
    void attack(Monster& target, Field& gameField);
};


#endif //OOP_LAB_CHARACTER_H
