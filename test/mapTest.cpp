#include "../header/map.h"
#include "gtest/gtest.h"
using namespace std;

TEST(MapTests, testConstructor){
    EXPECT_NO_THROW(Map mapTest);
}

TEST(Map_Tests, testGetItem) {
    srand(0);
    Map mapTest;
    
    vector<string> compareItem;
    compareItem.push_back("Cloak");
    compareItem.push_back("A hooded item that conceals your presence like a thief. --- Speed: 10");
    compareItem.push_back("10");
    compareItem.push_back("241");

    EXPECT_EQ(compareItem, mapTest.getItemFromCurrRoom());
}

TEST(MapTests, testGenerateRooms){
    Map mapTest;
    EXPECT_NO_THROW(mapTest.generateRooms());
}

TEST(MapTests, testMoveToNextRoom){
    Map mapTest;
    EXPECT_NO_THROW(mapTest.moveToNextRoom());
}

TEST(MapTests, testMoveToPREVRoom){
    Map mapTest;
    EXPECT_NO_THROW(mapTest.fleeToPrevRoom());
}

TEST(MapTests, testGetCurrRoom_DefaultConstructor){
    Map mapTest;
    int currentRoom = mapTest.getCurrRoom();
    EXPECT_EQ(currentRoom, 1);
}

TEST(MapTests, getCurrRoom_After_MovingToNextRoom){
    Map mapTest;
    mapTest.moveToNextRoom();

    EXPECT_EQ(mapTest.getCurrRoom(),2);
}

TEST(MapTests, getCurrRoom_After_FleeingtoPevRoom){
    Map mapTest;

    //Increments 'currRoom' value by 1. From previous test, 'currRoom' value is proven to be 2 at this point.
    mapTest.moveToNextRoom();
    //Derements 'currRoom' value by 1. The 'currRoom' value should now be back to 1.
    mapTest.fleeToPrevRoom();
    
    EXPECT_EQ(mapTest.getCurrRoom(),1);
}

TEST(MapTests, testNumOfRooms){
    Map mapTest;
    EXPECT_EQ(mapTest.getNumOfRooms(),10);
}

TEST(MapTests, testGetRoomStatus){
    Map mapTest;
    string roomStatus = mapTest.getRoomStatus(1);
    EXPECT_EQ(roomStatus, "Here ");
}

//TEST(MapTests, testGetItemFromCurrRoom){}

int main(int argc, char **argv) {
::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}