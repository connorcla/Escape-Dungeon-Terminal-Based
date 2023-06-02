#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "../header/screenManager.h"
#include "../header/inventory.h"

using std::cout;
using std::cin;
using std::endl;

char getCharInput() {
    std::string sInput;
    char cInput;
    cin >> sInput;
    cInput = sInput[0];
    return cInput;
}

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
    std::string nameInput = "";
    getline(std::cin, nameInput);
    player.setName(nameInput);

    clearScreen();
    roomIdle();
}

void ScreenManager::roomIdle() {
    while(true) {
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
        char choice = getCharInput();
        int numChoice = choice - 48;
        if(numChoice == 0) {
            return;             //FOR TESTING, QUICK QUIT REMOVE LATER
        }
        if(numChoice > 5 || numChoice < 1) {
            clearScreen();
            cout << "Invalid Input: Please try again." << endl;
            continue; 
        }
        else {
            int itemFoundChance = (rand() % 2);
            switch(numChoice) {
                case 1:
                    if(inventory.numItems() == 30) {
                        clearScreen();
                        cout << "Sorry your inventory is full. To gather more items, you will have to remove other items from your inventory first." << endl;
                    }
                    else {
                        if(itemFoundChance == 0) {
                            clearScreen();
                            cout << "No luck at finding any items this time. Are there even any more items in here?" << endl;
                        }
                        else if(itemFoundChance == 1) {
                            std::vector<std::string> itemFound = map.getItemFromCurrRoom();

                            if(itemFound.at(0) == " ") {
                                clearScreen();
                                cout << "No luck at finding any items this time. Are there even any more items in here?" << endl;
                            }
                            else {
                                clearScreen();
                                cout << "You found a " << itemFound.at(0) << "! This has been added to your inventory." << endl;
                                inventory.addItem(itemFound.at(0), itemFound.at(1), itemFound.at(2), itemFound.at(3));
                            }
                        }
                    }
                    break;
                case 2:
                    //Output dialoge with the room description
                    break;
                case 3:
                    clearScreen();
                    inventoryMenu();
                    break;
                case 4:
                    clearScreen();
                    mapMenu();
                    break;
                case 5:
                    //Increase room count, go to battle menu, start battle
                    map.moveToNextRoom();
                    clearScreen();
                    cout << "Moved to next room." << endl;
                    //battleMenu();
                    break;
                default:
                    cout << "An error occurred." << endl;
            }
        }
    }
}

void ScreenManager::mapMenu() {
    cout << "Current Map:" << endl;
    cout << "A map that you were gripping when you woke up." << endl;
    
    displayMap();

    cout << endl;
    cout << "Start: Where you woke up and began your journey." << endl;
    cout << "Clear: All enemies have been vanquished from there, there is no use going back." << endl;
    cout << "Here: You are currently in this room." << endl;
    cout << "?: Unexplored rooms, wonder what lies ahead." << endl;
    cout << "Exit?: Marked as a possible escape, hopefully this map tells the truth." << endl;
    cout << endl;
    cout << "Enter (b) to stop viewing your map: ";

    // Add user input validation, navigation back to idle room
    while (true) {
        char cInput = getCharInput();
        if(cInput == 'b') {
            return;
        }
        else {
            cout << "Invalid Input: Please try again." << endl;
            cout << "Enter (b) to stop viewing your map: ";
        }
    }
}

void ScreenManager::displayMap(){
    const unsigned int currntRoom = map.getCurrRoom();
    const unsigned int NUMOFROOMS = map.getNumOfRooms();
    cout << "----------------------------------------------------------------------" << endl;
    for(int room = 0; room < NUMOFROOMS; room++){
        cout << "| ";
        if(room == 0){ cout << "Start "; }
        else if(room > 0 && room < currntRoom){ cout << "Clear "; }
        else if(room == currntRoom){ cout << "Here "; }
        else if(room >currntRoom && room < (NUMOFROOMS-1)){ cout << " ?  "; }
        else cout << "Exit? |"; 
    }
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;
    
}

void ScreenManager::inventoryMenu() {
    while(true) {
        cout << "Satchel:" << endl;

        std::string list = inventory.listInventory();
        int size = inventory.numItems();
        cout << list << endl << endl; //Would output the list of items in inventory object from Player

        cout << "Equipped Weapon:" << endl;
        cout << inventory.outputWeapon() << endl << endl;

        cout << "Equip Slots:" << endl;
        cout << inventory.outputEquipped() << endl << endl; //Change with actual equipped items
        cout << "Enter item number (1-" << size << ") to view item, 0 to see your stats, or (b) to go back: ";

        char cInput;
        std::string input;
        int numValue = 0;
        cin >> input;
        cout << endl;
        if(input == "b")
        {
            clearScreen();
            return;
        }
        if(input.size() > 1) {
            char cInput1 = input.at(0);
            char cInput2 = input.at(1);
            numValue = ((cInput1 - 48) * 10) + (cInput2 - 48);
        }
        else {
            cInput = input.at(0);
            numValue = cInput - 48;
        }
        if(!(numValue >= 0 && numValue <= inventory.numItems()))
        {
            clearScreen();
            cout << "Invalid input, please try again." << endl << endl;
        }
        else {
            if(numValue == 0) {
                clearScreen();
                playerStats();
                clearScreen();
            }
            else {
                cout << inventory.displayItem(numValue-1);
                cout << endl;
                if((inventory.returnItem(numValue-1)->getID() / 100) == 1) {
                    cout << "You can equip this weapon with (e), remove it with (r), or continue with anything else: ";
                    cInput = getCharInput();
                    cout << endl;
                    clearScreen();
                    if(cInput == 'e') {
                        cout << "Weapon equipped!" << endl << endl;
                        inventory.equipWeapon(numValue-1,player);
                    }
                    else if(cInput == 'r') {
                        inventory.removeItem(numValue-1);
                        cout << "Item removed." << endl << endl;
                    }
                }
                else if((inventory.returnItem(numValue-1)->getID() / 100) == 2) {
                    cout << "You can equip this item with (e), remove it with (r), or continue with anything else: ";
                    cInput = getCharInput();
                    cout << endl;
                    clearScreen();
                    if(cInput == 'e') {
                        cout << "Equipped!" << endl << endl;
                        inventory.equipItem(numValue-1,player);
                    }
                    else if(cInput == 'r') {
                        inventory.removeItem(numValue-1);
                        cout << "Item removed." << endl << endl;
                    }
                }
                else if((inventory.returnItem(numValue-1)->getID() / 100) == 3) {
                    cout << "You can remove this item with (r), or continue with anything else: ";
                    cInput = getCharInput();
                    cout << endl << endl;
                    clearScreen();
                    if(cInput == 'r') {
                        inventory.removeItem(numValue-1);
                        cout << "Item removed." << endl << endl;
                    }
                }
            }
        }
    }
    

    //Get input from player and either output item info or change screens
}

void ScreenManager::playerStats() {
    cout << player.getName() << "\'s Current Statistics:" << endl << endl;
    cout << "Maximum Health: " << player.getMaxHealth() << endl; //Add variable
    cout << "Maximum Magic: " << player.getMaxMagic() << endl; //Add variable
    cout << "Attack: " << player.getAttack() << endl; //Add variable
    cout << "Defense: " << player.getDefense() << endl; //Add variable
    cout << "Speed: " << player.getSpeed() << endl; //Add variable
    cout << "EXP: " << player.getExp() << endl; //Add variable
    cout << endl;
    cout << "You can increase any statistic by 1 point by spending 10 EXP." << endl;
    cout << "Enter which statistic you wish to increase (H,M,A,D,S) or enter (b) to go back to satchel: ";
    char input;
    std::cin >> input;
    cout << endl;
    //Get user input validation and apply change
}

void ScreenManager::battleMenu() {
    unsigned int choice;
    do{
        cout << "Monsters block your path:" << endl << endl;
        cout << "[Enemies]" << endl; //Replace with list of enemies
        cout << "Witch [23/40]   Golem [17/60]   Spider [24/30] " << endl; //Replace with each enemy's getHealth() return
        cout << "--------------------------------------" << endl;
        cout << "Health: [27/50]     Magic: [35/50]" << endl; //Replace with appropriate variables
        cout << "--------------------------------------" << endl;
        cout << "What would you like to do?" << endl << endl;
        cout << "1. Attack an enemy" << endl;
        cout << "2. Use an item" << endl;
        cout << "3. Attempt to flee (return to previous room)" << endl << endl;
        cout << "Enter your choice (1-3): ";

        //Get user input validation, lots of output depending on choice
        cin >> choice;

        while(choice != 1 && choice != 2 && choice != 3){
            cout <<  "Invalid input! " << choice << " is not an option. Please try again." << endl;
            cin >> choice;
        }

        switch(choice){
            case 1: { break; } //Attack enemy
            case 2: { break; } //Use an item
            case 3: {
                    clearScreen();
                    cout << "You are now back in the previous room." << endl;
                    cout << "Hurry! Find the items and weapons you need to combat the monsters in the next room...." <<  endl;
                    map.fleeToPrevRoom();
                    displayMap();
                    return;
                }
            default: { cout << "Error occurred in ScreenManager::battleMenu(). " << endl; }
                 
        }

    }while(choice > 0 || 3 >= choice);
    
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