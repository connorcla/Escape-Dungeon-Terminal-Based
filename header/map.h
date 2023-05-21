#ifndef MAP_H
#define MAP_H
#include "../header/room.h"
#include <vector>

class Map{
    public:
        Map();
        void moveRooms(int);
        int getCurrRoom() const;

    private:
        vector<Room> rooms;
        const int NUMOFROOMS = 10;
        int currRoom; 
};
#endif
