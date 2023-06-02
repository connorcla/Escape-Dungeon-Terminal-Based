#include "../header/room.h"
#include "gtest/gtest.h"
using namespace std;

TEST(Room_Tests, testConstructor){
    EXPECT_NO_THROW(Room roomTest(1));
}


TEST(Room_Tests, getItem) {
    srand(0);
    Room room(2);

    vector<string> compareItem;
    compareItem.push_back("Cloak");
    compareItem.push_back("A hooded item that conceals your presence like a thief. --- Speed: 10");
    compareItem.push_back("10");
    compareItem.push_back("241");

    EXPECT_EQ(compareItem, room.getItem());
}


