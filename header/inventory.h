#ifndef INVENTORY_HPP
#define INVENTORY_HPP
#include "../header/inventory.h"
#include "../header/itemDatabase.h"
#include "../header/item.h"
#include "../header/weapon.h"
#include "../header/equip.h"
#include "../header/usable.h"
#include <string>
#include <vector>

class Inventory {
    private:
        std::vector<Item*> items;
        std::vector<Equip> equipped;
        int maxItems;
        void sortItems(); //Sort items by name
    public:
        Inventory();
        ~Inventory();
        int numItems();
        void addItem(std::string name, std::string des, std::string prop, std::string id);
        void removeItem(int);
        Item* returnItem(int);
        std::string listInventory() const;
        std::string displayItem(int) const;        
};

#endif