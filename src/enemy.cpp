#include "../header/enemy.h"

Enemy::Enemy() {}

Enemy::~Enemy() {}

bool Enemy::operator<(Enemy& other) {
    return this->speed < other.speed;
}

void Enemy::attackedByPlayer(){
    this->curr_health = (this->curr_health - 5);
}