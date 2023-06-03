#include "../header/spider.h"
#include <string>

Spider::Spider(std::string enemyName, int expVal, int health, int offense, int guard, int pace) {
    name = enemyName;
    exp = expVal;
    curr_health = max_health = health;
    attack = offense;
    defense = guard;
    speed = pace;
}

Spider::~Spider() {}

void Spider::action() {

}