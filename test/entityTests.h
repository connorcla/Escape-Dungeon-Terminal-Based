#ifndef ENTITYTESTS_H
#define ENTITYTESTS_H

#include "gtest/gtest.h"
#include "../header/entity.h"
#include <string>

TEST(EntityConstructor, CreateEntity) {
    ASSERT_NO_THROW(Entity entity);
}

TEST(EntityGetter, MaxHealth) {
    Entity entity;
    entity.setStats(10, 20, 30, 40, 50, 60, "TestEntity");
    int maxHealth = entity.getMaxHealth();

    EXPECT_EQ(maxHealth, 10);
}

TEST(EntityGetter, CurrHealth) {
    Entity entity;
    entity.setStats(10, 20, 30, 40, 50, 60, "TestEntity");
    int currHealth = entity.getCurrHealth();

    EXPECT_EQ(currHealth, 20);
}

TEST(EntityGetter, Defense) {
    Entity entity;
    entity.setStats(10, 20, 30, 40, 50, 60, "TestEntity");
    int defense = entity.getDefense();

    EXPECT_EQ(defense, 30);
}

TEST(EntityGetter, Attack) {
    Entity entity;
    entity.setStats(10, 20, 30, 40, 50, 60, "TestEntity");
    int attack = entity.getAttack();

    EXPECT_EQ(attack, 40);
}

TEST(EntityGetter, Speed) {
    Entity entity;
    entity.setStats(10, 20, 30, 40, 50, 60, "TestEntity");
    int speed = entity.getSpeed();

    EXPECT_EQ(speed, 50);
}

TEST(EntityGetter, Exp) {
    Entity entity;
    entity.setStats(10, 20, 30, 40, 50, 60, "TestEntity");
    int exp = entity.getExp();

    EXPECT_EQ(exp, 60);
}

TEST(EntityGetter, Name) {
    Entity entity;
    entity.setStats(10, 20, 30, 40, 50, 60, "TestEntity");
    std::string name = entity.getName();

    EXPECT_EQ(name, "TestEntity");
}

#endif