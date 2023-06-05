#ifndef ITEMTESTS_H
#define ITEMTESTS_H
#include "../header/inventory.h"
#include "../header/item.h"
#include "../header/itemDatabase.h"
#include "../header/player.h"
#include <string>
#include "gtest/gtest.h"

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
    EXPECT_EQ(name, "Basic Sword"); 
}

TEST(ReturnItemName, ReturnName3) {
    ItemDatabase allItems;
    Item testItem(allItems.returnItem(3,0), allItems.returnItem(3,1), stoi(allItems.returnItem(3,2)), stoi(allItems.returnItem(3,3)));
    std::string name = testItem.getName();
    EXPECT_EQ(name, "Flame Blade"); 
}

TEST(ReturnItemDescription, ReturnDescription0) {
    ItemDatabase allItems;
    Item testItem(allItems.returnItem(0,0), allItems.returnItem(0,1), stoi(allItems.returnItem(0,2)), stoi(allItems.returnItem(0,3)));
    std::string des = testItem.displayDescription();
    EXPECT_EQ(des, "A short blade that you woke up with. Looks like it can get the job done. --- Damage: 12"); 
}

TEST(ReturnItemDescription, ReturnDescription3) {
    ItemDatabase allItems;
    Item testItem(allItems.returnItem(3,0), allItems.returnItem(3,1), stoi(allItems.returnItem(3,2)), stoi(allItems.returnItem(3,3)));
    std::string des = testItem.displayDescription();
    EXPECT_EQ(des, "A short blade with fiery runes engraved. It even gives off a little light. --- Damage: 25"); 
}

TEST(ReturnItemProp, ReturnProperty0) {
    ItemDatabase allItems;
    Item testItem(allItems.returnItem(0,0), allItems.returnItem(0,1), stoi(allItems.returnItem(0,2)), stoi(allItems.returnItem(0,3)));
    int prop = testItem.getProperty();
    EXPECT_EQ(prop, 12); 
}

TEST(ReturnItemProp, ReturnProperty3) {
    ItemDatabase allItems;
    Item testItem(allItems.returnItem(3,0), allItems.returnItem(3,1), stoi(allItems.returnItem(3,2)), stoi(allItems.returnItem(3,3)));
    int prop = testItem.getProperty();
    EXPECT_EQ(prop, 25); 
}

TEST(ReturnItemID, ReturnID0) {
    ItemDatabase allItems;
    Item testItem(allItems.returnItem(0,0), allItems.returnItem(0,1), stoi(allItems.returnItem(0,2)), stoi(allItems.returnItem(0,3)));
    int id = testItem.getID();
    EXPECT_EQ(id, 120); 
}

TEST(ReturnItemID, ReturnID3) {
    ItemDatabase allItems;
    Item testItem(allItems.returnItem(3,0), allItems.returnItem(3,1), stoi(allItems.returnItem(3,2)), stoi(allItems.returnItem(3,3)));
    int id = testItem.getID();
    EXPECT_EQ(id, 123); 
}

#endif