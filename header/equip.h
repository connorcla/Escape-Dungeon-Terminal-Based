#ifndef EQUIP_HPP
#define EQUIP_HPP
#include <string>
#include "../header/item.h"
#include "../header/player.h"

class Equip : public Item {
    private:
    public:
        Equip();
        Equip(std::string, std::string, int, int);
        ~Equip();
        virtual void incrStat(Player& player);
        virtual void decrStat(Player& player);
};

#endif