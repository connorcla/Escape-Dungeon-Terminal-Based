#include "../header/boss.h"
#include <string>

Boss::Boss(std::string enemyName, int expVal, int health, int attack,int def, int sp, int mag){
    magic = mag;
}

Boss::~Boss(){}

void Boss::action(){
    
}