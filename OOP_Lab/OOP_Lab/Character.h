#pragma once
#ifndef OOP_LAB_CHARACTER_H
#define OOP_LAB_CHARACTER_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>

class Manager;
class Monster;

const int maxValue = 6;
const int startValue = 1;

class Field;

class Character {
private:
    int char_x, char_y;
    int health;
    int protection;
    int damage;
    int speed;

public:
    int getDamage() const;
    int getSpeed() const;
    void reduceHealth(int amount);
    int getHealth() const;
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);

    void setHealth(int value);
    void setDamage(int value);
    void setProtection(int value);
    void setSpeed(int value);
    int getProtection() const;
    void increaseHealth(int amount);

    void increaseDamage(int amount);
    void increaseProtection(int amount);
};

class Hero : public Character {
private:
    int distance;

public:
    using Character::Character;
    using Character::getHealth;
    using Character::reduceHealth;
    Hero() noexcept;

    void setDistance(int value);
    int getDistance() const;

    void increaseDistance(int amount);
    void restoreHealth();
    int move(int pos_X, int pos_Y, Field* gameField);
    void attack(Monster& target, Field* gameField);

    void diceResults();
};

class Monster : public Character {
private:
    bool active{};

public:

    using MonsterContainer = std::array<Monster, 5>;
    using Character::Character;
    Monster() noexcept;

    void setActive(bool active);
    bool isActive() const;
    using Character::getHealth;
    using Character::getDamage;
    using Character::setHealth;
    using Character::reduceHealth;

    static void calculateMonsterAttack(Hero &hero, MonsterContainer &monsters);
};

#endif // OOP_LAB_CHARACTER_H