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

void ScreenManager::mapMenu() {
    Map map; //Instatiate Map class.
    int MAPSIZE = 10; //Number of rooms (levels)
    int currLocation = map.getCurrRoom();

    cout << "Current Map:" << endl;
    cout << "A map that you were gripping when you woke up." << endl;
    cout << "----------------------------------------------------------------------" << endl;
    for(int room = 0; room < MAPSIZE; room++){
        cout << "| ";
        if(room == 0){ cout << "Start "; }
        else if(room > 0 && room < currLocation){ cout << "Clear "; }
        else if(room == currLocation){ cout << "Here "; }
        else if(room >currLocation && room < (MAPSIZE-1)){ cout << " ?  "; }
        else cout << "Exit? |"; 
    }
    cout << endl;
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
    cout << "Satchel:" << endl << endl;

    cout << "[List of Items]" << endl << endl; //Would output the list of items in inventory object from Player

    cout << "Equip Slots:" << endl;
    cout << "| Item1 |     " << "| Item2 |" << "     | Item3 |" << endl << endl; //Change with actual equipped items
    cout << "Enter item number (1-[numItems]) to view item or enter 0 to see your stats: ";
                                //replace numItems with variable
    //Get input from player and either output item info or change screens
}

void ScreenManager::playerStats() {
    cout << "Your Current Statistics:" << endl << endl;
    cout << "Maximum Health: " << endl; //Add variable
    cout << "Maximum Magic: " << endl; //Add variable
    cout << "Attack: " << endl; //Add variable
    cout << "Defense: " << endl; //Add variable
    cout << "Speed: " << endl; //Add variable
    cout << "EXP: " << endl; //Add variable
    cout << endl;
    cout << "You can increase any statistic by 1 point by spending 10 EXP." << endl;
    cout << "Enter which statistic you wish to increase (H,M,A,D,S) or enter (b) to go back to satchel: ";
    //Get user input validation and apply change
}

void ScreenManager::battleMenu() {
    cout << "Monsters block your path:" << endl << endl;
    cout << "[Enemies]" << endl << endl; //Replace with list of enemies
    cout << "--------------------------------------" << endl;
    cout << "Health: [27/50]     Magic: [35/50]" << endl; //Replace with appropriate variables
    cout << "--------------------------------------" << endl;
    cout << "What would you like to do?" << endl << endl;
    cout << "1. Attack an enemy" << endl;
    cout << "2. Use an item" << endl;
    cout << "3. Attempt to flee (return to previous room)" << endl << endl;
    cout << "Enter your choice (1-3): ";
    //Get user input validation, lots of output depending on choice
}

void ScreenManager::winScreen() {
    cout << "CONGRATULATIONS!!!" << endl << endl;
    cout << "You have overcome the trials and tribulations set before you and escaped with only your wits and what you could find!" << endl; 
    cout << "But have you found all the secrets hidden in this dungeon or found every powerful item? Or maybe, the dungeon calls once more..."; 
    cout << endl << endl;
    cout << "Enter anything to exit: ";
    //User input to exit
}

void ScreenManager::gameOver() {
    cout << "GAME OVER" << endl << endl;
    cout << "Your health has dropped to 0 and now your progress is lost to the dungeon once more..." << endl;
    cout << "Can you find the courage to attempt to escape again?" << endl << endl;
    cout << "Enter anything to exit: ";
    //User input to exit
}

void ScreenManager::clearScreen() {
    for (int i = 0; i < 100; i++) {
        cout << "\n";
    }
}