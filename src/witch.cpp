#include "../header/witch.h"
#include <string>

Witch::Witch() {}

Witch::Witch(std::string enemyName, int expVal, int health, int attack,int def, int sp, int mag){
    magic = mag;
}

Witch::~Witch(){}

void Witch::action(){
    
}