#include "../header/enemy.h"

Enemy::Enemy() {}

Enemy::~Enemy() {}


int Enemy::attackedByPlayer(int playerAttack) {
    if(this->curr_health != 0 && "ERROR! The function 'Witch::attackedByPlayer()' should not be called when enemy already dead.");
    int damage = (playerAttack * 0.5) - (this->defense / 4);
    if(damage < 1) {
        damage = 1;
    }
    this->curr_health -= damage;
    return damage;
}

bool Enemy::operator>(Enemy& other) {
    return this->speed > other.speed;
}

