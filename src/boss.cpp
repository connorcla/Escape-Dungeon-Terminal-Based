#include "../header/boss.h"
#include <sstream>
#include <string>

Boss::Boss(std::string enemyName, int expVal, int health, int offense, int guard, int pace, int mag){
    name = enemyName;
    exp = expVal;
    curr_health = max_health = health;
    attack = offense;
    defense = guard;
    speed = pace;
    magic = mag;
    numActions = 5;
}

Boss::~Boss(){}

/*void Boss::attackedByPlayer() {
    curr_health = curr_health - 5;
}*/

std::string Boss::action(Player& player){
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
            valueToUpdate = ((-1 * magic) / ((player.getMagic() / 10) + 1)) + variance;
            statToUpdate = 10;
            player.updateStat(statToUpdate, valueToUpdate);
            valueToUpdate = valueToUpdate * -1;
            str1 << valueToUpdate;
            outputNum = str1.str();
            returnString = "The dark lord waves his hand at you as a dark pulse emits from it dealing " + outputNum + " damage.";
            break;
        case 2:
            variance = (rand() % 7) - 3;
            valueToUpdate = ((-1 * attack * 1.5) / ((player.getDefense() / 10) + 1)) + variance;
            statToUpdate = 10;
            player.updateStat(statToUpdate, valueToUpdate);
            valueToUpdate = valueToUpdate * -1;
            str1 << valueToUpdate;
            outputNum = str1.str();
            returnString = "The dark lord lunges at you with his black blade. He slashes you and deals " + outputNum + " damage.";
            break;
        case 3:
            variance = (rand() % 7) - 3;
            valueToUpdate = ((-1 * magic * 2) / ((player.getDefense() / 10) + 1)) + variance;
            statToUpdate = 10;
            player.updateStat(statToUpdate, valueToUpdate);
            valueToUpdate = valueToUpdate * -1;
            str1 << valueToUpdate;
            outputNum = str1.str();
            returnString = "The dark lord raises a fist and smashes into the ground sending dark waves around you dealing " + outputNum + " damage.";
            break;
        case 4:
            variance = (rand() % 13) - 6;
            valueToUpdate = (1 * magic * 2) + variance;
            this->attack += valueToUpdate;
            str1 << valueToUpdate;
            outputNum = str1.str();
            returnString = "The dark lord harnessed his power within him in order to raise his attack by " + outputNum + " points.";
            break;
        case 5:
            variance = (rand() % 13) - 6;
            valueToUpdate = (-1 * magic * 0.5) + variance;
            statToUpdate = 30;
            player.updateStat(statToUpdate, valueToUpdate);
            valueToUpdate = valueToUpdate * -1;
            str1 << valueToUpdate;
            outputNum = str1.str();
            returnString = "The dark lord's magic focuses on you, lowering your defenses by " + outputNum + " points.";
            break;
        default:
            returnString = "An error occurred with a skeleton.";
            break;
    }
    return returnString;
}

std::string Boss::displayDialogue() {
    int dialogueChosen = (rand() % numActions) + 1;
    std::string returnString = "";
    switch(dialogueChosen) {
        case 1:
            returnString = "1st Option";
            break;
        case 2:
            returnString = "2nd Option";
            break;
        case 3:
            returnString = "3rd Option";
            break;
        case 4:
            returnString = "4th Option";
            break;
        case 5:
            returnString = "5th Option";
            break;
    }
    return returnString;
}