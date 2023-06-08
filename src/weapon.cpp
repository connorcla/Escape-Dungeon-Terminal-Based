#include <string>
#include "../header/weapon.h"

Weapon::Weapon(std::string name, std::string description, int property, int id) {
    this->name = name;
    this->description = description;
    this->property = property;
    this->id = id;
}

Weapon::~Weapon() {

}

void Weapon::incrStat(Player& player) {
    player.updateStat(id, property);
}

void Weapon::decrStat(Player& player) {
    player.updateStat(id, -1 * property);
}

//void Weapon::dealDamage(Enemy* attacked) {}