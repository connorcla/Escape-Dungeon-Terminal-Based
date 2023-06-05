#include "../header/enemy.h"

Enemy::Enemy() {}

Enemy::~Enemy() {}

bool Enemy::operator<(Enemy& other) {
    return this->speed < other.speed;
}