#ifndef WITCH_H
#define WITCH_H
#include "enemy.h"
#include <string>

class Witch: public Enemy{
    public:
        Witch();
        Witch(std::string,int,int,int,int,int,int);
        ~Witch();
        
        virtual void action();

    private:
        int magic;
};
#endif