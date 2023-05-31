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
        void roomIdle();             //Takes in Room argument *FIX LATER*
        void mapMenu();           //Takes in Room argument *FIX LATER*
        void displayMap();
        void inventoryMenu();   //Takes in Inventory argument *FIX LATER*
        void playerStats();
        void battleMenu();
        void winScreen();
        void gameOver();
        void clearScreen();
        
    private:
        Map map;
        Player player;
        Inventory inventory;
        ItemDatabase allItems;
};

#endif