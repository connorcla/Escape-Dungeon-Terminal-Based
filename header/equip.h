#ifndef EQUIP_HPP
#define EQUIP_HPP
#include <string>
#include "../header/item.h"

class Equip : public Item {
    private:
        bool equipped;
        int statChanged;
    public:
        Equip();
        Equip(std::string, std::string, int, int);
        ~Equip();
        //void incrStat(Player player);
        //void decrStat(Player player);
        void equipItem();
        void unequipItem();
};

#endif