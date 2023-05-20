#ifndef USABLE_HPP
#define USABLE_HPP
#include <string>
#include "../header/item.h"

class Usable : public Item {
    private:
        int statChanged;
    public:
        Usable();
        Usable(std::string, std::string, int, int);
        ~Usable();
        //void useItem(Player player);
};

#endif