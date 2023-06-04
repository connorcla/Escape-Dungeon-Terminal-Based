#include "../header/golem.h"
#include <string>

Golem::Golem(std::string enemyName, int expVal, int health, int offense, int guard, int pace){
    name = enemyName;
    exp = expVal;
    curr_health = max_health = health;
    attack = offense;
    defense = guard;
    speed = pace;
}
Golem::~Golem() {}

std::string Golem::action(Player&){

}