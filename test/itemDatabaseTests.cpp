#include "gtest/gtest.h"
#include "../header/itemDatabase.h"
#include <string>

TEST(DatabaseConstructor, CreateItems) {
    ASSERT_NO_THROW(ItemDatabase allItems);
}

TEST(ReturnItemString, ReturnName0) {
    ItemDatabase allItems;
    std::string name = allItems.returnItem(0, 0);
    EXPECT_EQ(name, "Health Potion I"); 
}

TEST(ReturnItemString, ReturnName3) {
    ItemDatabase allItems;
    std::string name = allItems.returnItem(3, 0);
    EXPECT_EQ(name, "Stone Sword"); 
}

TEST(ReturnItemString, ReturnDescription0) {
    ItemDatabase allItems;
    std::string des = allItems.returnItem(0, 1);
    EXPECT_EQ(des, "A simple red potion that restores some health."); 
}

TEST(ReturnItemString, ReturnDescription3) {
    ItemDatabase allItems;
    std::string des = allItems.returnItem(3, 1);
    EXPECT_EQ(des, "A short blade made out of stone. It has worn down over time."); 
}

TEST(ReturnItemString, ReturnProperty0) {
    ItemDatabase allItems;
    std::string prop = allItems.returnItem(0, 2);
    EXPECT_EQ(prop, "10"); 
}

TEST(ReturnItemString, ReturnProperty3) {
    ItemDatabase allItems;
    std::string prop = allItems.returnItem(3, 2);
    EXPECT_EQ(prop, "10"); 
}

TEST(ReturnItemString, ReturnID0) {
    ItemDatabase allItems;
    std::string id = allItems.returnItem(0, 3);
    EXPECT_EQ(id, "0"); 
}

TEST(ReturnItemString, ReturnID3) {
    ItemDatabase allItems;
    std::string id = allItems.returnItem(3, 3);
    EXPECT_EQ(id, "3"); 
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}