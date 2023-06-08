#include <string>
#include "../header/item.h"
#include "../header/equip.h"


Equip::Equip(std::string name, std::string description, int property, int id) {
    this->name = name;
    this->description = description;
    this->property = property;
    this->id = id;
}

Equip::~Equip() {

}

void Equip::incrStat(Player& player) {
    player.updateStat(id, property);
}

void Equip::decrStat(Player& player) {
    player.updateStat(id, -1 * property);
}