#ifndef INVENTORYTESTS_H
#define INVENTORYTESTS_H

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
    inv.addItem(allItems.returnItem(14,0), allItems.returnItem(14,1), allItems.returnItem(14,2), allItems.returnItem(14,3));
    inv.addItem(allItems.returnItem(3,0), allItems.returnItem(3,1), allItems.returnItem(3,2), allItems.returnItem(3,3));
    inv.addItem(allItems.returnItem(4,0), allItems.returnItem(4,1), allItems.returnItem(4,2), allItems.returnItem(4,3));

    std::string display = inv.displayItem(1);
    EXPECT_EQ(display, "Equip: Dragon Force --- Take Bal\'s powers, bal!. --- Attack: 25");
}

TEST(InventoryDisplayItem, DisplayOutOf1)  {
    ItemDatabase allItems;
    Inventory inv;
    inv.addItem(allItems.returnItem(34,0), allItems.returnItem(34,1), allItems.returnItem(34,2), allItems.returnItem(34,3));

    std::string display = inv.displayItem(0);
    EXPECT_EQ(display, "Usable: Dog --- A simple companion to cure all those worries. --- Heal: 70");
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
    inv.addItem(allItems.returnItem(34,0), allItems.returnItem(34,1), allItems.returnItem(34,2), allItems.returnItem(34,3));

    std::string list = inv.listInventory();
    EXPECT_EQ(list, "(1)Basic Sword,  (2)Dog");
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
    EXPECT_EQ(list, "(1)Basic Sword,  (2)Boxing Gloves,  (3)Flame Blade,  (4)Iron Sword,  (5)Musket,  \n(6)Stone Sword");
}

TEST(InventoryList, List10)  {
    ItemDatabase allItems;
    Inventory inv;
    inv.addItem(allItems.returnItem(0,0), allItems.returnItem(0,1), allItems.returnItem(0,2), allItems.returnItem(0,3));
    inv.addItem(allItems.returnItem(1,0), allItems.returnItem(1,1), allItems.returnItem(1,2), allItems.returnItem(1,3));
    inv.addItem(allItems.returnItem(2,0), allItems.returnItem(2,1), allItems.returnItem(2,2), allItems.returnItem(2,3));
    inv.addItem(allItems.returnItem(3,0), allItems.returnItem(3,1), allItems.returnItem(3,2), allItems.returnItem(3,3));
    inv.addItem(allItems.returnItem(4,0), allItems.returnItem(4,1), allItems.returnItem(4,2), allItems.returnItem(4,3));
    inv.addItem(allItems.returnItem(5,0), allItems.returnItem(5,1), allItems.returnItem(5,2), allItems.returnItem(5,3));
    inv.addItem(allItems.returnItem(6,0), allItems.returnItem(6,1), allItems.returnItem(6,2), allItems.returnItem(6,3));
    inv.addItem(allItems.returnItem(7,0), allItems.returnItem(7,1), allItems.returnItem(7,2), allItems.returnItem(7,3));
    inv.addItem(allItems.returnItem(8,0), allItems.returnItem(8,1), allItems.returnItem(8,2), allItems.returnItem(8,3));
    inv.addItem(allItems.returnItem(9,0), allItems.returnItem(9,1), allItems.returnItem(9,2), allItems.returnItem(9,3));

    std::string list = inv.listInventory();
    EXPECT_EQ(list, "(1)Basic Sword,  (2)Boxing Gloves,  (3)Broken Sword,  (4)Electric Blade,  (5)Flame Blade,  \n(6)Iron Sword,  (7)Musket,  (8)Stick,  (9)Stone Sword,  (10)Sword from Stone");
}

TEST(InventoryList, List0)  {
    ItemDatabase allItems;
    Inventory inv;

    std::string list = inv.listInventory();
    EXPECT_EQ(list, "There are no items in your inventory.");
}

TEST(InventoryEquip, Equip2) {
    ItemDatabase allItems;
    Inventory inv;
    Player player;
    inv.addItem(allItems.returnItem(14,0), allItems.returnItem(14,1), allItems.returnItem(14,2), allItems.returnItem(14,3));
    inv.addItem(allItems.returnItem(15,0), allItems.returnItem(15,1), allItems.returnItem(15,2), allItems.returnItem(15,3));
    inv.addItem(allItems.returnItem(16,0), allItems.returnItem(16,1), allItems.returnItem(16,2), allItems.returnItem(16,3));
    inv.addItem(allItems.returnItem(17,0), allItems.returnItem(17,1), allItems.returnItem(17,2), allItems.returnItem(17,3));
    inv.addItem(allItems.returnItem(18,0), allItems.returnItem(18,1), allItems.returnItem(18,2), allItems.returnItem(18,3));
    inv.addItem(allItems.returnItem(19,0), allItems.returnItem(19,1), allItems.returnItem(19,2), allItems.returnItem(19,3));

    inv.equipItem(2, player);
    inv.equipItem(2, player);

    EXPECT_EQ(inv.outputEquipped(), "| Dragon Force |     | Iron Chainmail |     | Empty Slot 3 |     | Empty Slot 4 |     | Empty Slot 5 |     ");
}

TEST(InventoryEquip, Equip6) {
    ItemDatabase allItems;
    Inventory inv;
    Player player;
    inv.addItem(allItems.returnItem(14,0), allItems.returnItem(14,1), allItems.returnItem(14,2), allItems.returnItem(14,3));
    inv.addItem(allItems.returnItem(15,0), allItems.returnItem(15,1), allItems.returnItem(15,2), allItems.returnItem(15,3));
    inv.addItem(allItems.returnItem(16,0), allItems.returnItem(16,1), allItems.returnItem(16,2), allItems.returnItem(16,3));
    inv.addItem(allItems.returnItem(17,0), allItems.returnItem(17,1), allItems.returnItem(17,2), allItems.returnItem(17,3));
    inv.addItem(allItems.returnItem(18,0), allItems.returnItem(18,1), allItems.returnItem(18,2), allItems.returnItem(18,3));
    inv.addItem(allItems.returnItem(19,0), allItems.returnItem(19,1), allItems.returnItem(19,2), allItems.returnItem(19,3));

    inv.equipItem(0, player);
    inv.equipItem(0, player);
    inv.equipItem(0, player);
    inv.equipItem(0, player);
    inv.equipItem(0, player);
    inv.equipItem(0, player);

    EXPECT_EQ(inv.outputEquipped(), "| Cursed Armor |     | Dragon Force |     | Iron Chainmail |     | Leather Armor |     | Red Scarf |     ");
}

TEST(InventoryEquip, Weapon0) {
    ItemDatabase allItems;
    Inventory inv;
    Player player;
    inv.addItem(allItems.returnItem(0,0), allItems.returnItem(0,1), allItems.returnItem(0,2), allItems.returnItem(0,3));
    inv.addItem(allItems.returnItem(1,0), allItems.returnItem(1,1), allItems.returnItem(1,2), allItems.returnItem(1,3));

    EXPECT_EQ(inv.outputWeapon(), "| Empty Weapon Slot |");
}

TEST(InventoryEquip, Weapon1) {
    ItemDatabase allItems;
    Inventory inv;
    Player player;
    inv.addItem(allItems.returnItem(0,0), allItems.returnItem(0,1), allItems.returnItem(0,2), allItems.returnItem(0,3));
    inv.addItem(allItems.returnItem(1,0), allItems.returnItem(1,1), allItems.returnItem(1,2), allItems.returnItem(1,3));

    inv.equipWeapon(0, player);

    EXPECT_EQ(inv.outputWeapon(), "| Basic Sword |");
}

TEST(InventoryEquip, Weapon2) {
    ItemDatabase allItems;
    Inventory inv;
    Player player;
    inv.addItem(allItems.returnItem(0,0), allItems.returnItem(0,1), allItems.returnItem(0,2), allItems.returnItem(0,3));
    inv.addItem(allItems.returnItem(1,0), allItems.returnItem(1,1), allItems.returnItem(1,2), allItems.returnItem(1,3));

    inv.equipWeapon(0, player);
    inv.equipWeapon(0, player);

    EXPECT_EQ(inv.outputWeapon(), "| Stone Sword |");
}

TEST(InventoryUse, IncreaseAttack) {
    ItemDatabase allItems;
    Inventory inv;
    Player player;
    inv.addItem(allItems.returnItem(39,0), allItems.returnItem(39,1), allItems.returnItem(39,2), allItems.returnItem(39,3));

    inv.returnItem(0)->incrStat(player);

    EXPECT_EQ(player.getAttack(), 50);
}

TEST(InventoryUse, DecreaseAttack) {
    ItemDatabase allItems;
    Inventory inv;
    Player player;
    inv.addItem(allItems.returnItem(39,0), allItems.returnItem(39,1), allItems.returnItem(39,2), allItems.returnItem(39,3));

    inv.returnItem(0)->decrStat(player);

    EXPECT_EQ(player.getAttack(), 1);
}

#endif