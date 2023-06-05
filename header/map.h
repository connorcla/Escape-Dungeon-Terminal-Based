#ifndef MAP_H
#define MAP_H
#include "room.h"
#include "item.h"
#include "player.h"
#include <vector>

class Map {
    public:
        Map();
        ~Map();

        void generateRooms();
        void moveToNextRoom();
        void fleeToPrevRoom();
        vector<string> fightScenario(Inventory&, Player&, int);
        unsigned int getCurrRoom() const;
        unsigned int getNumOfRooms() const;
        unsigned int getEnemyQuantity() const;
        unsigned int getEnemyCURRNTHealthStatus(const int) const;
        unsigned int getEnemyMAXHealthStatus(const int) const;
        string getCurrInfo(); 
        string getRoomStatus(const unsigned);
        string getEnemyName(const int) const;
        int getEnemySpeed(const int) const;
        vector<string> getItemFromCurrRoom();
        vector<string> itemBattle(Inventory&, Player&, int);

    private:
        vector<Room> rooms;
        const unsigned int NUMOFROOMS = 10;
        unsigned int currRoom; 
};
#endif
