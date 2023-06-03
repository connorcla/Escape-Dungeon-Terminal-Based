#ifndef SKELETON_H
#define SKELETON_H
#include "enemy.h"
#include <string>

class Skeleton:public Enemy{
    public:
        Skeleton(std::string,int,int,int,int,int);
        ~Skeleton();
        
        virtual void action();

    private:
};
#endif