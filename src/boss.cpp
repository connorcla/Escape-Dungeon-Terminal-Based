#include "../header/boss.h"
#include <string>

Boss::Boss(std::string enemyName, int expVal, int health, int offense, int guard, int pace, int mag){
    name = enemyName;
    exp = expVal;
    curr_health = max_health = health;
    attack = offense;
    defense = guard;
    speed = pace;
    magic = mag;
}

Boss::~Boss(){}

std::string Boss::action(Player&){
    
}