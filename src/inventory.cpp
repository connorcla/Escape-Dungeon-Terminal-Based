#include <string>
#include <vector>
#include "../header/inventory.h"
#include "../header/itemDatabase.h"
#include "../header/item.h"
#include "../header/weapon.h"
#include "../header/equip.h"
#include "../header/usable.h"
#include <string>
#include <vector>
#include <assert.h>

Inventory::Inventory() {
    this->maxItems = 30;
}

Inventory::~Inventory() {
    while(!items.empty()) {
        delete items.back();
        items.pop_back();
    }
}

void Inventory::sortItems() {
    
}

int Inventory::numItems() {
    return items.size();
}

void Inventory::addItem(std::string name, std::string des, std::string prop, std::string id) {
    int property = stoi(prop);
    int idNum = stoi(id);
    Item* returnItem = nullptr;
    if((idNum / 100) == 1)
    {
        returnItem = new Weapon(name, des, property, idNum);
    }
    else if((idNum / 100) == 2)
    {
        returnItem = new Equip(name, des, property, idNum);
    }
    else if((idNum / 100) == 3)
    {
        returnItem = new Usable(name, des, property, idNum);
    }
    items.push_back(returnItem);
}

void Inventory::removeItem(int index) {
    assert(index >= 0 && index <= (items.size()-1) && "Out of range: RemoveItem");
    assert(!items.empty() && "Out of range: RemoveItem");

    std::vector<Item*>::iterator it;
    it = items.begin();
    it = it + index;
    delete items.at(index);
    items.erase(it);
}

Item* Inventory::returnItem(int index) {
    assert(index >= 0 && index <= (items.size()-1) && "Out of range: ReturnItem");
    assert(!items.empty() && "Out of range: ReturnItem");

    return items.at(index);
}

std::string Inventory::listInventory() const {
    std::string returnString = "";
    int newLineCnt = 0;

    if(items.empty()) {
        return "There are no items in your inventory.";
    }

    for(unsigned int i = 0; i < items.size()-1; i++) {
        returnString = returnString + items.at(i)->getName();
        returnString = returnString + ",  ";
        if(newLineCnt > 3) {
            returnString = returnString + "\n";
            newLineCnt = -1;
        }
        newLineCnt++;
    }
    returnString = returnString + items.at(items.size()-1)->getName();

    return returnString;
}

std::string Inventory::displayItem(int selectedItem) const {
    assert(selectedItem >= 0 && selectedItem <= (items.size()-1) && "Out of range: DisplayItem");
    assert(!items.empty() && "Out of range: DisplayItem");

    std::string returnString = "";
    Item* item = items.at(selectedItem);

    if((item->getID() / 100) == 1)
    {
        returnString = returnString + "Weapon: ";
    }
    else if((item->getID() / 100) == 2)
    {
        returnString = returnString + "Equip: ";
    }
    else if((item->getID() / 100) == 3)
    {
        returnString = returnString + "Usable: ";
    }
    
    returnString = returnString + item->getName();
    returnString = returnString + " --- ";
    returnString = returnString + item->displayDescription();

    return returnString;
}