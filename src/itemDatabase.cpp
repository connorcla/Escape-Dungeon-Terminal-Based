#include <string>
#include <vector>
#include "../header/itemDatabase.h"

ItemDatabase::ItemDatabase() {
    allItems.push_back(singleItem("Health Potion I", "A simple red potion that restores some health.", "10", "0"));
    allItems.push_back(singleItem("Health Potion II", "A stronger red potion that restores health.", "25", "1"));
    allItems.push_back(singleItem("Health Potion III", "A superb red potion that restores a good portion of health.", "50", "2"));
    allItems.push_back(singleItem("Stone Sword", "A short blade made out of stone. It has worn down over time.", "10", "3"));
    allItems.push_back(singleItem("Basic Sword", "A short blade that you woke up with. Looks like it can get the job done.", "12", "4"));
    allItems.push_back(singleItem("Iron Sword", "A short blade made of cold iron. A little dull but can cut through a lot", "18", "5"));
    allItems.push_back(singleItem("Flame Blade", "A short blade with fiery runes engraved. It even gives off a little light.", "25", "6"));
}

ItemDatabase::~ItemDatabase() {}

int ItemDatabase::getSize() {
    return allItems.size();
}

std::string ItemDatabase::returnItem(int item, int returnProperty) {
    return allItems.at(item).at(returnProperty);
}

std::vector<std::string> ItemDatabase::singleItem(std::string name, std::string des, std::string prop, std::string id) {
    std::vector<std::string> returnVector;
    returnVector.push_back(name);
    returnVector.push_back(des);
    returnVector.push_back(prop);
    returnVector.push_back(id);
    return returnVector;
}
