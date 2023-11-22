#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <windows.h>
#include "Manager.h"

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