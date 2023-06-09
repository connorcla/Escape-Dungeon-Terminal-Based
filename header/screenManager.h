#ifndef SCREENMANAGER_HPP
#define SCREENMANAGER_HPP
#include "itemDatabase.h"
#include "player.h"
#include "inventory.h"
#include "map.h"

class ScreenManager {
    public:
        ScreenManager();
        ~ScreenManager();

        //Functions for Menus & specific displays:
        void setUp();
        void mainMenu();
        void idleRoomMenu();
        void examineRoom();
        void mapMenu();  
        void displayMap();
        void winScreen();
        void lostScreen();
        void clearScreen();
        
        //Functions for Inventory items:
        void inventoryMenu();
        void invLogistics(unsigned int);
        void displayItem();
        void equipWeapon(char,unsigned int);
        void equipItem(char,unsigned int);
        void useItem();

        //Functions for Player stats:
        void playerStats();
        void modPlayerStats(char);

        //Functions for Battle menu (fight scenario):
        void battleMenu();
        void attackMenu();
        void displayEnemies();
        void displayTurnOutputs(std::string,int);

        //Extended functions for validating user input:
        void checkIdleRoomChoice(char*);
        void checkMapMenuChoice(char*);
        void checkInventoryMenuChoice(char*);
        void checkInvLogisticsChoice(char*);
        void checkRemoveItemChoice(char*);
        void checkPlayerStatsChoice(char*);
        void checkBattleMenuChoice(char*);
        void checkAttackMenuChoice(char*);
        void checkUseItemChoice(std::string*);

    private:
        Map map;
        Player player;
        Inventory inventory;
        ItemDatabase allItems;
};

#endif
