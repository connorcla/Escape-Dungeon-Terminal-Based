#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "item.h"

class Weapon : public Item { 
    private:       
    public:
        Weapon();
        Weapon(std::string, std::string, int, int);
        ~Weapon();
        virtual void incrStat(Player& player);
        virtual void decrStat(Player& player);
        //void dealDamage(Enemy* attacked);
};

#endif