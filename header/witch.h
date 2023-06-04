#ifndef WITCH_H
#define WITCH_H
#include "enemy.h"
#include <string>

class Witch: public Enemy{
    public:
        Witch(std::string,int,int,int,int,int,int);
        ~Witch();
        
        virtual std::string action(Player&);

    private:
        int magic;
};
#endif