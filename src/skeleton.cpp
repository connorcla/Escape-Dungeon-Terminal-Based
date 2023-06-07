#include "../header/skeleton.h"
#include <sstream>
#include <string>

Skeleton::Skeleton(std::string enemyName, int expVal, int health, int offense, int guard, int pace){
    name = enemyName;
    exp = expVal;
    curr_health = max_health = health;
    attack = offense;
    defense = guard;
    speed = pace;
    numActions = 5;
}

Skeleton::~Skeleton() {}

/*oid Skeleton::attackedByPlayer() {
    curr_health = curr_health - 5;
}*/

std::string Skeleton::action(Player& player){
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
            valueToUpdate = ((-1 * attack * 0.5) / ((player.getDefense() / 10) + 1)) + variance;
            statToUpdate = 10;
            player.updateStat(statToUpdate, valueToUpdate);
            valueToUpdate = valueToUpdate * -1;
            str1 << valueToUpdate;
            outputNum = str1.str();
            returnString = "The skeleton slashed at you with a blade dealing " + outputNum + " damage.";
            break;
        case 2:
            variance = (rand() % 7) - 3;
            valueToUpdate = ((-1 * attack * 0.75) / ((player.getDefense() / 10) + 1)) + variance;
            statToUpdate = 10;
            player.updateStat(statToUpdate, valueToUpdate);
            valueToUpdate = valueToUpdate * -1;
            str1 << valueToUpdate;
            outputNum = str1.str();
            returnString = "The skeleton took off one of its ribs and threw it at you dealing " + outputNum + " damage.";
            break;
        case 3:
            variance = (rand() % 5) - 2;
            valueToUpdate = ((-1 * attack) / ((player.getDefense() / 10) + 1)) + variance;
            statToUpdate = 10;
            player.updateStat(statToUpdate, valueToUpdate);
            valueToUpdate = valueToUpdate * -1;
            str1 << valueToUpdate;
            outputNum = str1.str();
            returnString = "The skeleton got close and tried to crush you with its entire rib cage to deal " + outputNum + " damage.";
            break;
        case 4:
            variance = (rand() % 5) - 2;
            valueToUpdate = (1 * attack * 0.25) + variance;
            this->attack += valueToUpdate;
            str1 << valueToUpdate;
            outputNum = str1.str();
            returnString = "The skeleton uses its bones to sharpen and enhance its blade, increasing its attack by " + outputNum + " points.";
            break;
        case 5:
            variance = (rand() % 9) - 4;
            valueToUpdate = (-1 * attack * 0.5) + variance;
            statToUpdate = 30;
            player.updateStat(statToUpdate, valueToUpdate);
            valueToUpdate = valueToUpdate * -1;
            str1 << valueToUpdate;
            outputNum = str1.str();
            returnString = "The skeleton threw down a small object with a flash, reducing your sight and defense by " + outputNum + " points.";
            break;
        default:
            returnString = "An error occurred with a skeleton.";
            break;
    }

    return returnString;
}