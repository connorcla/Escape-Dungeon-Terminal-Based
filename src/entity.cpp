#include "entity.h"

// Constructor
Entity::Entity()
    : max_health(0), curr_health(0), defense(0), attack(0), speed(0) {}

// Getters and setters
int Entity::getMaxHealth() const {
    return max_health;
}
int Entity::getCurrHealth() const {
    return curr_health;
}
int Entity::getDefense() const {
    return defense;
}
int Entity::getAttack() const {
    return attack;
}
int Entity::getSpeed() const {
    return speed;
}
void Entity::setStats(int maxHealth, int currHealth, int defense, int attack, int speed) {
    this->max_health = maxHealth;
    this->curr_health = currHealth;
    this->defense = defense;
    this->attack = attack;
    this->speed = speed;
}
