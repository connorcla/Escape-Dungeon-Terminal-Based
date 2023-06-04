#include "../header/enemy.h"
#include "../header/witch.h"
#include "../header/spider.h"
#include "gtest/gtest.h"
using namespace std;

/*********** Witch Tests **********/
TEST(WitchTests, testConstructor){
    EXPECT_NO_THROW(Enemy* villan = new Witch("Witch",1,2,3,4,5,6));
}

TEST(WitchTests, getName){
    string name = "Witch";
    Enemy* villan = new Witch("Witch",1,2,3,4,5,6);

    EXPECT_EQ(villan->getName(), name);
}

TEST(WitchTests, getMaxHealth){
    int health = 20;
    Enemy* villan = new Witch("Witch",1,health,3,4,5,6);

    EXPECT_EQ(villan->getMaxHealth(), health);
}

TEST(WitchTests, getCurrHealth){
    int health = 20;
    Enemy* villan = new Witch("Witch",1,health,3,4,5,6);

    EXPECT_EQ(villan->getCurrHealth(), health);
}

TEST(WitchTests, getDefense){
    int defense = 20;
    Enemy* villan = new Witch("Witch",1,2,3,defense,5,6);

    EXPECT_EQ(villan->getDefense(), defense);
}

TEST(WitchTests, getAttack){
    int attack = 5;
    Enemy* villan = new Witch("Witch",1,2,attack,4,5,6);

    EXPECT_EQ(villan->getAttack(), attack);
}

TEST(WitchTests, getSpeed){
    int speed = 5;
    Enemy* villan = new Witch("Witch",1,2,3,4,speed,6);

    EXPECT_EQ(villan->getSpeed(), speed);
}

TEST(WitchTests, getExp){
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

/*********** Spider Tests **********/
TEST(SpiderTests, testConstructor){
    EXPECT_NO_THROW(Enemy* villan = new Spider("Spider",1,2,3,4,5));
}

TEST(SpiderTests, getName){
    string name = "Spider";
    Enemy* villan = new Spider("Spider",1,2,3,4,5);

    EXPECT_EQ(villan->getName(), name);
}

TEST(SpiderTests, getMaxHealth){
    int health = 20;
    Enemy* villan = new Spider("Spider",1,health,3,4,5);

    EXPECT_EQ(villan->getMaxHealth(), health);
}

TEST(SpiderTests, getCurrHealth){
    int health = 20;
    Enemy* villan = new Spider("Spider",1,health,3,4,5);

    EXPECT_EQ(villan->getCurrHealth(), health);
}

TEST(SpiderTests, getDefense){
    int defense = 20;
    Enemy* villan = new Spider("Spider",1,2,3,defense,5);

    EXPECT_EQ(villan->getDefense(), defense);
}

TEST(SpiderTests, getAttack){
    int attack = 5;
    Enemy* villan = new Spider("Spider",1,2,attack,4,5);

    EXPECT_EQ(villan->getAttack(), attack);
}

TEST(SpiderTests, getSpeed){
    int speed = 5;
    Enemy* villan = new Spider("Spider",1,2,3,4,speed);

    EXPECT_EQ(villan->getSpeed(), speed);
}

TEST(SpiderTests, getExp){
    int exp = 3;
    Enemy* villan = new Spider("Spider",exp,2,3,4,5);

    EXPECT_EQ(villan->getExp(), exp);
}

