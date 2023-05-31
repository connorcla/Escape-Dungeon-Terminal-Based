#include "../header/map.h"
#include <vector>
#include <assert.h>
using namespace std;

Map::Map() {
    //Player starts at room 4, which is index 3 in the vector.
    currRoom = 1;
    if(currRoom != 1){ throw "Failed to initialize the current room."; }
    
    int randomEnemies;
   
    for(int r = 0; r < NUMOFROOMS; r++){ 
        Room rm(r);
    
        rooms.push_back(rm);
        if(r == 0){
            rooms[r].setRmStatus("Start");
        }
        else if(r == currRoom){
            rooms[r].setRmStatus("Here");
        }
        else if(r != (NUMOFROOMS-1)){
            rooms[r].setRmStatus("?");
        }
        else{
            rooms[r].setRmStatus("Exit?");
        }
    }
}


void Map::moveToNextRoom() {
    currRoom++;
}

void Map::fleeToPrevRoom() {
    currRoom--;
}

unsigned int Map::getCurrRoom() const {
    return currRoom;
}

unsigned int Map::getNumOfRooms() const {
    return NUMOFROOMS;
}

vector<string> Map::getItemFromCurrRoom() {
    return rooms.at(currRoom).getItem();

}