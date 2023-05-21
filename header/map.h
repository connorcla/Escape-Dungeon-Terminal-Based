#ifndef MAP_H
#define MAP_H
#include "room.h"
#include <vector>

class Map{
    private:
    vector<Room> rooms;
    const int NUMOFROOMS = 10;
    int currRoom; 

    public:
    Map();
    ~Map();

    void moveRooms(int);
    int displayMap() const;
};
#endif
