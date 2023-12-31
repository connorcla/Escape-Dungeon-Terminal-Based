#ifndef ITEMDATABASETESTS_H
#define ITEMDATABASETESTS_H

#include "gtest/gtest.h"
#include "../header/itemDatabase.h"
#include <string>

TEST(DatabaseConstructor, CreateItems) {
    ASSERT_NO_THROW(ItemDatabase allItems);
}

TEST(ReturnItemString, ReturnName0) {
    ItemDatabase allItems;
    std::string name = allItems.returnItem(0, 0);
    EXPECT_EQ(name, "Basic Sword"); 
}

TEST(ReturnItemString, ReturnName3) {
    ItemDatabase allItems;
    std::string name = allItems.returnItem(3, 0);
    EXPECT_EQ(name, "Flame Blade"); 
}

TEST(ReturnItemString, ReturnDescription0) {
    ItemDatabase allItems;
    std::string des = allItems.returnItem(0, 1);
    EXPECT_EQ(des, "A short blade that you woke up with. Looks like it can get the job done. --- Damage: 12"); 
}

TEST(ReturnItemString, ReturnDescription3) {
    ItemDatabase allItems;
    std::string des = allItems.returnItem(3, 1);
    EXPECT_EQ(des, "A short blade with fiery runes engraved. It even gives off a little light. --- Damage: 25"); 
}

TEST(ReturnItemString, ReturnProperty0) {
    ItemDatabase allItems;
    std::string prop = allItems.returnItem(0, 2);
    EXPECT_EQ(prop, "12"); 
}

TEST(ReturnItemString, ReturnProperty3) {
    ItemDatabase allItems;
    std::string prop = allItems.returnItem(3, 2);
    EXPECT_EQ(prop, "25"); 
}

TEST(ReturnItemString, ReturnID0) {
    ItemDatabase allItems;
    std::string id = allItems.returnItem(0, 3);
    EXPECT_EQ(id, "120"); 
}

TEST(ReturnItemString, ReturnID3) {
    ItemDatabase allItems;
    std::string id = allItems.returnItem(3, 3);
    EXPECT_EQ(id, "123"); 
}

#endif