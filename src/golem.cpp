#include "../header/golem.h"
#include <sstream>
#include <string>

Golem::Golem(std::string enemyName, int expVal, int health, int offense, int guard, int pace){
    name = enemyName;
    exp = expVal;
    curr_health = max_health = health;
    attack = offense;
    defense = guard;
    speed = pace;
    numActions = 3;
}
Golem::~Golem() {}

std::string Golem::action(Player& player){
    int actionTaken = (rand() % numActions) + 1;
    int valueToUpdate = 0;
    int statToUpdate = 0;
    int variance = 0;

    std::string returnString = "";
    std::ostringstream str1;
    std::string outputNum = "";

    switch(actionTaken) {
        case 1:
            variance = (rand() % 7) - 3;
            valueToUpdate = ((-1 * attack) / (player.getDefense() / 10)) + variance;
            statToUpdate = 10;
            player.updateStat(statToUpdate, valueToUpdate);
            valueToUpdate = valueToUpdate * -1;
            str1 << valueToUpdate;
            outputNum = str1.str();
            returnString = "The golem threw a large rock at you and dealt " + outputNum + " damage.";
            break;
        case 2:
            variance = (rand() % 7) - 3;
            valueToUpdate = ((-1 * attack * 1.5) / (player.getDefense() / 10)) + variance;
            statToUpdate = 10;
            player.updateStat(statToUpdate, valueToUpdate);
            valueToUpdate = valueToUpdate * -1;
            str1 << valueToUpdate;
            outputNum = str1.str();
            returnString = "The golem punched with its stone arm dealing " + outputNum + " damage.";
            break;
        case 3:
            variance = (rand() % 5) - 2;
            valueToUpdate = (1 * defense) + variance;
            this->defense += valueToUpdate;
            str1 << valueToUpdate;
            outputNum = str1.str();
            returnString = "The golem stuck itself into the ground, heightening its defense by " + outputNum + " points.";
            break;
        default:
            returnString = "An error occurred with a skeleton.";
            break;
    }

    return returnString;
}