#include "../header/spider.h"
#include <sstream>
#include <string>

Spider::Spider(std::string enemyName, int expVal, int health, int offense, int guard, int pace) {
    name = enemyName;
    exp = expVal;
    curr_health = max_health = health;
    attack = offense;
    defense = guard;
    speed = pace;
    numActions = 3;
}

Spider::~Spider() {}

std::string Spider::action(Player& player){
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
            valueToUpdate = ((-1 * attack) / ((player.getDefense() / 10) + 1)) + variance;
            statToUpdate = 10;
            player.updateStat(statToUpdate, valueToUpdate);
            valueToUpdate = valueToUpdate * -1;
            str1 << valueToUpdate;
            outputNum = str1.str();
            returnString = "The spider tried to slash at you and dealt " + outputNum + " damage.";
            break;
        case 2:
            variance = (rand() % 7) - 3;
            valueToUpdate = ((-1 * attack * 1.5) / ((player.getDefense() / 10) + 1)) + variance;
            statToUpdate = 10;
            player.updateStat(statToUpdate, valueToUpdate);
            valueToUpdate = valueToUpdate * -1;
            str1 << valueToUpdate;
            outputNum = str1.str();
            returnString = "The spider tried to bite you and dealt " + outputNum + " damage.";
            break;
        case 3:
            variance = (rand() % 5) - 2;
            valueToUpdate = (-1 * attack * 0.5) + variance;
            statToUpdate = 40;
            player.updateStat(statToUpdate, valueToUpdate);
            valueToUpdate = valueToUpdate * -1;
            str1 << valueToUpdate;
            outputNum = str1.str();
            returnString = "The spider shot webs at you in attempt to slow you down and decreased speed by " + outputNum + " points.";
            break;
        default:
            returnString = "An error occurred with a spider.";
            break;
    }

    return returnString;
}