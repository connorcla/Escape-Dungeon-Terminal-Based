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
        void deleteEnemies();
        int getRandomNumber(int) const;
        Enemy* getEnemy(int);
        unsigned int getNumOfEnemies() const;
        unsigned int getEnemyCURRNTHealth(const int) const; 
        unsigned int getEnemyMAXHealth(const int) const;
        string getEnemyName(const int) const;
        
        //Item functions
        void generateItems(int);
        vector<string> getItem();
        
        //Room specific functions
        void setRmStatus(string);
        void setRoomInfo(string);
        void startBattle();
        string getRmStatus();  
        string getRoomInfo();

    private:
        vector <Enemy* > enemies;
        vector <vector<string>> items;
        string rmStatus = " ";
        string rmInfo;
        int enemyQuantity;
};
#endif