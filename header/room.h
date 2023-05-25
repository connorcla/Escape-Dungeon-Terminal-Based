#ifndef ROOM_H
#define ROOM_H
//#include "Enemy"
//#include "Item"
#include <vector>
#include <string>
using namespace std;

class Room{
    public:
        Room();

        void setRmStatus(string);
        void startBattle();

        string getRoomInfo();
        string getRoomStatus();

    private:
//        vector <Enemy> enemies;
//        vector <Item> items;
        string rmStatus;//States either the room is "Clear" or not.
        string rmInfo;

};
#endif