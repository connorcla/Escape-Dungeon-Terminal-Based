#include "../header/enemy.h"
#include "../header/witch.h"
#include "gtest/gtest.h"
using namespace std;

TEST(EnemyTests, testConstructor){
    EXPECT_NO_THROW(Enemy* villan = new Witch());
}

TEST(EnemyTests, getName){
    string name = "Witch";
    Enemy* villan = new Witch("Witch",1,2,3,4,5,6);

    EXPECT_EQ(villan->getName(), name);
}

TEST(EnemyTests, getMaxHealth){
    int health = 20;
    Enemy* villan = new Witch("Witch",1,health,3,4,5,6);

    EXPECT_EQ(villan->getMaxHealth(), health);
}

TEST(EnemyTests, getCurrHealth){
    int health = 20;
    Enemy* villan = new Witch("Witch",1,health,3,4,5,6);

    EXPECT_EQ(villan->getCurrHealth(), health);
}

TEST(EnemyTests, getDefense){
    int defense = 20;
    Enemy* villan = new Witch("Witch",1,2,3,defense,5,6);

    EXPECT_EQ(villan->getDefense(), defense);
}

TEST(EnemyTests, getAttack){
    int attack = 5;
    Enemy* villan = new Witch("Witch",1,2,attack,4,5,6);

    EXPECT_EQ(villan->getAttack(), attack);
}

TEST(EnemyTests, getSpeed){
    int speed = 5;
    Enemy* villan = new Witch("Witch",1,2,3,4,speed,6);

    EXPECT_EQ(villan->getSpeed(), speed);
}

TEST(EnemyTests, getExp){
    int exp = 3;
    Enemy* villan = new Witch("Witch",exp,2,3,4,5,6);

    EXPECT_EQ(villan->getExp(), exp);
}

/*
TEST(EnemyTests, getMagic){
    int magic = 2;
    Enemy* villan = new Witch("Witch",1,2,3,4,5,magic);

    EXPECT_EQ(villan->getMagic(), magic);
}
*/
