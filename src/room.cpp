#include "../header/room.h"
#include "../header/witch.h"
#include "../header/spider.h"
#include "../header/golem.h"
#include "../header/skeleton.h"
#include "../header/boss.h"
#include <vector>
#include <assert.h>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

Room::Room() {}

Room::Room(int roomIndex) {
    assert(roomIndex >= 0 && "ERROR! 'roomIndex' cannot be a negative value in Room::Room().");
    generateEnemies(roomIndex);
    generateItems(roomIndex);
    sortEnemies();
}

Room::~Room(){}

void Room::deleteEnemies() {
    while(!enemies.empty()) {
        delete enemies.back();
        enemies.pop_back();
        enemyQuantity--;
    }
}

void Room::generateEnemies(int roomIndex) {
    assert(roomIndex >= 0 && "ERROR! 'roomIndex' cannot be less than zero in Room::generateEnemies().");
    int room = roomIndex + 1;
    const int lastRoom = 10;

    if(room != lastRoom){
        enemyQuantity = getRandomNumber(room);
        setEnemiesBeforeLastRoom(enemyQuantity, room);
        
    } 
    else{
        enemyQuantity = 1;
        int bossValue = 5;
        Enemy* boss = getEnemy(bossValue, room);
        enemies.push_back(boss);
    }
}

void Room::setEnemiesBeforeLastRoom(const int numOfEnemies, int roomIndex) {
    assert(numOfEnemies > 0 && "ERROR! 'numOfEnemies' value cannot be less than 0 in Room::setEnemiesBeforeLastRoom().");
    unsigned int randomEnemy;
    
    for(int enemy = 0; enemy < numOfEnemies; enemy++){
        randomEnemy = getRandomNumber(enemy+1);//This number should be different than enemyQuantity's number.
        
        Enemy* villan = getEnemy(randomEnemy, roomIndex);
        enemies.push_back(villan);  
    }
}

int Room::getRandomNumber(int counter) const {
    int randomNumber = rand();
    randomNumber = ((randomNumber/counter) % 4) + 1;
    return randomNumber;//This should return a number between 1 to 4.
}

void Room::setRmStatus(string status) {
    rmStatus = status;
    assert(rmStatus != " " && "ERROR! The 'status' parameter in Room::setRmStatus() not correctly setting room status.");
}

bool Room::compareEnemies(Enemy* enemy1, Enemy* enemy2) {
    return (*enemy1 > *enemy2);
}

void Room::sortEnemies() {
    assert(enemies.empty() == false && "ERROR! Cannot sort enemies with an empty Enemy vector in Room::sortEnemies().");
    std::sort(enemies.begin(), enemies.end(), compareEnemies);
}

void Room::startBattle(Player& player, int enemyIndex) {
    if(enemyIndex < 0 || enemyIndex > 4){ throw "ERROR! 'enemyIndex' cannot be out of limit bounds 0 & 4 in Room::startBattle()."; }
    
    if(player.getSpeed() > enemies[enemyIndex]->getSpeed()){
        //Player attacks first!
        enemies[enemyIndex]->attackedByPlayer();
        int enemyDamage = enemies[enemyIndex]->getCurrHealth();
        
        assert(enemyDamage >= 0 && "ERROR! 'enemyDamage' cannot be less than 0 in Room::startBattle()." );
        
        if(enemyDamage == 0){
            enemyQuantity--;
            assert(enemyQuantity >= 0 && "ERROR! 'enemyQuantity' cannot be less than 0 in Room::startBattle().");
            removeEnemy(enemyIndex);
            //player has killed the enemy.
        }
    }
    else{
        //Enemy attacks first!
        enemies[enemyIndex]->action(player);
        
    }
}

void Room::removeEnemy(const int enemyIndex){
    assert(enemyIndex >= 0 && enemyIndex < 5 && "ERROR! 'enemyIndex' cannot be out of limit bounds 0 & 4 in Room::startBattle().");
    
    std::vector<Enemy*>::iterator it;
    it = enemies.begin();
    it = it + enemyIndex;
    delete enemies.at(enemyIndex);
    enemies.erase(it);
    sortEnemies();
}

vector<string> Room::itemBattle(Inventory& inventory, Player& player, int numValue) {
    vector<string> turnOutputs;
    string returnString = "";
    bool playerTurnDone = false;
    
    for(unsigned int i = 0; i < enemies.size(); i++) {
        if(enemies.at(i)->getSpeed() > player.getSpeed() || playerTurnDone == true) {
            turnOutputs.push_back(enemies.at(i)->action(player));
            if(i == enemies.size() - 1 && playerTurnDone == false) {
                playerTurnDone = true;
                goto playerLast;
            }
        }
        else {
            playerLast:
            if(inventory.returnItem(numValue)->getID() / 100 == 3) {
                int value = inventory.returnItem(numValue)->getProperty();
                int outputValue = value;
                std::string name = inventory.returnItem(numValue)->getName();
                switch((inventory.returnItem(numValue)->getID() / 10) % 10) {
                    case 1:
                        if((player.getCurrHealth() + value) > player.getMaxHealth()) {
                            outputValue = player.getMaxHealth() - player.getCurrHealth();
                            player.setStats(player.getMaxHealth(), player.getMaxHealth()-value, player.getDefense(), player.getAttack(), player.getSpeed(), player.getExp(), player.getName());
                        }
                        returnString = "You used " + name + " and increased your health by " + to_string(outputValue) + " points.";
                        break;
                    case 2:
                        returnString = "You used " + name + " and increased your attack by " + to_string(value) + " points.";
                        break;
                    case 3:
                        returnString = "You used " + name + " and increased your defense by " + to_string(value) + " points.";
                        break;
                    case 4:
                        returnString = "You used " + name + " and increased your defense by " + to_string(value) + " points.";
                        break;
                    case 5:
                        returnString = "You used " + name + " and increased your defense by " + to_string(value) + " points.";
                        break;
                }
                inventory.returnItem(numValue)->incrStat(player);
                inventory.removeItem(numValue);
            }
            else {
                returnString = "You tried to use an item that can't be used here! Fumbling in your bag created an opportunity for the enemies to attack!"; 
            }
            turnOutputs.push_back(returnString);
            if(playerTurnDone == false) {
                i--;
                playerTurnDone = true;
            }
        }
    }
    return turnOutputs;
}

Enemy* Room::getEnemy(int randEnemy, int indexScaler) {
    Enemy* enemy = nullptr;
    int variance = (indexScaler-1) * 5;
    //unsigned int defaultExp, defaultHealth, defaultAttack, defaultDefense, defaultSpeed, defaultMagic; 
    
    switch(randEnemy){
            case 1:{ 
                enemy = new Witch("Witch",10+variance,10+variance,5+variance,8+variance,6+variance,8+variance); 
                break;
                }
            case 2:{ 
                enemy = new Spider("Spider",10+variance,10+variance,8+variance,5+variance,10+variance);
                break;
            }
            case 3:{ 
                enemy = new Golem("Golem",10+variance,15+variance,5+variance,12+variance,5+variance);
                break;
            }
            case 4:{ 
                enemy = new Skeleton("Skeleton",10+variance,8+variance,10+variance,10+variance,8+variance);
                break;
            }
            case 5:{
                enemy = new Boss("Boss",100,100,50,50,50,15);
                break;
            }
            default: break;
        }

    return enemy;
}

string Room::getEnemyName(const int enemyIndex) const {
    string enemyName = " ";

    if(enemyQuantity != 0){
        enemyName = enemies[enemyIndex]->getName();
    }
    return enemyName;
}

int Room::getEnemySpeed(const int enemyIndex) const {
    return enemies.at(enemyIndex)->getSpeed();
}

void Room::setRoomInfo(string info) {
    rmInfo = info;
}

string Room::getRoomInfo() {
    return rmInfo;
}

string Room::getRmStatus() {
    return rmStatus;
}

unsigned int Room::getNumOfEnemies() const {
    return enemyQuantity;
}

unsigned int Room::getEnemyCURRNTHealth(const int enemyIndex) const {
    int currntHealth = 0;

    if(enemyQuantity != 0){
        currntHealth = enemies[enemyIndex]->getCurrHealth();
    }

    return currntHealth;
}

unsigned int Room::getEnemyMAXHealth(const int enemyIndex) const {
    int maxHealth = 0;

    if(enemyQuantity != 0){
        maxHealth = enemies[enemyIndex]->getMaxHealth();
    }

    return maxHealth;
}

void Room::generateItems(int randomQuantity) {
    ItemDatabase allitems;
    
    int numItemsGenerated = ((rand() % (randomQuantity+1) * 2)) + 1;
    
    for(int i = 0; i < numItemsGenerated; i++) {
        int itemGenerated = (rand() % allitems.getSize());
        items.push_back(allitems.returnSingleItem(itemGenerated));
    }
}

vector<string> Room::getItem() {
    vector<string> returnVector;
    if(!items.empty()){
    returnVector = items.back();
    items.pop_back();
    }
    else {
        returnVector.push_back(" ");
    }
    return returnVector;
}