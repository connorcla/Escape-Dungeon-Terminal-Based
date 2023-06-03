#ifndef ENEMY_H
#define ENEMY_H
#include "entity.h"
#include <string>

class Enemy: public Entity{
    public:
        Enemy();
        ~Enemy();
        virtual void action()=0;

    private:
        int numActions;
};
#endif