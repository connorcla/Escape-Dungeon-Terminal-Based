#include <string>
#include "../header/item.h"
#include "../header/usable.h"

Usable::Usable() {
    this->name = "Default Usable";
    this->description = "default usable description";
    this->property = -1;
    this->id = -1;
    this->statChanged = -1;
}

Usable::Usable(std::string name, std::string description, int property, int id) {
    this->name = name;
    this->description = description;
    this->property = property;
    this->id = id;
    this->statChanged = 0; //Change to get statChanged form the id number, format with be decided later
}

Usable::~Usable() {

}

void Usable::incrStat(Player& player) {
    player.updateStat(id, property);
}

void Usable::decrStat(Player& player) {
    player.updateStat(id, -1 * property);
}

//void Usable::useItem(Player player) {}