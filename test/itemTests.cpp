#include "gtest/gtest.h"
#include "../header/item.h"
#include "../header/itemDatabase.h"
#include <string>

TEST(ItemConstructor, DefaultItems) {
    ASSERT_NO_THROW(Item testItem);
}

TEST(ItemConstructor, NonDefaultItems) {
    ItemDatabase allItems;
    ASSERT_NO_THROW(Item testItem(allItems.returnItem(0,0), allItems.returnItem(0,1), stoi(allItems.returnItem(0,2)), stoi(allItems.returnItem(0,3))));
}

TEST(ReturnItemName, ReturnName0) {
    ItemDatabase allItems;
    Item testItem(allItems.returnItem(0,0), allItems.returnItem(0,1), stoi(allItems.returnItem(0,2)), stoi(allItems.returnItem(0,3)));
    std::string name = testItem.getName();
    EXPECT_EQ(name, "Health Potion I"); 
}

TEST(ReturnItemName, ReturnName3) {
    ItemDatabase allItems;
    Item testItem(allItems.returnItem(3,0), allItems.returnItem(3,1), stoi(allItems.returnItem(3,2)), stoi(allItems.returnItem(3,3)));
    std::string name = testItem.getName();
    EXPECT_EQ(name, "Stone Sword"); 
}

TEST(ReturnItemDescription, ReturnDescription0) {
    ItemDatabase allItems;
    Item testItem(allItems.returnItem(0,0), allItems.returnItem(0,1), stoi(allItems.returnItem(0,2)), stoi(allItems.returnItem(0,3)));
    std::string des = testItem.displayDescription();
    EXPECT_EQ(des, "A simple red potion that restores some health."); 
}

TEST(ReturnItemDescription, ReturnDescription3) {
    ItemDatabase allItems;
    Item testItem(allItems.returnItem(3,0), allItems.returnItem(3,1), stoi(allItems.returnItem(3,2)), stoi(allItems.returnItem(3,3)));
    std::string des = testItem.displayDescription();
    EXPECT_EQ(des, "A short blade made out of stone. It has worn down over time."); 
}

TEST(ReturnItemProp, ReturnProperty0) {
    ItemDatabase allItems;
    Item testItem(allItems.returnItem(0,0), allItems.returnItem(0,1), stoi(allItems.returnItem(0,2)), stoi(allItems.returnItem(0,3)));
    int prop = testItem.getProperty();
    EXPECT_EQ(prop, 10); 
}

TEST(ReturnItemProp, ReturnProperty3) {
    ItemDatabase allItems;
    Item testItem(allItems.returnItem(3,0), allItems.returnItem(3,1), stoi(allItems.returnItem(3,2)), stoi(allItems.returnItem(3,3)));
    int prop = testItem.getProperty();
    EXPECT_EQ(prop, 10); 
}

TEST(ReturnItemID, ReturnID0) {
    ItemDatabase allItems;
    Item testItem(allItems.returnItem(0,0), allItems.returnItem(0,1), stoi(allItems.returnItem(0,2)), stoi(allItems.returnItem(0,3)));
    int id = testItem.getID();
    EXPECT_EQ(id, 0); 
}

TEST(ReturnItemID, ReturnID3) {
    ItemDatabase allItems;
    Item testItem(allItems.returnItem(3,0), allItems.returnItem(3,1), stoi(allItems.returnItem(3,2)), stoi(allItems.returnItem(3,3)));
    int id = testItem.getID();
    EXPECT_EQ(id, 3); 
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}