#include <string>
#include <vector>
#include "../header/itemDatabase.h"

ItemDatabase::ItemDatabase() {
    //Weapons
    allItems.push_back(singleItem("Basic Sword", "A short blade that you woke up with. Looks like it can get the job done. --- Damage: 12", "12", "100"));
    allItems.push_back(singleItem("Stone Sword", "A short blade made out of stone. It has worn down over time. --- Damage: 10", "10", "101"));
    allItems.push_back(singleItem("Iron Sword", "A short blade made of cold iron. A little dull but can cut through a lot. --- Damage: 18", "18", "102"));
    allItems.push_back(singleItem("Flame Blade", "A short blade with fiery runes engraved. It even gives off a little light. --- Damage: 25", "25", "103"));

    //Equips
    allItems.push_back(singleItem("Leather Armor", "Some thick armor made out of rough leather. --- Defense: +5", "5", "230"));
    allItems.push_back(singleItem("Iron Chainmail", "Light chains that can protect from weaker blows. --- Defense: +10", "10", "231"));
    allItems.push_back(singleItem("Iron Plating", "Heavy plating made of iron. It weighs you down but not a lot with get through. --- Defense: +18", "18", "232"));
    allItems.push_back(singleItem("Basic Shield", "A medium round shield that can block incoming attacks. --- Defense: +8", "8", "233"));
    allItems.push_back(singleItem("Pegasus Boots", "With these boots, you feel extremely light on your feet. --- Speed: +10", "10", "240"));

    //Usables
    allItems.push_back(singleItem("Health Potion I", "A simple red potion that restores some health. --- Heal: 10", "10", "310"));
    allItems.push_back(singleItem("Health Potion II", "A stronger red potion that restores health. --- Heal: 25", "25", "311"));
    allItems.push_back(singleItem("Health Potion III", "A superb red potion that restores a good portion of health. --- Heal: 50", "50", "312"));
    allItems.push_back(singleItem("Magic Potion I", "A simple green potion that restores some magic. --- Magic: 10", "10", "350"));
    allItems.push_back(singleItem("Magic Potion II", "A stronger green potion that restores magic. --- Magic: 25", "25", "351"));
    allItems.push_back(singleItem("Magic Potion III", "A superb green potion that restores a good portion of magic. --- Magic: 50", "50", "352"));
}

ItemDatabase::~ItemDatabase() {}

int ItemDatabase::getSize() const {
    return allItems.size();
}

std::string ItemDatabase::returnItem(int item, int returnProperty) const {
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
