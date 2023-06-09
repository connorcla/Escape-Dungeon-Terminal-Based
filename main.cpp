#include <iostream>
#include <cstdlib>
#include <ctime>
#include "header/screenManager.h"

void gameStartManager(bool*);

int main () {
    srand(time(0));
    bool playAgain = false;

    do{
        gameStartManager(&playAgain);
    }while(playAgain);
    
    return 0;
}

void gameStartManager(bool* playAgain) {
    ScreenManager screen;
    screen.setUp();

    char choice;
    cout << "Would you like to play again?" << endl;
    cout << "\t Press [1] to play again" << endl;
    cout << "\t Press [2] to quit game" << endl;
    cout << ">Enter here: ";
    cin >> choice;

    while(choice != '1' && choice != '2'){
        cout <<  "Invalid input! " << choice << " is not an option. Please try again." << endl;
        cin >> choice;
    }
        
    if(choice == '1'){
        *playAgain = true;
        cin.clear();
        cin.ignore();
    }
    else{
        *playAgain = false;
        cout << endl << endl;
        cout << "Come back soon!";
        cout << endl << endl;
    }
}