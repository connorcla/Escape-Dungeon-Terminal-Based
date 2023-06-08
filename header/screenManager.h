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

        void setUp();
        void mainMenu();
        void idleRoomMenu();
        void mapMenu();  
        void displayMap();
        
        //Functions for Inventory items:
        void inventoryMenu();   //Takes in Inventory argument *FIX LATER*
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
        void winScreen();
        void lostScreen();
        void clearScreen();
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
        void checkUseItemChoice(char*);

    private:
        Map map;
        Player player;
        Inventory inventory;
        ItemDatabase allItems;
};

#endif
