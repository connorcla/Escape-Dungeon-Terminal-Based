#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <string>
#include "../header/item.h"

class Weapon : public Item {
    private:
        
    public:
        Weapon();
        Weapon(std::string, std::string, int, int);
        ~Weapon();
        //void dealDamage(Enemy* attacked);
};

#endif