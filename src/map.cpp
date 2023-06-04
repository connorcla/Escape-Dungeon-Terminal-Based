#include "../header/map.h"
#include <vector>
#include <assert.h>
using namespace std;

Map::Map() {
    currRoom = 0;
    assert(currRoom == 0 && "ERROR! 'currRoom' not assigned to correct value in Map::Map().'");
    generateRooms();
}

Map::~Map() {
    for(int room = 0; room < NUMOFROOMS; room++) {
        rooms.at(room).deleteEnemies();
    }
}

void Map::generateRooms(){
    assert(NUMOFROOMS == 10 && "ERROR! 'NUMOFROOMS' is not properly initialized in Map::generateRooms().");

    for(int room = 0; room < NUMOFROOMS; room++){ 
        Room rm(room);
    
        rooms.push_back(rm);
        if(room == 0){
            rooms[room].setRmStatus("Start ");
        }
        else if(room == currRoom){
            rooms[room].setRmStatus("Here ");
        }
        else if(room != (NUMOFROOMS-1)){
            rooms[room].setRmStatus(" ?  ");
        }
        else{
            rooms[room].setRmStatus(" Exit? ");
        }
    }
    rooms.at(0).setRoomInfo("You just woke up in this room. There is only a dim light from a door frame which appears to be the only way forward.");
    rooms.at(1).setRoomInfo("A very stone cold room with patterns of bricks lining the floor illuminated by dim torches spanning the walls.\nThe only other thing the light reflects off of in the room are chains that hang in certain marked places.");
    rooms.at(2).setRoomInfo("Setting foot into this room, you feel a light touch underneath your feet. This room is lined and overflowing with vegetation.\nEven though this greenry is a nicer sight, the shadows of the swaying plants cause movement in the corner of your eye.");
    rooms.at(3).setRoomInfo("A cold breeze covers the entire room and appears like it is coming from the ceiling.\nSlight shimmers of ice plaster the walls making them shine more than usual.");
    rooms.at(4).setRoomInfo("On closer inspection, the torches appear to not be lit with actual fire.\nOne of the torches has wires coming out of it and the flame is flickering in an unusual way.\nThese rooms look more and more manufactured as each next door opens.");
    rooms.at(5).setRoomInfo("This room is dimmer than the last few but there is an abyss black in the center of the room.\nOn closer inspection, the void of light in the center of the room is a large hole.\nBetter not get any closer to it.");
    rooms.at(6).setRoomInfo("Separate pieces of furniture are sprawled across the expansive room. The furniture is very elaborate but very unorderly around the room.\nIt looks like a very nice place to stay, but you better not stay too long.");
    rooms.at(7).setRoomInfo("A wave of heat rushes past your entire body. Just standing in this room seems to drain some of your energy.\nInstead of torches lining the walls, a thin layer of heat emits from a slit between the walls and the ceiling.");
    rooms.at(8).setRoomInfo("Very similar to the room you woke up in, nothing appears to be left in the room except a few scattered items.\nThere is only a dim light coming from what appears to be the exit.\nBut, a sense of dread is emitting from it. What lies beyond the door?");
    rooms.at(9).setRoomInfo("How did you get here? Well anyway, thanks for playing our game! - Kal C");
}

void Map::moveToNextRoom() {

    if(currRoom == 0) {
        rooms[currRoom].setRmStatus("Start ");
        currRoom++;
        rooms[currRoom].setRmStatus("Here ");
    }
    else if(currRoom < 9){
        rooms[currRoom].setRmStatus("Clear ");
        currRoom++;
        rooms[currRoom].setRmStatus("Here ");
    }

    assert(currRoom < 10 && "ERROR! 'currRoom' cannot reach further than 10th room. Check Map::moveToNextRoom().");
}

void Map::fleeToPrevRoom() {
    if(currRoom > 1){ 
        rooms[currRoom].setRmStatus(" ?  ");
        currRoom--;
        rooms[currRoom].setRmStatus("Here "); 
        }
    assert(currRoom > 0 && "ERROR! 'currRoom' cannot be less than zero. Check Map::fleeToPrevRoom().");
}

string Map::getCurrInfo() {
    return rooms.at(currRoom).getRoomInfo();
}

unsigned int Map::getCurrRoom() const {
    return currRoom;
}

unsigned int Map::getNumOfRooms() const {
    return NUMOFROOMS;
}

unsigned int Map::getEnemyQuantity() const{
    //Get the number of enemies at the current room locaiton:
    return rooms[currRoom].getNumOfEnemies();
}

unsigned int Map::getEnemyCURRNTHealthStatus(const int enemyIndex) const {
    int enemyCurrHealth = 0;
    
    if(currRoom < 9){
        enemyCurrHealth  = rooms[currRoom].getEnemyCURRNTHealth(enemyIndex);
    }

    return enemyCurrHealth;
}

unsigned int Map::getEnemyMAXHealthStatus(const int enemyIndex) const {
    int enemyMAXHealth = 0;
    
    if(currRoom < 9){
        enemyMAXHealth = rooms[currRoom].getEnemyMAXHealth(enemyIndex);
    }

    return enemyMAXHealth;
}

string Map::getRoomStatus(const unsigned room) {
    string roomStatus = rooms[room].getRmStatus();
    return roomStatus;
}

string Map::getEnemyName(const int enemyIndex) const{
    string enemyName = " ";

    if(currRoom < 9){
        enemyName = rooms[currRoom].getEnemyName(enemyIndex);
    }

    return enemyName;
}

vector<string> Map::getItemFromCurrRoom() {
    return rooms.at(currRoom).getItem();

}