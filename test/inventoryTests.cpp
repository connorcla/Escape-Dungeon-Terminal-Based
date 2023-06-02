#include "gtest/gtest.h"
#include "../header/inventory.h"
#include "../header/itemDatabase.h"
#include "../header/item.h"
#include "../header/weapon.h"
#include "../header/equip.h"
#include "../header/usable.h"
#include <string>
#include <vector>

TEST(InventoryConstructor, InventoryDefault) {
    ASSERT_NO_THROW(Inventory inv);
}

TEST(InventoryAddItem, Add2Items)  {
    ItemDatabase allItems;
    Inventory inv;
    inv.addItem(allItems.returnItem(0,0), allItems.returnItem(0,1), allItems.returnItem(0,2), allItems.returnItem(0,3));
    inv.addItem(allItems.returnItem(5,0), allItems.returnItem(5,1), allItems.returnItem(5,2), allItems.returnItem(5,3));

    int verifySize = inv.numItems();
    EXPECT_EQ(verifySize, 2);
}

TEST(InventoryAddItem, Add5Items)  {
    ItemDatabase allItems;
    Inventory inv;
    inv.addItem(allItems.returnItem(0,0), allItems.returnItem(0,1), allItems.returnItem(0,2), allItems.returnItem(0,3));
    inv.addItem(allItems.returnItem(1,0), allItems.returnItem(1,1), allItems.returnItem(1,2), allItems.returnItem(1,3));
    inv.addItem(allItems.returnItem(2,0), allItems.returnItem(2,1), allItems.returnItem(2,2), allItems.returnItem(2,3));
    inv.addItem(allItems.returnItem(3,0), allItems.returnItem(3,1), allItems.returnItem(3,2), allItems.returnItem(3,3));
    inv.addItem(allItems.returnItem(4,0), allItems.returnItem(4,1), allItems.returnItem(4,2), allItems.returnItem(4,3));

    int verifySize = inv.numItems();
    EXPECT_EQ(verifySize, 5);
}

TEST(InventoryRemoveItem, Add2_Remove2)  {
    ItemDatabase allItems;
    Inventory inv;
    inv.addItem(allItems.returnItem(0,0), allItems.returnItem(0,1), allItems.returnItem(0,2), allItems.returnItem(0,3));
    inv.addItem(allItems.returnItem(5,0), allItems.returnItem(5,1), allItems.returnItem(5,2), allItems.returnItem(5,3));

    inv.removeItem(1);
    inv.removeItem(0);

    int verifySize = inv.numItems();
    EXPECT_EQ(verifySize, 0);
}

TEST(InventoryRemoveItem, Add5_Remove3)  {
    ItemDatabase allItems;
    Inventory inv;
    inv.addItem(allItems.returnItem(0,0), allItems.returnItem(0,1), allItems.returnItem(0,2), allItems.returnItem(0,3));
    inv.addItem(allItems.returnItem(1,0), allItems.returnItem(1,1), allItems.returnItem(1,2), allItems.returnItem(1,3));
    inv.addItem(allItems.returnItem(2,0), allItems.returnItem(2,1), allItems.returnItem(2,2), allItems.returnItem(2,3));
    inv.addItem(allItems.returnItem(3,0), allItems.returnItem(3,1), allItems.returnItem(3,2), allItems.returnItem(3,3));
    inv.addItem(allItems.returnItem(4,0), allItems.returnItem(4,1), allItems.returnItem(4,2), allItems.returnItem(4,3));

    inv.removeItem(0);
    inv.removeItem(0);
    inv.removeItem(0);

    int verifySize = inv.numItems();
    EXPECT_EQ(verifySize, 2);
}

TEST(InventoryRemoveItem, RemoveOutofRange)  {
    ItemDatabase allItems;
    Inventory inv;
    inv.addItem(allItems.returnItem(0,0), allItems.returnItem(0,1), allItems.returnItem(0,2), allItems.returnItem(0,3));
    inv.addItem(allItems.returnItem(1,0), allItems.returnItem(1,1), allItems.returnItem(1,2), allItems.returnItem(1,3));

    inv.removeItem(0);
    EXPECT_ANY_THROW(inv.removeItem(1));
}

TEST(InventoryReturnItem, ReturnOutOf2)  {
    ItemDatabase allItems;
    Inventory inv;
    inv.addItem(allItems.returnItem(0,0), allItems.returnItem(0,1), allItems.returnItem(0,2), allItems.returnItem(0,3));
    inv.addItem(allItems.returnItem(5,0), allItems.returnItem(5,1), allItems.returnItem(5,2), allItems.returnItem(5,3));

    Item* returned = inv.returnItem(1);
    std::string returnedName = returned->getName();
    EXPECT_EQ(returnedName, "Boxing Gloves");
}

TEST(InventoryReturnItem, ReturnOutOf5)  {
    ItemDatabase allItems;
    Inventory inv;
    inv.addItem(allItems.returnItem(0,0), allItems.returnItem(0,1), allItems.returnItem(0,2), allItems.returnItem(0,3));
    inv.addItem(allItems.returnItem(1,0), allItems.returnItem(1,1), allItems.returnItem(1,2), allItems.returnItem(1,3));
    inv.addItem(allItems.returnItem(2,0), allItems.returnItem(2,1), allItems.returnItem(2,2), allItems.returnItem(2,3));
    inv.addItem(allItems.returnItem(3,0), allItems.returnItem(3,1), allItems.returnItem(3,2), allItems.returnItem(3,3));
    inv.addItem(allItems.returnItem(4,0), allItems.returnItem(4,1), allItems.returnItem(4,2), allItems.returnItem(4,3));

    Item* returned = inv.returnItem(2);
    std::string returnedName = returned->getName();
    EXPECT_EQ(returnedName, "Iron Sword");
}

TEST(InventoryReturnItem, ReturnOutOfRange)  {
    ItemDatabase allItems;
    Inventory inv;
    inv.addItem(allItems.returnItem(0,0), allItems.returnItem(0,1), allItems.returnItem(0,2), allItems.returnItem(0,3));
    inv.addItem(allItems.returnItem(5,0), allItems.returnItem(5,1), allItems.returnItem(5,2), allItems.returnItem(5,3));

    EXPECT_ANY_THROW(inv.returnItem(2));
}

TEST(InventoryDisplayItem, DisplayOutOf2)  {
    ItemDatabase allItems;
    Inventory inv;
    inv.addItem(allItems.returnItem(0,0), allItems.returnItem(0,1), allItems.returnItem(0,2), allItems.returnItem(0,3));
    inv.addItem(allItems.returnItem(5,0), allItems.returnItem(5,1), allItems.returnItem(5,2), allItems.returnItem(5,3));

    std::string display = inv.displayItem(1);
    EXPECT_EQ(display, "Weapon: Boxing Gloves --- For those wanting to get personal with their opponents. --- Attack: 15");
}

TEST(InventoryDisplayItem, DisplayOutOf5)  {
    ItemDatabase allItems;
    Inventory inv;
    inv.addItem(allItems.returnItem(0,0), allItems.returnItem(0,1), allItems.returnItem(0,2), allItems.returnItem(0,3));
    inv.addItem(allItems.returnItem(1,0), allItems.returnItem(1,1), allItems.returnItem(1,2), allItems.returnItem(1,3));
    inv.addItem(allItems.returnItem(2,0), allItems.returnItem(2,1), allItems.returnItem(2,2), allItems.returnItem(2,3));
    inv.addItem(allItems.returnItem(3,0), allItems.returnItem(3,1), allItems.returnItem(3,2), allItems.returnItem(3,3));
    inv.addItem(allItems.returnItem(4,0), allItems.returnItem(4,1), allItems.returnItem(4,2), allItems.returnItem(4,3));

    std::string display = inv.displayItem(2);
    EXPECT_EQ(display, "Weapon: Iron Sword --- A short blade made of cold iron. A little dull but can cut through a lot. --- Damage: 18");
}

TEST(InventoryDisplayItem, DisplayOutOfRange)  {
    ItemDatabase allItems;
    Inventory inv;
    inv.addItem(allItems.returnItem(0,0), allItems.returnItem(0,1), allItems.returnItem(0,2), allItems.returnItem(0,3));
    inv.addItem(allItems.returnItem(1,0), allItems.returnItem(1,1), allItems.returnItem(1,2), allItems.returnItem(1,3));

    EXPECT_ANY_THROW(inv.displayItem(2));
}

TEST(InventoryList, List2)  {
    ItemDatabase allItems;
    Inventory inv;
    inv.addItem(allItems.returnItem(0,0), allItems.returnItem(0,1), allItems.returnItem(0,2), allItems.returnItem(0,3));
    inv.addItem(allItems.returnItem(5,0), allItems.returnItem(5,1), allItems.returnItem(5,2), allItems.returnItem(5,3));

    std::string list = inv.listInventory();
    EXPECT_EQ(list, "(1)Basic Sword,  (2)Boxing Gloves");
}

TEST(InventoryList, List6)  {
    ItemDatabase allItems;
    Inventory inv;
    inv.addItem(allItems.returnItem(0,0), allItems.returnItem(0,1), allItems.returnItem(0,2), allItems.returnItem(0,3));
    inv.addItem(allItems.returnItem(1,0), allItems.returnItem(1,1), allItems.returnItem(1,2), allItems.returnItem(1,3));
    inv.addItem(allItems.returnItem(2,0), allItems.returnItem(2,1), allItems.returnItem(2,2), allItems.returnItem(2,3));
    inv.addItem(allItems.returnItem(3,0), allItems.returnItem(3,1), allItems.returnItem(3,2), allItems.returnItem(3,3));
    inv.addItem(allItems.returnItem(4,0), allItems.returnItem(4,1), allItems.returnItem(4,2), allItems.returnItem(4,3));
    inv.addItem(allItems.returnItem(5,0), allItems.returnItem(5,1), allItems.returnItem(5,2), allItems.returnItem(5,3));

    std::string list = inv.listInventory();
    EXPECT_EQ(list, "(1)Basic Sword,  (2)Stone Sword,  (3)Iron Sword,  (4)Flame Blade,  (5)Musket,  \n(6)Boxing Gloves");
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}