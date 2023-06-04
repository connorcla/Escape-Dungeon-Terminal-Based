#include "../header/witch.h"
#include <string>

Witch::Witch(std::string enemyName, int expVal, int health, int offense, int guard, int pace, int spells) {
    name = enemyName;
    exp = expVal;
    curr_health = max_health = health;
    attack = offense;
    defense = guard;
    speed = pace; 
    magic = spells;
}

Witch::~Witch() {}

void Witch::action() {
    
}