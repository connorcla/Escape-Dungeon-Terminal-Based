#include <string>
#include "../header/item.h"
#include "../header/weapon.h"

Weapon::Weapon() {
    this->name = "Default Weapon";
    this->description = "default weapon description";
    this->property = -1;
    this->id = -1;
}

Weapon::Weapon(std::string name, std::string description, int property, int id) {
    this->name = name;
    this->description = description;
    this->property = property;
    this->id = id;
}

Weapon::~Weapon() {

}

//void Weapon::dealDamage(Enemy* attacked) {}