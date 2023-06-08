#include "../header/player.h"

Player::Player() {
    this->max_health = 50;
    this->curr_health = 50;
    this->defense = 20;
    this->attack = 20;
    this->speed = 20;
    this->exp = 0;
    this->name = "default";
    this->magic = 20;
}

Player::~Player() {

}

int Player::getMagic() const {
    return magic;
}

void Player::setMagic(int magic) {
    this->magic = magic;
}

void Player::gainExp(int exp) {
    this->exp += exp;
    if(this->exp < 0) {
        this->exp = 0;
    }
}

void Player::setName(std::string name) {
    this->name = name;
}

void Player::updateStat(int idNum, int updatedValue) {
    int statToBeUpdated = (idNum / 10) % 10;
    switch(statToBeUpdated) {
        case 1:
            curr_health += updatedValue;
            if(curr_health < 0) {
                curr_health = 0;
            }
            break;
        case 2:
            attack += updatedValue;
            if(attack < 1) {
                attack = 1;
            }
            break;
        case 3:
            defense += updatedValue;
            if(defense < 1) {
                defense = 1;
            }
            break;
        case 4:
            speed += updatedValue;
            if(speed < 1) {
                speed = 1;
            }
            break;
        case 5:
            magic += updatedValue;
            if(magic < 1) {
                magic = 1;
            }
            break;
        case 6:
            max_health += updatedValue;
    }
}