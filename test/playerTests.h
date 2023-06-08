#ifndef PLAYERTESTS_H
#define PLAYERTESTS_H

#include "gtest/gtest.h"
#include "../header/player.h"
#include <string>

TEST(PlayerConstructor, CreatePlayer) {
    ASSERT_NO_THROW(Player player);
}

TEST(PlayerSetter, Magic) {
    Player player;
    player.setMagic(60);
    int magic = player.getMagic();

    EXPECT_EQ(magic, 60);
}

TEST(PlayerSetter, GainExp) {
    Player player;
    player.gainExp(20);
    int exp = player.getExp();

    EXPECT_EQ(exp, 20);
}

TEST(PlayerSetter, GainExpNegative) {
    Player player;
    player.gainExp(-20);
    int exp = player.getExp();

    EXPECT_EQ(exp, 0);
}

TEST(PlayerSetter, Name) {
    Player player;
    player.setName("Test Player");
    std::string name = player.getName();

    EXPECT_EQ(name, "Test Player");
}

TEST(PlayerUpdateStat, MaxHealth) {
    Player player;
    player.updateStat(60, 5);
    int maxHealth = player.getMaxHealth();

    EXPECT_EQ(maxHealth, 55);
}

TEST(PlayerUpdateStat, CurrHealth) {
    Player player;
    player.updateStat(10, 5);
    int currHealth = player.getCurrHealth();

    EXPECT_EQ(currHealth, 55);
}

TEST(PlayerUpdateStat, CurrHealthNegative) {
    Player player;
    player.updateStat(10, -100);
    int currHealth = player.getCurrHealth();

    EXPECT_EQ(currHealth, 0);
}

TEST(PlayerUpdateStat, Attack) {
    Player player;
    player.updateStat(20, 5);
    int attack = player.getAttack();

    EXPECT_EQ(attack, 25);
}

TEST(PlayerUpdateStat, AttackNegative) {
    Player player;
    player.updateStat(20, -100);
    int attack = player.getAttack();

    EXPECT_EQ(attack, 1);
}

TEST(PlayerUpdateStat, Defense) {
    Player player;
    player.updateStat(30, 5);
    int defense = player.getDefense();

    EXPECT_EQ(defense, 25);
}

TEST(PlayerUpdateStat, DefenseNegative) {
    Player player;
    player.updateStat(30, -100);
    int defense = player.getDefense();

    EXPECT_EQ(defense, 1);
}

TEST(PlayerUpdateStat, Speed) {
    Player player;
    player.updateStat(40, 5);
    int speed = player.getSpeed();

    EXPECT_EQ(speed, 25);
}

TEST(PlayerUpdateStat, SpeedNegative) {
    Player player;
    player.updateStat(40, -100);
    int speed = player.getSpeed();

    EXPECT_EQ(speed, 1);
}

TEST(PlayerUpdateStat, Magic) {
    Player player;
    player.updateStat(50, 5);
    int magic = player.getMagic();

    EXPECT_EQ(magic, 25);
}

TEST(PlayerUpdateStat, MagicNegative) {
    Player player;
    player.updateStat(50, -100);
    int magic = player.getMagic();

    EXPECT_EQ(magic, 1);
}

#endif