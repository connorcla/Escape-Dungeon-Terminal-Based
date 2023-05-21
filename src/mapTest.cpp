#include "../header/map.h"
#include "gtest/gtest.h"
using namespace std;

TEST(ConstructorTest, testDefault){
    EXPECT_NO_THROW(Map mapTest);
}

TEST( ){

}

int main(int argc, char **argv) {
::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}