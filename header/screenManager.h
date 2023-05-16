#ifndef SCREENMANAGER_HPP
#define SCREENMANAGER_HPP

class ScreenManager {
    public:
        ScreenManager();
        ~ScreenManager();
        void setUp();
        void mainMenu();
        void roomIdle();             //Takes in Room argument *FIX LATER*
        void battleMenu();           //Takes in Room argument *FIX LATER*
        void inventoryMenu();   //Takes in Inventory argument *FIX LATER*
        void winScreen();
        void gameOver();
        void clearScreen();
};

#endif