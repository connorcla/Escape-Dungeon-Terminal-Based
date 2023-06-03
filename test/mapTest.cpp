#include "../header/map.h"
#include "gtest/gtest.h"
using namespace std;

TEST(Map_Tests, testConstructor){
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

int main(int argc, char **argv) {
::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}