#include <iostream>
#include <cstdlib>
#include <ctime>
//#include "header/map.h"
#include "header/screenManager.h"

int main () {
    srand(time(0));
    ScreenManager screen;
    screen.setUp();
    
    return 0;
}