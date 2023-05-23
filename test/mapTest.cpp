#include "../header/map.h"
#include "gtest/gtest.h"
using namespace std;

TEST(Map_Tests, testConstructor){
    EXPECT_NO_THROW(Map mapTest);
}

TEST(Map_Tests, testMoveToNextRoom){
    Map mapTest;
    mapTest.moveRooms(1);
    EXPECT_EQ(mapTest.getCurrRoom(),2);
}

TEST(Map_Tests, testMoveToPREVRoom){
    Map mapTest;
    mapTest.moveRooms(-1);
    EXPECT_EQ(mapTest.getCurrRoom(),0);
}

int main(int argc, char **argv) {
::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}