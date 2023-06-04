#include "../header/witch.h"
#include <sstream>
#include <string>

Witch::Witch(std::string enemyName, int expVal, int health, int offense, int guard, int pace, int spells) {
    name = enemyName;
    exp = expVal;
    curr_health = max_health = health;
    attack = offense;
    defense = guard;
    speed = pace; 
    magic = spells;
    numActions = 4;
}

Witch::~Witch() {}

std::string Witch::action(Player& player) {
    int actionTaken = (rand() % numActions) + 1;
    int valueToUpdate = 0;
    int statToUpdate = 0;
    int variance = 0;
    
    std::string returnString = " ";
    std::ostringstream str1;
    std::string outputNum = "";

    switch(actionTaken) {
        case 1:
            variance = (rand() % 5) - 2;
            valueToUpdate = (-1 * magic) + variance;
            statToUpdate = 20;
            player.updateStat(statToUpdate, valueToUpdate);
            str1 << valueToUpdate;
            outputNum = str1.str();
            returnString = "The witch used a spell to decrease your attack by " + outputNum + " points.";
            break;
        case 2:
            variance = (rand() % 5) - 2;
            valueToUpdate = (-1 * magic) + variance;
            statToUpdate = 50;
            player.updateStat(statToUpdate, valueToUpdate);
            str1 << valueToUpdate;
            outputNum = str1.str();
            returnString = "The witch cast spell to decrease your magic capabilities by " + outputNum + " points.";
            break;
        case 3:
            variance = (rand() % 7) - 3;
            valueToUpdate = ((-1 * magic * 1.5) / (player.getMagic() / 10)) + variance;
            statToUpdate = 10;
            player.updateStat(statToUpdate, valueToUpdate);
            valueToUpdate = valueToUpdate * -1;
            str1 << valueToUpdate;
            outputNum = str1.str();
            returnString = "The witch cast fireball at you and dealt " + outputNum + " damage.";
            break;
        case 4:
            variance = (rand() % 7) - 3;
            valueToUpdate = ((-1 * magic * 2) / (player.getMagic() / 10)) + variance;
            statToUpdate = 10;
            player.updateStat(statToUpdate, valueToUpdate);
            valueToUpdate = valueToUpdate * -1;
            str1 << valueToUpdate;
            outputNum = str1.str();
            returnString = "The witch cast thunder wave to knock you back and dealt " + outputNum + " damage.";
            break;
        default:
            returnString = "An error occurred with a witch";
            break;
    }
    return returnString;
} 