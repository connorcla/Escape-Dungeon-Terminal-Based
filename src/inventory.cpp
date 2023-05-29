#include "../header/inventory.h"

Inventory::Inventory() {
    this->maxItems = 30;
}

Inventory::~Inventory() {
    while(!items.empty()) {
        delete items.back();
        items.pop_back();
    }
    while(!equipped.empty()) {
        delete equipped.back();
        equipped.pop_back();
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
    if(index < 0 || index > (items.size()-1)) {throw "Out of range: RemoveItem";}
    if(items.empty()) {throw "Out of range: RemoveItem";}

    std::vector<Item*>::iterator it;
    it = items.begin();
    it = it + index;
    delete items.at(index);
    items.erase(it);
}

Item* Inventory::returnItem(int index) {
    if(index < 0 || index > (items.size()-1)) {throw "Out of range: ReturnItem";}
    if(items.empty()) {throw "Out of range: ReturnItem";}

    return items.at(index);
}

std::string Inventory::listInventory() const {
    std::string returnString = "";
    int newLineCnt = 0;

    if(items.empty()) {
        return "There are no items in your inventory.";
    }

    for(unsigned int i = 0; i < items.size()-1; i++) {
        char index = i + 1 + 48;
        returnString = returnString + "(" + index + ")" + items.at(i)->getName();
        returnString = returnString + ",  ";
        if(newLineCnt > 3) {
            returnString = returnString + "\n";
            newLineCnt = -1;
        }
        newLineCnt++;
    }
    char lastIndex = items.size() + 48;
    returnString = returnString + "(" + lastIndex + ")" + items.at(items.size()-1)->getName();

    return returnString;
}

std::string Inventory::displayItem(int selectedItem) const {
    if(selectedItem < 0 || selectedItem > (items.size()-1)) {throw "Out of range: DisplayItem";}
    if(items.empty()) {throw "Out of range: DisplayItem";}

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

void Inventory::equipItem(int index, Player& player) {
    std::vector<Item*>::iterator it;
    if(equipped.size() == 3) {
        items.push_back(equipped.at(0));
        //Sort inventory again maybe
        equipped.at(0)->decrStat(player);
        it = equipped.begin();
        equipped.erase(it);
    }
    equipped.push_back(items.at(index));
    equipped.at(equipped.size()-1)->incrStat(player);
    it = items.begin();
    it = it + index;
    items.erase(it);
}

std::string Inventory::outputEquipped() const {
    std::string outputString = "";
    unsigned int numEquippedItems = 0;
    for(unsigned int i = 0; i < equipped.size(); i++) {
        outputString = outputString + "| " + equipped.at(i)->getName() + " |     ";
        numEquippedItems++;
    }
    for(unsigned int i = numEquippedItems; i < 3; i++) {
        char outputChar = numEquippedItems + 1 + 48;
        outputString = outputString + "| Empty Slot " + outputChar + " |     ";
        numEquippedItems++;
    }
    return outputString;
}