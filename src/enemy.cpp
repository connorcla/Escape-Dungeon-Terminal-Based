#include "../header/enemy.h"

Enemy::Enemy() {}

Enemy::~Enemy() {}


void Enemy::attackedByPlayer() {
    if(curr_health != 0 && "ERROR! The function 'Witch::attackedByPlayer()' should not be called when enemy already dead.");
    curr_health = curr_health - 5;
}

bool Enemy::operator>(Enemy& other) {
    return this->speed > other.speed;
}

