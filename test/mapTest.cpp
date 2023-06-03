#include "../header/map.h"
#include "gtest/gtest.h"
//#include <string>
using namespace std;

TEST(MapTests, testConstructor){
    EXPECT_NO_THROW(Map mapTest);
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

TEST(MapTests, testGetCurrRoom){
    Map mapTest;
    int currentRoom = mapTest.getCurrRoom();
    EXPECT_EQ(currentRoom, 1);
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