#include "../header/map.h"
#include <vector>
#include <assert.h>
using namespace std;

Map::Map(){
    //Player starts at room 4, which is index 3 in the vector.
    currRoom = 3;

    //Throw an error if currRoom doesn't start at index 3.
    if(currRoom != 3){ throw "Failed to initialize the current room."; }

    //Create an empty room;
    Room rm;
    
    for(int r = 0; r < NUMOFROOMS; r++){
        rooms.push_back(rm);
        if(r == 0){
            rooms[r].setRmStatus("Start");
        }
        else if(r == 1 || r == 2){
            rooms[r].setRmStatus("Clear");
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

void Map::moveRooms(int moveTo){
    //Move to next or previous room.
    currRoom = (currRoom + moveTo);
}

int Map::getCurrRoom() const{
    //Returns the room that the player is currently in.
    return currRoom;
}