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

std::string Item::getName() {
    return this->name;
}

std::string Item::displayDescription() {
    return this->description;
}

int Item::getProperty() {
    return this->property;
}

int Item::getID() {
    return this->id;
}