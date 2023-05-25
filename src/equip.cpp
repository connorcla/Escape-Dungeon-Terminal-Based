#include <string>
#include "../header/item.h"
#include "../header/equip.h"

Equip::Equip() {
    this->name = "Default Equip";
    this->description = "default equip description";
    this->property = -1;
    this->id = -1;
    this->statChanged = -1;
    this->equipped = false;
}

Equip::Equip(std::string name, std::string description, int property, int id) {
    this->name = name;
    this->description = description;
    this->property = property;
    this->id = id;
    this->statChanged = 0; //Change to get statChanged form the id number, format with be decided later
    this->equipped = false;
}

Equip::~Equip() {

}

//void Equip::incrStat(Player player) {}
//void Equip::decrStat(Player player) {}

void Equip::equipItem() {
    this->equipped = true;
    //put in player vector of equipped items
}

void Equip::unequipItem() {
    this->equipped = false;
    //remove from player vector of equipped items
}