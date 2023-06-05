#ifndef ENEMY_H
#define ENEMY_H
#include "entity.h"
#include "player.h"
#include <string>

class Enemy: public Entity{
    public:
        Enemy();
        ~Enemy();

       virtual std::string action(Player&)=0;
       bool operator<(Enemy&);
       void attackedByPlayer();

    protected:
        int numActions;
};
#endif