#ifndef ENEMY_H
#define ENEMY_H
#include "entity.h"
#include "player.h"
#include <string>

class Enemy: public Entity{
    public:
        Enemy();
        virtual ~Enemy();

       virtual std::string action(Player&)=0;
       int attackedByPlayer(int);
       bool operator>(Enemy&);

    protected:
        int numActions;
};
#endif