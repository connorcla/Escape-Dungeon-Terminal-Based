#ifndef ITEM_HPP
#define ITEM_HPP

#include "player.h"
#include <string>

class Item {
    protected:
        std::string name;
        std::string description;
        int property;
        int id;
    public:
        Item();
        Item(std::string, std::string, int, int);
        virtual ~Item();
        std::string getName() const;
        std::string displayDescription() const;
        int getProperty() const;
        int getID() const;
        virtual void incrStat(Player& player);
        virtual void decrStat(Player& player);
        bool operator<(Item&);
};

#endif