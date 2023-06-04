#include "../header/skeleton.h"
#include <string>

Skeleton::Skeleton(std::string enemyName, int expVal, int health, int offense, int guard, int pace){
    name = enemyName;
    exp = expVal;
    curr_health = max_health = health;
    attack = offense;
    defense = guard;
    speed = pace;
}

Skeleton::~Skeleton() {}

std::string Skeleton::action(Player&){
    
}