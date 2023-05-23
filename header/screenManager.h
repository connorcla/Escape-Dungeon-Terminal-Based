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
        void mapMenu();           //Takes in Room argument *FIX LATER*
        void inventoryMenu();   //Takes in Inventory argument *FIX LATER*
        void playerStats();
        void battleMenu();
        void winScreen();
        void gameOver();
        void clearScreen();
};

#endif