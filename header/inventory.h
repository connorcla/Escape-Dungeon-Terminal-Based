#ifndef INVENTORY_HPP
#define INVENTORY_HPP
#include "item.h"
#include "weapon.h"
#include "equip.h"
#include "usable.h"
#include "player.h"
#include <string>
#include <vector>
#include <algorithm>

class Inventory {
    private:
        std::vector<Item*> items;
        std::vector<Item*> equipped;
        std::vector<Item*> weapon;
        int maxItems;
        static bool compareItems(Item*, Item*);
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
        void equipItem(int, Player&);
        std::string outputEquipped() const;
        void equipWeapon(int, Player&);
        std::string outputWeapon() const;
};

#endif