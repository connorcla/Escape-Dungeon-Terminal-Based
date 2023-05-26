#ifndef SCREENMANAGER_HPP
#define SCREENMANAGER_HPP
#include "map.h"

class ScreenManager {
    public:
        ScreenManager();
        ~ScreenManager();
        void setUp();
        void mainMenu();
        void roomIdle();             //Takes in Room argument *FIX LATER*
        void prevRoom();
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
};

#endif