#include <string>
#include "../header/item.h"

Item::Item() {
    this->name = "Default";
    this->description = "default description";
    this->property = -1;
    this->id = -1;
}

Item::Item(std::string name, std::string description, int property, int id) {
    this->name = name;
    this->description = description;
    this->property = property;
    this->id = id;
}

Item::~Item() {

}

std::string Item::getName() const {
    return this->name;
}

std::string Item::displayDescription() const {
    return this->description;
}

int Item::getProperty() const {
    return this->property;
}

int Item::getID() const {
    return this->id;
}

bool Item::operator<(Item& other) {
    return this->name < other.name;
}

void Item::incrStat(Player& player) {
    player.updateStat(id, property);
}

void Item::decrStat(Player& player) {
    player.updateStat(id, -1 * property);
}