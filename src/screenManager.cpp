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
        inventory.addItem(allItems.returnItem(0,0), allItems.returnItem(0,1), allItems.returnItem(0,2), allItems.returnItem(0,3));
        inventory.addItem(allItems.returnItem(30,0), allItems.returnItem(30,1), allItems.returnItem(30,2), allItems.returnItem(30,3));
        inventory.addItem(allItems.returnItem(30,0), allItems.returnItem(30,1), allItems.returnItem(30,2), allItems.returnItem(30,3));
        inventory.equipWeapon(0, player);
        clearScreen();
        mainMenu();
}

void ScreenManager::mainMenu() {
    cout << "*~*~*~*~*~*~*~*~*~*~*~*~ Welcome to Escape Dungeon *~*~*~*~*~*~*~*~*~*~*~*~*" << endl << endl;
    cout << "Can you:" << endl;
    cout << "Build your arsenal," << endl;
    cout << "Battle through enemies," << endl;
    cout << "Reach the end before you are stopped?" << endl;

    cout << "Enter your name to begin: ";

    std::string nameInput = "";
    getline(std::cin, nameInput);
    player.setName(nameInput);

    clearScreen();
    idleRoomMenu();
}

void ScreenManager::idleRoomMenu() {
    char choice;

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
        choice = getCharInput();

        checkIdleRoomChoice(&choice);

        switch(choice){
            case '1':
                examineRoom();
                break;
            case '2':
                cout << endl;
                cout << map.getCurrInfo() << endl << endl;
                cout << "Press any key to continue: ";
                getCharInput();
                clearScreen();
                break;
            case '3':
                clearScreen();
                inventoryMenu();
                break;
            case '4':
                clearScreen();
                mapMenu();
                break;
            case '5':
                map.moveToNextRoom();
                clearScreen();
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

void ScreenManager::examineRoom() {
    int itemFoundChance = (rand() % 2);
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
}

void ScreenManager::checkIdleRoomChoice(char* choice) {
    while(*choice != '1' &&  *choice != '2' && *choice  != '3' && *choice  != '4' && *choice != '5'){
        cout << endl;
        cout << "Invalid choice! [" << *choice <<"] is not an option. Please try again." << endl;
        cout << player.getName() <<": ";
        *choice = getCharInput();
    }
    cout << endl;
}

void ScreenManager::mapMenu() {
    char choice;

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
    cout << "Press [b] to stop viewing your map: ";
    choice = getCharInput();

    checkMapMenuChoice(&choice);
}

void ScreenManager::checkMapMenuChoice(char* choice) {
    while(*choice != 'b'){
        cout << endl;
        cout << "Invalid choice! [" << *choice <<"] is not an option. Please try again." << endl;
        cout << player.getName() <<": ";
        *choice = getCharInput();
    }
    cout << endl;
}

void ScreenManager::displayMap() {
    std::string roomStatus;
    const unsigned NUMOFROOMS = map.getNumOfRooms();
   
    cout << "---------------------------------- MAP ----------------------------------------" << endl;
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
    char choice;
    
    while(true) {
        cout << "---------------------------- Inventory Items List --------------------------------" << endl << endl;
        cout << "Satchel:" << endl;
        std::string list = inventory.listInventory();
        cout << list << endl << endl; 
        cout << "Equipped Weapon:" << endl;
        cout << inventory.outputWeapon() << endl << endl;
        cout << "Equip Slots:" << endl;
        cout << inventory.outputEquipped() << endl << endl; 
        cout << "Choose what you'd like to do from this menu:" << endl; 
        cout << " Press [b] to go back to previous menu. " << endl;
        cout << " Press [v] to view an item from the list." << endl;
        cout << " Press [s] to view your stats. " << endl;
        cout << player.getName() <<": ";
        choice = getCharInput();

        checkInventoryMenuChoice(&choice);
       
        switch(choice) {
            case 'b': {
                clearScreen();
                return;
            }
            case 'v': {
                displayItem();
                clearScreen();
                break;
            }
            case 's': {
                playerStats();
                clearScreen();
                break;
            }
        }
    }
}

void ScreenManager::checkInventoryMenuChoice(char* choice) {
    while(*choice != 'b' && *choice != 'v' && *choice != 's'){
        cout << endl;
        cout << "Invalid choice! [" << *choice <<"] is not an option. Please try again." << endl;
        cout << player.getName() <<": ";
        *choice = getCharInput();
    }
    cout << endl;
}

void ScreenManager::displayItem() {
    int itemQuantity = inventory.numItems();
    unsigned int choice;
    
    do {
        cout << "Enter item number (1 - " << itemQuantity << ") to view an item." << endl;
        cout << player.getName() <<": ";
        cin >> choice;
        cout << endl;

        if(0 >= choice || choice > itemQuantity) {
            cout << "Invalid choice! '" << choice <<"' is not an option. Please enter a correct choice from the list." << endl;
        }
    } while(0 >= choice || choice > itemQuantity);

    invLogistics(choice);
}

void ScreenManager::invLogistics(unsigned int numValue) {
    int itemID = inventory.returnItem(numValue-1)->getID() / 100;
    char choice;

    cout << endl;
    cout << inventory.displayItem(numValue-1);
    cout << endl << endl;
    
    switch(itemID) {
        case 1: {
            cout << "You can equip this weapon by pressing [e], remove it with [r], or press [c] to continue." << endl;
            cout << player.getName() <<": ";
            choice = getCharInput();
            checkInvLogisticsChoice(&choice);
            equipWeapon(choice,numValue);
            break;
        }
        case 2: {
            cout << "You can equip this item by pressing [e], remove it with [r], or press [c] to continue." << endl;
            cout << player.getName() <<": ";
            choice = getCharInput();
            checkInvLogisticsChoice(&choice);
            equipItem(choice,numValue);
        }
        case 3: {
            cout << "You can remove this item by pressing [r], or press [c] to continue." << endl;
            cout << player.getName() <<": ";
            choice = getCharInput();
            checkRemoveItemChoice(&choice);
            cout << endl << endl;
            equipItem(choice,numValue);
        }
    }
}

void ScreenManager::checkInvLogisticsChoice(char* choice) {
    while(*choice != 'e' && *choice != 'r' && *choice != 'c'){
        cout << endl;
        cout << "Invalid choice! [" << *choice <<"] is not an option. Please try again." << endl;
        cout << player.getName() <<": ";
        *choice = getCharInput();
    }
    cout << endl;
}

void ScreenManager::checkRemoveItemChoice(char* choice) {
    while(*choice != 'r' && *choice != 'c'){
        cout << endl;
        cout << "Invalid choice! [" << *choice <<"] is not an option. Please try again." << endl;
        cout << player.getName() <<": ";
        *choice = getCharInput();
    }
    cout << endl;
}

void ScreenManager::equipWeapon(char choice, unsigned int numValue) {
    switch(choice){
            case 'e':
                cout << "Weapon equipped!" << endl << endl;
                inventory.equipWeapon(numValue-1,player);
                break;
            case 'r':
                inventory.removeItem(numValue-1);
                cout << "Weapon removed." << endl << endl;
                break;
            default: return;
        }
}

void ScreenManager::equipItem(char choice, unsigned int numValue) {
    switch(choice){
            case 'e':
                cout << "Equipped!" << endl << endl;
                inventory.equipItem(numValue-1,player);
                break;
            case 'r':
                inventory.removeItem(numValue-1);
                cout << "Item removed." << endl << endl;
                break;
            default: return;
        }
}

void ScreenManager::playerStats() {
    char choice;

    while(true) {
        cout << "------------------------------ " << player.getName() << "\'s Current Stats ------------------------------ " << endl << endl;
        cout << "Maximum Health: " << player.getMaxHealth() << endl; 
        cout << "         Magic: " << player.getMagic() << endl;
        cout << "        Attack: " << player.getAttack() << endl; 
        cout << "       Defense: " << player.getDefense() << endl; 
        cout << "         Speed: " << player.getSpeed() << endl; 
        cout << "           EXP: " << player.getExp() << endl; 
        cout << endl;
        cout << "You can increase any statistic by 5 points by spending 20 EXP." << endl;
        cout << "Enter which statistic you wish to increase (h,m,a,d,s) or enter [b] to go back to satchel: " << endl;
        cout << player.getName() <<": ";
        choice = getCharInput();

        checkPlayerStatsChoice(&choice);

        if(player.getExp() < 20) {
                cout << "You need at least 10 EXP to increase any statistic." << endl << endl;
        }
        else if(choice != 'b'){
            modPlayerStats(choice);
        }
        else{ return; }
    }
    
}

void ScreenManager::checkPlayerStatsChoice(char* choice) {
    while(*choice != 'h' && *choice != 'm' && *choice != 'a' && *choice != 'd' && *choice!= 's' && *choice != 'b') {
        cout << endl;
        cout << "Invalid choice! [" << *choice <<"] is not an option. Please try again." << endl;
        cout << player.getName() <<": ";
        *choice = getCharInput();
    }
    cout << endl;
}

void ScreenManager::modPlayerStats(char input) {
    if (input == 'H') {
        player.updateStat(60, 5);
        player.gainExp(-20);
         cout << "Permanently increased Max Health by 5 points!" << endl << endl;
    }
    else if (input == 'M') {
        player.updateStat(50, 5);
        player.gainExp(-20);
        cout << "Permanently increased Magic by 5 points!" << endl << endl;
    }
    else if (input == 'A') {
        player.updateStat(20, 5);
        player.gainExp(-20);
        cout << "Permanently increased Attack by 5 points!" << endl << endl;
    }
    else if (input == 'D') {
        player.updateStat(30, 5);
        player.gainExp(-20);
        cout << "Permanently increased Defense by 5 points!" << endl << endl;
    }
    else if (input == 'S') {
        player.updateStat(40, 5);
        player.gainExp(-20);
        cout << "Permanently increased Speed by 5 points!" << endl << endl;
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

void ScreenManager::battleMenu() {
    char choice;
    vector<int> savedPlayerStats;
    savedPlayerStats.push_back(player.getAttack());
    savedPlayerStats.push_back(player.getDefense());
    savedPlayerStats.push_back(player.getMagic());
    savedPlayerStats.push_back(player.getSpeed());

    while(true){
        cout << endl;
        cout << "Monsters block your path:" << endl << endl;
        displayEnemies();
        cout << endl;
        cout << "--------------------------------------" << endl;
        cout << "Health: [" << player.getCurrHealth() << "/" << player.getMaxHealth() << "]" << endl; 
        cout << "--------------------------------------" << endl;
        cout << "What would you like to do?" << endl << endl;
        cout << "Press [1] to attack an enemy" << endl;
        cout << "Press [2] to use an item" << endl;
        cout << "Press [b] to attempt to flee (return to previous room)" << endl << endl;
        cout << "Choose (1-3) " << player.getName() << ": ";
        choice = getCharInput();
        
        checkBattleMenuChoice(&choice);

        switch(choice){
            case '1': {
                attackMenu();
                if(player.getCurrHealth() <= 0){
                    lostScreen();
                    return;
                }
                if(map.getEnemyQuantity()==0) {
                    cout << endl; 
                    cout << "CONGRATULATIONS " << player.getName() <<"!!! You've defeated all enemies in this room!" << endl << endl << endl; 
                    player.setStats(player.getMaxHealth(), player.getCurrHealth(), savedPlayerStats.at(1), savedPlayerStats.at(0), savedPlayerStats.at(3), player.getExp(), player.getName());
                    player.setMagic(savedPlayerStats.at(2));
                    return;
                }
                break;
            }
            case '2': {
                useItem();
                break;
            }
            case 'b': {
                clearScreen();
                cout << "You are now back in the previous room." << endl;
                cout << "Hurry! Find items and weapons you need to combat the monsters in the next room...." <<  endl;
                map.fleeToPrevRoom();
                displayMap();
                player.setStats(player.getMaxHealth(), player.getCurrHealth(), savedPlayerStats.at(1), savedPlayerStats.at(0), savedPlayerStats.at(3), player.getExp(), player.getName());
                player.setMagic(savedPlayerStats.at(2));
                return;
            }
            default: { cout << "Error occurred in ScreenManager::battleMenu()."; }
        }
    }
}

void ScreenManager::checkBattleMenuChoice(char* choice) {
    while(*choice != '1' && *choice != '2' && *choice != 'b') {
        cout << endl;
        cout << "Invalid choice! [" << *choice <<"] is not an option. Please try again." << endl;
        cout << player.getName() <<": ";
        *choice = getCharInput();
    }
    cout << endl;
}

void ScreenManager::attackMenu() {
   if(map.getEnemyQuantity() == 0){
        cout << "All enemies defeated in this room. GOOD JOB, " << player.getName() << "! " << endl;
    }
    else{
        std::vector<std::string> turnOutputs;
        char enemy;
        cout << endl <<"Here are the enemies to defeat in this room:" << endl;
        displayEnemies();
        cout << endl << "Which enemy do you want to attack?" << endl;
        cout << "(Example: Press [1] for " << map.getEnemyName(0) << ") ";
        cout << player.getName() << ": ";
        enemy = getCharInput();

        checkAttackMenuChoice(&enemy);

        displayTurnOutputs("Fight Scenario",enemy);    
    }
}

void ScreenManager::checkAttackMenuChoice(char* choice) {
    int enemy = *choice - 48;
    while(0 >= enemy || enemy > map.getEnemyQuantity()) {
        cout << endl;
        cout << "Invalid choice! [" << enemy <<"] is not an option. Please try again." << endl;
        cout << player.getName() <<": ";
        cin >> enemy;
    }
    *choice = static_cast<char>(enemy);
    cout << endl;
}

void ScreenManager::displayTurnOutputs(string fromMap, int index) {
    if(fromMap == "Fight Scenario"){
        std::vector<std::string> turnOutputs = map.fightScenario(inventory, player, (index-1));
        clearScreen();
        for(unsigned int i = 0; i < turnOutputs.size(); i++) {
            cout << turnOutputs.at(i) << endl;
        }
    }

    if(fromMap == "Item Battle"){
        std::vector<std::string> turnOutputs = map.itemBattle(inventory, player, (index-1));
        for(unsigned int i = 0; i < turnOutputs.size(); i++) {
            cout << turnOutputs.at(i) << endl;
        }
    }
}

void ScreenManager::useItem(){
    std::string list = inventory.listInventory();
    int itemQuantity = inventory.numItems();
    char itemNumber;
    cout << list << endl << endl; 
                
    while(true) {
        if(itemQuantity == 0){
            cout << endl;
            cout << player.getName() << ", unfortunately you are out of items." << endl << endl;
            break;
        }
        else{
            if(itemQuantity != 0)
            cout << "Enter item number of usable item (1-" << itemQuantity << ") to use an item. " << endl;
            cout << player.getName() <<": ";
            itemNumber = getCharInput();
            checkUseItemChoice(&itemNumber);
            int choice = static_cast<int>(itemNumber);
            displayTurnOutputs("Item Battle",choice); 
            cout << endl;
            break;
            clearScreen();
        }
    }
}

void ScreenManager::checkUseItemChoice(char* choice) {
    int item = *choice - 48;
    while(0 >= item || item > inventory.numItems()) {
        cout << endl;
        cout << "Invalid choice! [" << *choice <<"] is not an option. Please try again." << endl;
        cout << player.getName() <<": ";
        cin >> item;
    }
    *choice = static_cast<char>(item);
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
    cout << "Can you find the courage to attempt to escape again?" << endl << endl;
    cout << endl << endl;
}

void ScreenManager::clearScreen() {
    for (int i = 0; i < 100; i++) {
        cout << "\n";
    }
}
