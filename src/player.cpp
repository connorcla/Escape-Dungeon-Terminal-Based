#include "../header/player.h"

Player::Player() {
    this->max_health = 50;
    this->curr_health = 50;
    this->defense = 20;
    this->attack = 20;
    this->speed = 20;
    this->exp = 0;
    this->name = "default";
    this->max_magic = 50;
    this->curr_magic = 50;
}

Player::~Player() {

}

int Player::getMaxMagic() const {
    return max_magic;
}

int Player::getCurrMagic() const {
    return curr_magic;
}

void Player::setName(std::string name) {
    this->name = name;
}

void Player::updateStat(int idNum, int updatedValue) {
    int statToBeUpdated = (idNum / 10) % 10;
    switch(statToBeUpdated) {
        case 1:
            curr_health += updatedValue;
            break;
        case 2:
            attack += updatedValue;
            break;
        case 3:
            defense += updatedValue;
            break;
        case 4:
            speed += updatedValue;
            break;
        case 5:
            curr_magic += updatedValue;
            break;
    }
}