#include "Character.h"

void Character::setHealth(int value) { health = value; }
void Character::setDamage(int value) { damage = value; }
void Character::setProtection(int value) { protection = value; }
void Character::setDistance(int value) { distance = value; }

int Character::getHealth() const { return health; }
int Character::getDamage() const { return damage; }
int Character::getProtection() const { return protection; }
int Character::getDistance() const { return distance; }

Character::Character(int health, int damage, int protection, int distance)
        : health(health), damage(damage), protection(protection), distance(distance) {}

void Character::increaseHealth(int amount) { setHealth(getHealth() + amount); }
void Character::increaseDamage(int amount) { setDamage(getDamage() + amount); }
void Character::increaseProtection(int amount) { setProtection(getProtection() + amount); }
void Character::increaseDistance(int amount) { setDistance(getDistance() + amount); }

void Hero::diceResults(int firstRoll, int secondRoll, int thirdRoll) {
    speed += firstRoll;
    setDamage(getDamage() + secondRoll);
    setProtection(getProtection() + thirdRoll);
}

void Hero::restoreHealth() { setHealth(maxValue); }

void Monster::setActive(bool active) { active = active; }