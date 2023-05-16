#include <iostream>
#include "../header/screenManager.h"

using std::cout;
using std::endl;

ScreenManager::ScreenManager() {}

ScreenManager::~ScreenManager() {}

void ScreenManager::setUp() {
    //Initialize Player object and any map stuff needed
    
}

void ScreenManager::mainMenu() {
    cout << "Escape Dungeon" << endl << endl;
    cout << "Can you:" << endl;
    cout << "Build your arsenal," << endl;
    cout << "Battle through enemies," << endl;
    cout << "Reach the end before you are stopped?" << endl;

    cout << "Enter your name to begin: ";
    //cin >> player.Name; Set player's name here and begin
}

void ScreenManager::roomIdle() {
    cout << "You find yourself in a damp room and nothing seems to be moving except the flicker of the torches on the walls." << endl << endl;
    cout << "What would you like to do?" << endl << endl;
    cout << "1. Look around the room for any items" << endl;
    cout << "2. Examine the room" << endl;
    cout << "3. View Inventory" << endl;
    cout << "4. View Map" << endl;
    cout << "5. Move to the next room" << endl;
    cout << endl;
    cout << "Enter your choice (1-5): ";

    //Add user input, choice validation and corresponding functions for appropriate choice
}

void ScreenManager::battleMenu() {
    cout << "Current Map:" << endl;
    cout << "A map that you were gripping when you woke up." << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "| Start | Clear | Clear | Here |  ?  |  ?  |  ?  |  ?  |  ?  | Exit? |" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Start: Where you woke up and began your journey." << endl;
    cout << "Clear: All enemies have been vanquished from there, there is no use going back." << endl;
    cout << "Here: You are currently in this room." << endl;
    cout << "?: Unexplored rooms, wonder what lies ahead." << endl;
    cout << "Exit?: Marked as a possible escape, hopefully this map tells the truth." << endl;
    cout << endl;
    cout << "Enter (b) to stop viewing your map: ";

    // Add user input validation, navigation back to idle room
}

void ScreenManager::inventoryMenu() {

}

void ScreenManager::winScreen() {

}

void ScreenManager::gameOver() {

}

void ScreenManager::clearScreen() {

}