#ifndef BOSS_H
#define BOSS_H
#include "enemy.h"
#include <string>

class Boss: public Enemy{
    public:
        Boss(std::string,int,int,int,int,int,int);
        ~Boss();
        
        virtual void action();

    private:
        int magic;
};
#endif