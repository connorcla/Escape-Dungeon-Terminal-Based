#ifndef SPIDER_H
#define SPIDER_H
#include "enemy.h"
#include <string>

class Spider:public Enemy{
    public:
        Spider();
        Spider(std::string,int,int,int,int,int);
        ~Spider();
        
        virtual void action();

    private:
};
#endif