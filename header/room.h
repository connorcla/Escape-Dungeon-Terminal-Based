#ifndef ROOM_H
#define ROOM_H
//#include "enemy.h"
#include "item.h"
#include "itemDatabase.h"
#include "weapon.h"
#include "usable.h"
#include "equip.h"
#include <vector>
#include <string>

using namespace std;

class Room{
    public:
        Room(int);
        ~Room();
        //Enemy functions
        void generateEnemies(int);
        int vecIndxOfEnemy();
        //Enemy* getEnemy(int);
        
        //Item functions
        void generateItems(int);
        vector<string> getItem();

        void setRmStatus(string);
        void startBattle();
        string getRoomInfo();
        string getRoomStatus();
        

    private:
        //vector <Enemy* > enemies;
        vector <vector<string>> items;
        string rmStatus;//States either the room is "Clear" or not.
        string rmInfo;
};
#endif