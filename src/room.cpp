#include "../header/room.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

Room::Room(int randomQuantity) {
    generateItems(randomQuantity);
}

Room::~Room(){
    //delete vector<Enemy> enemies
    //vector<Enemy>::iterator it = enemies.begin();
}

void Room::setRmStatus(string status){
    rmStatus = status;
}

void Room::startBattle(){

}

string Room::getRoomInfo(){
    return rmInfo;
}

string Room::getRoomStatus(){
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