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
    while(!weapon.empty()) {
        delete weapon.back();
        weapon.pop_back();
    }
}

bool Inventory::compareItems(Item* item1, Item* item2) {
    return (*item1 < *item2);
}

void Inventory::sortItems() {
    std::sort(items.begin(), items.end(), compareItems);
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
    sortItems();
}

void Inventory::removeItem(int index) {
    if(index < 0 || index > (items.size()-1)) {throw "Out of range: RemoveItem";}
    if(items.empty()) {throw "Out of range: RemoveItem";}

    std::vector<Item*>::iterator it;
    it = items.begin();
    it = it + index;
    delete items.at(index);
    items.erase(it);
    sortItems();
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
        char index1 = (i/10) + 48;
        char index2 = (i%10) + 1 + 48;
        if(index2 == ':') {
            index2 = '0';
            index1++;
        }
        std::string sIndex1;
        sIndex1.push_back(index1);
        if(sIndex1 == "0") {
            sIndex1 = "";
        }
        returnString = returnString + "(" + sIndex1 + index2 + ")" + items.at(i)->getName();
        returnString = returnString + ",  ";
        if(newLineCnt > 3) {
            returnString = returnString + "\n";
            newLineCnt = -1;
        }
        newLineCnt++;
    }
    char index1 = (items.size()/10) + 48;
    char index2 = (items.size()%10) + 48;
    std::string sIndex1;
    sIndex1.push_back(index1);
    if(sIndex1 == "0") {
        sIndex1 = "";
    }
    returnString = returnString + "(" + sIndex1 + index2 + ")" + items.at(items.size()-1)->getName();

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
    if(equipped.size() == 5) {
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
    sortItems();
}

std::string Inventory::outputEquipped() const {
    std::string outputString = "";
    unsigned int numEquippedItems = 0;
    for(unsigned int i = 0; i < equipped.size(); i++) {
        outputString = outputString + "| " + equipped.at(i)->getName() + " |     ";
        numEquippedItems++;
    }
    for(unsigned int i = numEquippedItems; i < 5; i++) {
        char outputChar = numEquippedItems + 1 + 48;
        outputString = outputString + "| Empty Slot " + outputChar + " |     ";
        numEquippedItems++;
    }
    return outputString;
}

void Inventory::equipWeapon(int index, Player& player) {
    std::vector<Item*>::iterator it;
    if(weapon.size() == 1) {
        items.push_back(weapon.at(0));
        //Sort inventory again maybe
        weapon.at(0)->decrStat(player);
        it = weapon.begin();
        weapon.erase(it);
    }
    weapon.push_back(items.at(index));
    weapon.at(weapon.size()-1)->incrStat(player);
    it = items.begin();
    it = it + index;
    items.erase(it);
    sortItems();
}

std::string Inventory::outputWeapon() const {
    std::string outputString = "";
    if(weapon.size() == 0) {
        outputString = outputString + "| Empty Weapon Slot |";
    }
    else {
        outputString = outputString + "| " + weapon.at(0)->getName() + " |";
    }
    return outputString;
}