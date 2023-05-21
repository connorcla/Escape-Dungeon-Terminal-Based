#include <iostream>
#include "header/map.h"

int main () {
    Map mapTest;
    int getCurrLocation;

    getCurrLocation = mapTest.getCurrRoom();
    cout<<"Player is currently at Level "<<getCurrLocation<<endl;
    
    return 0;
}