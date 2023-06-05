#include "../header/enemy.h"

Enemy::Enemy() {}

Enemy::~Enemy() {}

bool Enemy::operator<(Enemy& other) {
    return this->speed < other.speed;
}

void Enemy::attackedByPlayer() {
    if(curr_health != 0 && "ERROR! The function 'Witch::attackedByPlayer()' should not be called when enemy already dead.");
    curr_health = curr_health - 5;
}
