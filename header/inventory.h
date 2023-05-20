#ifndef INVENTORY_HPP
#define INVENTORY_HPP
#include <string>
#include <vector>
#include "../header/item.h"
#include "../header/equip.h"

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
        void addItem(Item*);
        void removeItem(Item*);
        std::string listInventory();
        std::string displayItem(int);        
};

#endif