#ifndef ROOM_H
#define ROOM_H
#include "enemy.h"
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
        Room();
        Room(int);
        ~Room();

        //Enemy functions
        void generateEnemies(int);
        void setEnemiesBeforeLastRoom(const int);
        int getRandomNumber(int) const;
        Enemy* getEnemy(int);
        void deleteEnemies();
        
        //Item functions
        void generateItems(int);
        vector<string> getItem();

        void setRmStatus(string);
        void setRoomInfo(string);
        void startBattle();
        string getRmStatus();
        string getRoomInfo();
        

    private:
        vector <Enemy* > enemies;
        vector <vector<string>> items;
        string rmStatus = " ";//States either the room is "Clear" or not.
        string rmInfo;
};
#endif