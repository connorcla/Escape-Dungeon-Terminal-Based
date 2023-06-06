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
        //Change health potion I with correct index after merge
        inventory.addItem(allItems.returnItem(0,0), allItems.returnItem(0,1), allItems.returnItem(0,2), allItems.returnItem(0,3));
        inventory.addItem(allItems.returnItem(30,0), allItems.returnItem(30,1), allItems.returnItem(30,2), allItems.returnItem(30,3));
        inventory.addItem(allItems.returnItem(30,0), allItems.returnItem(30,1), allItems.returnItem(30,2), allItems.returnItem(30,3));
        inventory.equipWeapon(0, player);
        clearScreen();
        mainMenu();
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
        cout << "You find yourself in a dim room and nothing seems to be moving except the flicker of the torches on the walls." << endl << endl;
        cout << "What would you like to do?" << endl << endl;
        cout << "1. Look around the room for any items" << endl;
        cout << "2. Examine the room" << endl;
        cout << "3. View Inventory" << endl;
        cout << "4. View Map" << endl;
        cout << "5. Move to the next room" << endl;
        cout << endl;
        cout << "Choose (1-5) " << player.getName() << ": ";

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
                    cout << endl;
                    cout << map.getCurrInfo() << endl << endl;
                    cout << "Enter anything to continue: ";
                    getCharInput();
                    clearScreen();
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
                    map.moveToNextRoom();
                    clearScreen();
                    cout << "Map:" << endl;
                    displayMap();
                    cout << "As you enter the next room, monsters begin to appear!!!" << endl;
                    battleMenu();
                    if(player.getCurrHealth() <= 0){
                        return;
                    }
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

    while (true) {
        char cInput = getCharInput();
        if(cInput == 'b') {
            clearScreen();
            return;
        }
        else {
            cout << "Invalid Input: Please try again." << endl;
            cout << "Enter (b) to stop viewing your map: ";
        }
    }
}

void ScreenManager::displayMap(){
    std::string roomStatus;
    const unsigned NUMOFROOMS = map.getNumOfRooms();

    cout << "-------------------------------------------------------------------------------" << endl;
    for(int room = 0; room < NUMOFROOMS; room++){
        roomStatus = map.getRoomStatus(room);
        cout << "| ";
        if(room != (NUMOFROOMS-1)){ cout << roomStatus; }
        else{ cout << roomStatus << " |"; }
    }
    cout << endl;
    cout << "-------------------------------------------------------------------------------" << endl << endl;
}

void ScreenManager::inventoryMenu() {
    while(true) {
        cout << "Satchel:" << endl;

        std::string list = inventory.listInventory();
        int size = inventory.numItems();
        cout << list << endl << endl; 

        cout << "Equipped Weapon:" << endl;
        cout << inventory.outputWeapon() << endl << endl;

        cout << "Equip Slots:" << endl;
        cout << inventory.outputEquipped() << endl << endl; 
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
    cout << "Magic: " << player.getMagic() << endl; //Add variable
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
    char choice;
    int numChoice;
    vector<int> savedPlayerStats;
    savedPlayerStats.push_back(player.getAttack());
    savedPlayerStats.push_back(player.getDefense());
    savedPlayerStats.push_back(player.getMagic());
    savedPlayerStats.push_back(player.getSpeed());

    do{
        cout << endl;
        cout << "Monsters block your path:" << endl << endl;
        displayEnemies();
        cout << endl;
        cout << "--------------------------------------" << endl;
        cout << "Health: [" << player.getCurrHealth() << "/" << player.getMaxHealth() << "]" << endl; //Replace with appropriate variables
        cout << "--------------------------------------" << endl;
        cout << "What would you like to do?" << endl << endl;
        cout << "1. Attack an enemy" << endl;
        cout << "2. Use an item" << endl;
        cout << "3. Attempt to flee (return to previous room)" << endl << endl;
        cout << "Choose (1-3) " << player.getName() << ": ";
        cin >> choice;

        numChoice = choice - 48;

        while(numChoice != 1 && numChoice != 2 && numChoice != 3){
            cout <<  "Invalid input! " << choice << " is not an option. Please try again." << endl;
            cout <<  player.getName() << ": ";
            cin.clear();
            cin >> choice;
            numChoice = choice - 48;
        }

        std::vector<std::string> turnOutputs;
        switch(numChoice){
            case 1: { 
                cout << endl;
                cout << "Enemies: " << endl;
                displayEnemies();
                attackMenu();
                if(map.getEnemyQuantity()==0) {
                    cout << endl; 
                    cout << "CONGRATULATIONS " << player.getName() <<"!!! You've defeated all enemies in this room!" << endl << endl; 
                    player.setStats(player.getMaxHealth(), player.getCurrHealth(), savedPlayerStats.at(1), savedPlayerStats.at(0), savedPlayerStats.at(3), player.getExp(), player.getName());
                    player.setMagic(savedPlayerStats.at(2));
                    return;
                }
                if(player.getCurrHealth() <= 0){
                    lostScreen();
                    return;
                }
                break; 
            } 
            case 2: {
                std::string list = inventory.listInventory();
                int size = inventory.numItems();
                cout << list << endl << endl; 
                
                while(true) {
                    cout << "Enter item number of usable item (1-" << size << ") to use an item: ";

                    char cInput;
                    std::string input;
                    int numValue = 0;
                    cin >> input;
                    cout << endl;

                    if(input.size() > 1) {
                        char cInput1 = input.at(0);
                        char cInput2 = input.at(1);
                        numValue = ((cInput1 - 48) * 10) + (cInput2 - 48);
                    }
                    else {
                        cInput = input.at(0);
                        numValue = cInput - 48;
                    }
                    numValue -= 1;
                    clearScreen();
                    if(!(numValue >= 0 && numValue <= inventory.numItems() && inventory.numItems() != 0))
                    {
                        cout << "Invalid input, please try again." << endl << endl;
                    }
                    else {
                        turnOutputs = map.itemBattle(inventory, player, numValue);
                        for(unsigned int i = 0; i < turnOutputs.size(); i++) {
                            cout << turnOutputs.at(i) << endl;
                        }
                        cout << endl;
                        break;
                    }
                }
                break;
             }
            case 3: {
                clearScreen();
                cout << "You are now back in the previous room." << endl;
                cout << "Hurry! Find the items and weapons you need to combat the monsters in the next room...." <<  endl;
                map.fleeToPrevRoom();
                displayMap();
                player.setStats(player.getMaxHealth(), player.getCurrHealth(), savedPlayerStats.at(1), savedPlayerStats.at(0), savedPlayerStats.at(3), player.getExp(), player.getName());
                player.setMagic(savedPlayerStats.at(2));
                return;
                } 
            default: { cout << "Error occurred in ScreenManager::battleMenu(). " << endl; }
                 
        }

    }while(choice > 0 || 3 >= choice);
    
}

void ScreenManager::attackMenu(){
    const unsigned int enemyQuantity = map.getEnemyQuantity();
    if(enemyQuantity == 0){
        cout << "All enemies defeated in this room. GOOD JOB! " << endl;
    }
    else{
        char chooseEnemy;
        int enemyChosen;
        cout << endl << "Which enemy do you want to attack?" << endl << "(Example: Press '1' for " << map.getEnemyName(0) << ")" << endl;
        cout << player.getName() << ": ";
        cin >> chooseEnemy;
        enemyChosen = chooseEnemy - 48;

        while(0 >= enemyChosen || enemyChosen > enemyQuantity){
            cout << endl;
            cout << "Invalid input! " << chooseEnemy << " is not an option." << endl;
            cout << "Please try again, " << player.getName() << ": ";
            cin >> chooseEnemy;
            enemyChosen = chooseEnemy - 48;
        }

        std::vector<std::string> turnOutputs = map.fightScenario(inventory, player, (enemyChosen-1));
        clearScreen();
        for(unsigned int i = 0; i < turnOutputs.size(); i++) {
            cout << turnOutputs.at(i) << endl;
        }
    }
}

void ScreenManager::displayEnemies() {
    int enemyQuantity = map.getEnemyQuantity();
    string enemyName;
    int enemyMAXHealth;
    int enemyCURRNTHealth;

    for(int enemy = 0; enemy < enemyQuantity; enemy++){
        enemyName = map.getEnemyName(enemy);
        enemyCURRNTHealth = map.getEnemyCURRNTHealthStatus(enemy);
        enemyMAXHealth = map.getEnemyMAXHealthStatus(enemy);

        cout << "(" << (enemy+1) << ") " << enemyName << "["<< enemyCURRNTHealth<<"/" << enemyMAXHealth << "]";
        
        if(enemy != (enemyQuantity-1)){ cout <<"    "; }
    }
    cout << endl;
}

void ScreenManager::winScreen() {
    cout << "CONGRATULATIONS!!!" << endl << endl;
    cout << "You have overcome the trials and tribulations set before you and escaped with only your wits and what you could find!" << endl; 
    cout << "But have you found all the secrets hidden in this dungeon or found every powerful item? Or maybe, the dungeon calls once more..."; 
    cout << endl << endl;
    cout << "Enter anything to exit: ";
    //User input to exit
}

void ScreenManager::lostScreen() {
    cout << endl << endl;
    cout << "OH NO, YOU DIED!!!" << endl;
    cout << "Enemies of the dungeon have killed you and taken your soul....RIP " << player.getName() << "...." << endl;
    cout << endl << endl;
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