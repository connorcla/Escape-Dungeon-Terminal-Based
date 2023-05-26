#ifndef ROOM_H
#define ROOM_H
//#include "Enemy"
//#include "Item"
#include <vector>
#include <string>
using namespace std;

class Room {
    public:
        Room();

        void setRmStatus(string);

        string getRoomInfo() const;
        string getRoomStatus() const;

    private:
//        vector <Enemy> enemies;
//        vector <Item> items;
        string rmStatus;//States either the room is "Clear" or not.
        string rmInfo;

};
#endif