#ifndef MAPTESTS_H
#define MAPTESTS_H
#include "../header/map.h"
#include "../header/player.h"//For testing FightScenaro() function
#include "gtest/gtest.h"
using namespace std;

TEST(MapTests, testConstructor){
    EXPECT_NO_THROW(Map mapTest);
}

TEST(MapTests, testGetItem) {
    srand(0);
    Map mapTest;
    
    vector<string> compareItem;
    compareItem.push_back("Health Potion III");
    compareItem.push_back("A superb red potion that restores a good portion of health. --- Heal: 80");
    compareItem.push_back("80");
    compareItem.push_back("312");

    EXPECT_EQ(compareItem, mapTest.getItemFromCurrRoom());
}

TEST(MapTests, moveToNextRoom){
    Map mapTest;
    EXPECT_NO_THROW(mapTest.moveToNextRoom());
}

TEST(MapTests, moveToNextRoomTwice){
    Map mapTest;
    mapTest.moveToNextRoom();
    EXPECT_NO_THROW(mapTest.moveToNextRoom());
}

TEST(MapTests, moveToPREVRoom){
    Map mapTest;
    mapTest.moveToNextRoom();
    EXPECT_NO_THROW(mapTest.fleeToPrevRoom());
}

TEST(MapTests, getCurrRoom_DefaultConstructor){
    Map mapTest;
    int currentRoom = mapTest.getCurrRoom();
    EXPECT_EQ(currentRoom, 0);
}

TEST(MapTests, getCurrRoom_After_MovingToNextRoom){
    Map mapTest;
    mapTest.moveToNextRoom();

    EXPECT_EQ(mapTest.getCurrRoom(),1);
}

TEST(MapTests, getCurrRoom_After_FleeingtoPevRoom){
    Map mapTest;

    //Increments 'currRoom' value by 1. From previous test, 'currRoom' value is proven to be 2 at this point.
    mapTest.moveToNextRoom();
    //Derements 'currRoom' value by 1. The 'currRoom' value should now be back to 1.
    mapTest.fleeToPrevRoom();
    
    EXPECT_EQ(mapTest.getCurrRoom(),0);
}

TEST(MapTests, getNumOfRooms){
    Map mapTest;
    EXPECT_EQ(mapTest.getNumOfRooms(),10);
}

TEST(MapTests, getRoomStatus){
    Map mapTest;
    string roomStatus = mapTest.getRoomStatus(0);
    EXPECT_EQ(roomStatus, "Start ");
}

TEST(MapTests, getEnemyQuantityGTZero){
    Map mapTest;
    EXPECT_GT(mapTest.getEnemyQuantity(),0);
}

TEST(MapTests, getEnemyQuantityLTFive){
    Map mapTest;
    EXPECT_LT(mapTest.getEnemyQuantity(),5);
}

TEST(MapTests, getEnemyCURRNTHealthStatus){
    Map map;
    EXPECT_NE(map.getEnemyCURRNTHealthStatus(0),0);
}

TEST(MapTests, getEnemyMaxHealthStatus){
    Map map;
    EXPECT_NE(map.getEnemyMAXHealthStatus(0),0);
}

TEST(MapTests, getEnemyName){
    Map map;
    EXPECT_NE(map.getEnemyName(0),"");
}

TEST(MapTests, getEnemySpeed){
    Map map;
    EXPECT_NE(map.getEnemySpeed(0),0);
}

TEST(MapTests, fightScenarioThrow){
    Map map;
    Player player;
    Inventory inventory;
    int enemyIndex = -1;

    EXPECT_ANY_THROW(map.fightScenario(inventory, player, enemyIndex));
}


TEST(MapTests, getRoomInfo) {
    Map map;
    std::string info = map.getCurrInfo();

    EXPECT_EQ(info, "You just woke up in this room. There is only a dim light from a door frame which appears to be the only way forward.");
}

//TEST(MapTests, testGetItemFromCurrRoom){}

#endif