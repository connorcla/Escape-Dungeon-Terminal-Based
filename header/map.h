#ifndef MAP_H
#define MAP_H
#include "../header/room.h"
#include <vector>

class Map {
    public:
        Map();
        void moveToNextRoom();
        void fleeToPrevRoom();
        unsigned int getCurrRoom() const;
        unsigned int getNumOfRooms() const;

    private:
        vector<Room> rooms;
        const unsigned int NUMOFROOMS = 10;
        unsigned int currRoom; 
};
#endif
