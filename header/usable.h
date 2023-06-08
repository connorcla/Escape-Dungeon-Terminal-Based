#ifndef USABLE_HPP
#define USABLE_HPP
#include <string>
#include "item.h"
#include "player.h"

class Usable : public Item {
    private:
        int statChanged;
    public:
        Usable(std::string, std::string, int, int);
        ~Usable();
        virtual void incrStat(Player& player);
        virtual void decrStat(Player& player);
};

#endif