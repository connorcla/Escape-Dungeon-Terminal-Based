#include <string>
#include <iostream>
#include "../header/screenManager.h"

using namespace std;

int main() {

    ScreenManager screen;
    string waitInput = "";

    screen.setUp();
    screen.clearScreen();
    
    screen.mainMenu();
    cin >> waitInput;
    screen.clearScreen();

    screen.roomIdle();
    cin >> waitInput;
    screen.clearScreen();

    screen.mapMenu();
    cin >> waitInput;
    screen.clearScreen();

    screen.inventoryMenu();
    cin >> waitInput;
    screen.clearScreen();

    screen.playerStats();
    cin >> waitInput;
    screen.clearScreen();

    screen.battleMenu();
    cin >> waitInput;
    screen.clearScreen();

    screen.winScreen();
    cin >> waitInput;
    screen.clearScreen();

    screen.gameOver();
    cin >> waitInput;

    return 0;
}