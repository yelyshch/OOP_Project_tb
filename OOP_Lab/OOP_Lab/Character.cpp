#include "Character.h"
#include "Field.h"

void Character::setProtection(int value) { protection = value; }
int Character::getProtection() const { return protection; }
void Character::increaseHealth(int amount) { setHealth(getHealth() + amount); }

void Character::setHealth(int value) { health = value; }
int Character::getHealth() const { return health; }

int Character::getX() const { return char_x; }
int Character::getY() const { return char_y; }
void Character::setX(int x) { char_x = x; }
void Character::setY(int y) { char_y = y; }


void Hero::setDamage(int value) { damage = value; }
void Hero::setDistance(int value) { distance = value; }
void Hero::setSpeed(int value) { speed = value; }

int Hero::getDamage() const { return damage; }
int Hero::getDistance() const { return distance; }
int Hero::getSpeed() const { return speed; }

Hero::Hero() noexcept
        : speed(maxValue),
          damage(startValue),
          distance(2),
          Character() {
    setHealth(maxValue);
    setProtection(startValue);
}

void Hero::increaseDamage(int amount) { setDamage(getDamage() + amount); }
void Hero::increaseProtection(int amount) { setProtection(getProtection() + amount); }
void Hero::increaseDistance(int amount) { setDistance(getDistance() + amount); }

void Hero::diceResults(int firstRoll, int secondRoll, int thirdRoll) {
    speed += firstRoll;
    setDamage(getDamage() + secondRoll);
    setProtection(getProtection() + thirdRoll);
}

int Hero::move(int pos_X, int pos_Y, Field& gameField){
    int new_x = getX() + pos_X;
    int new_y = getY() + pos_Y;
    if (gameField.freeCell(new_x, new_y)) {
        int deltaX = std::abs(new_x - getX());
        int deltaY = std::abs(new_y - getY()); // герой витрачає очки швидкості для пересування, якщо по діагоналі на одну то мінус 3, а так мінус 2

        int moveCost = 0;
        if (deltaX == deltaY){ // diagonal
            if (deltaX == 1 && deltaY == 1){
                moveCost = 3; // move 1 cell - 3 points
            }
            else{
                moveCost = 3 + (deltaX - 1); // move by more cells
            }
        }
        else { // straight movement
            moveCost = std::max(deltaX, deltaY) + 1;
        }

        if (speed >= moveCost) {
            setX(new_x);
            setY(new_y);
            speed -= moveCost;
        }
        return moveCost;
    }
}

void Hero::attack(Monster& target, Field& gameField) {
    int target_x = target.getX();
    int target_y = target.getY(); // де знаходиться монстр
    /* Щоб атакувати монстра, потрібно знаходитись в межах дистанції, для зменшення здоров'я монстра потрібно мати кількість очків атаки рівну його захисту. На початку гри дистанція гравця дорівнює двом,
     * що означає що він може атакувати лише по прямій на 1 клітинку, але протягом гри цей діапазон розширюється, включно з можливістю атакувати діагонально. */

    int moveCost = move(target_x - getX(), target_y - getY(), gameField);
    if (moveCost <= getDistance()) {

        int damageNeeded = target.getProtection();

        // Check if the hero has enough damage points to attack
        if (getDamage() >= damageNeeded) {

            int damageDealt = getDamage() - damageNeeded;
            target.setHealth(target.getHealth() - damageDealt); // reduce the monster's health

            if (target.getHealth() <= 0) { // monster is dead as hell
                target.setActive(false);
            }
        } else {
        }
    } else {
    }
}


void Hero::restoreHealth() { setHealth(maxValue); }

void Monster::setActive(bool active) { active = active; }