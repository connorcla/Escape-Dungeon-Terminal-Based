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

#include <iostream>//DELTE THIS

using namespace std;

Room::Room() {}

Room::Room(int roomIndex) {
    assert(roomIndex >= 0 && "ERROR! 'roomIndex' cannot be a negative value in Room::Room().");
    generateEnemies(roomIndex);
    generateItems(roomIndex);
}

Room::~Room(){
    //delete vector<Enemy> enemies
    //vector<Enemy>::iterator it = enemies.begin();
}

void Room::generateEnemies(int roomIndex) {
    assert(roomIndex >= 0 && "ERROR! 'roomIndex' cannot be less than zero in Room::generateEnemies().");
    int room = roomIndex + 1;
    const int lastRoom = 10;
    int enemyQuantity;

    if(room != lastRoom){
        enemyQuantity = getRandomNumber(room);
        setEnemiesBeforeLastRoom(enemyQuantity);
        
    } 
    else{
        int bossValue = 5;
        Enemy* boss = getEnemy(bossValue);
        enemies.push_back(boss);
    }
}

void Room::setEnemiesBeforeLastRoom(const int numOfEnemies){
    assert(numOfEnemies > 0 && "ERROR! 'numOfEnemies' value cannot be less than 0 in Room::setEnemiesBeforeLastRoom().");
    unsigned int randomEnemy;
    
    for(int enemy = 0; enemy < numOfEnemies; enemy++){
        randomEnemy = getRandomNumber(enemy+1);//This number should be different than enemyQuantity's number.
        
        Enemy* villan = getEnemy(randomEnemy);
        enemies.push_back(villan);  
    }
}

int Room::getRandomNumber(int counter) const{
    int randomNumber = rand();
    randomNumber = ((randomNumber/counter) % 4) + 1;
    return randomNumber;//This should return a number between 1 to 4.
}

Enemy* Room::getEnemy(int randEnemy){
    Enemy* enemy = nullptr;
    
    switch(randEnemy){
            case 1:{ 
                enemy = new Witch("Witch",1,2,3,4,5,6); 
                break;
                }
            case 2:{ 
                enemy = new Spider("Spider",1,2,3,4,5);
                break;
            }
            case 3:{ 
                enemy = new Golem("Golem",1,2,3,4,5);
                break;
            }
            case 4:{ 
                enemy = new Skeleton("Skeleton",1,2,3,4,5);
                break;
            }
            case 5:{
                enemy = new Boss("Boss",1,2,3,4,5,6);
                break;
            }
            default: break;
        }

    return enemy;
}

void Room::setRmStatus(string status){
    rmStatus = status;
    assert(rmStatus != " " && "ERROR! The 'status' parameter in Room::setRmStatus() not correctly setting room status.");
}

void Room::startBattle(){

}

string Room::getRmStatus() {
    return rmStatus;
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