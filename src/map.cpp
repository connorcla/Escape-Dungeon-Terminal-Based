#include "../header/map.h"
#include <vector>
#include <assert.h>
using namespace std;

Map::Map() {
    //Player starts at room 4, which is index 3 in the vector.
    currRoom = 1;
    assert(currRoom == 1 && "ERROR! 'currRoom' not assigned to correct value in Map::Map().'");
    generateRooms();
}

Map::~Map() {}

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
}

void Map::moveToNextRoom() {

    if(currRoom < 9){
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

unsigned int Map::getCurrRoom() const {
    return currRoom;
}

unsigned int Map::getNumOfRooms() const {
    return NUMOFROOMS;
}

string Map::getRoomStatus(const unsigned room) {
    string roomStatus = rooms[room].getRmStatus();
    return roomStatus;
}

vector<string> Map::getItemFromCurrRoom() {
    return rooms.at(currRoom).getItem();

}