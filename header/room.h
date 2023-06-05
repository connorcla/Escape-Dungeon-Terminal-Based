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
#include <algorithm>

using namespace std;

class Room{
    public:
        Room();
        Room(int);
        ~Room();

        //Enemy functions
        void generateEnemies(int);
        void setEnemiesBeforeLastRoom(const int, int);
        void sortEnemies(); //Sort enemies by speed
        void removeEnemy(const int);
        void deleteEnemies();
        int getRandomNumber(int) const;
        unsigned int getNumOfEnemies() const;
        unsigned int getEnemyCURRNTHealth(const int) const; 
        unsigned int getEnemyMAXHealth(const int) const;
        string getEnemyName(const int) const;
        Enemy* getEnemy(int, int);
        static bool compareEnemies(Enemy*, Enemy*);
        
        //Item functions
        void generateItems(int);
        vector<string> getItem();
        
        //Room specific functions
        void setRmStatus(string);
        void setRoomInfo(string);
        void startBattle(Player&, int);
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