#ifndef GOLEM_H
#define GOLEM_H
#include "enemy.h"
#include <string>

class Golem:public Enemy{
    public:
        Golem(std::string,int,int,int,int,int);
        ~Golem();
        
//        virtual void attackedByPlayer();
        virtual std::string action(Player&);

    private:
};
#endif