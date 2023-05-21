#include "../header/map.h"
#include <vector>
using namespace std;

Map::Map(){
    //Player starts at room 4, which is index 3 in the vector.
    currRoom = 3;
    //Create an empty room;
    Room rm;
    
    for(int r = 0; r < NUMOFROOMS; r++){
        rooms.push_back(rm);
        if(r == 0){
            rooms[i].setRmStatus("Start");
        }
        else if(r == 1 || r == 2){
            rooms[i].setRmStatus("Clear");
        }
        else if(r == currRoom){
            rooms[i].setRmStatus("Here");
        }
        else if(r != (NUMOFROOMS-1)){
            rooms[i].setRmStatus(?);
        }
        else{
            rooms[i].setRmStatus("Exit?");
        }
    }
}

void Map::moveRooms(int moveTo){
    currRoom++;
}

int Map::displayMap() const{
    return currRoom;
}