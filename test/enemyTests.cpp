#include "../header/enemy.h"
#include "../header/witch.h"
#include "../header/spider.h"
#include "../header/golem.h"
#include "../header/skeleton.h"
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


/********** Golem Tests ***********/
TEST(GolemTests, testConstructor){
    EXPECT_NO_THROW(Enemy* villan = new Golem("Golem",1,2,3,4,5));
}

TEST(GolemTests, getName){
    string name = "Golem";
    Enemy* villan = new Golem("Golem",1,2,3,4,5);

    EXPECT_EQ(villan->getName(), name);
}

TEST(GolemTests, getMaxHealth){
    int health = 20;
    Enemy* villan = new Golem("Golem",1,health,3,4,5);

    EXPECT_EQ(villan->getMaxHealth(), health);
}

TEST(GolemTests, getCurrHealth){
    int health = 20;
    Enemy* villan = new Golem("Golem",1,health,3,4,5);

    EXPECT_EQ(villan->getCurrHealth(), health);
}

TEST(GolemTests, getDefense){
    int defense = 20;
    Enemy* villan = new Golem("Golem",1,2,3,defense,5);

    EXPECT_EQ(villan->getDefense(), defense);
}

TEST(GolemTests, getAttack){
    int attack = 5;
    Enemy* villan = new Golem("Golem",1,2,attack,4,5);

    EXPECT_EQ(villan->getAttack(), attack);
}

TEST(GolemTests, getSpeed){
    int speed = 5;
    Enemy* villan = new Golem("Golem",1,2,3,4,speed);

    EXPECT_EQ(villan->getSpeed(), speed);
}

TEST(GolemTests, getExp){
    int exp = 3;
    Enemy* villan = new Golem("Golem",exp,2,3,4,5);

    EXPECT_EQ(villan->getExp(), exp);
}

/*********** Skeleton Tests **********/
TEST(SkeletonTests, testConstructor){
    EXPECT_NO_THROW(Enemy* villan = new Skeleton("Skeleton",1,2,3,4,5));
}

TEST(SkeletonTests, getName){
    string name = "Skeleton";
    Enemy* villan = new Skeleton("Skeleton",1,2,3,4,5);

    EXPECT_EQ(villan->getName(), name);
}

TEST(SkeletonTests, getMaxHealth){
    int health = 20;
    Enemy* villan = new Skeleton("Skeleton",1,health,3,4,5);

    EXPECT_EQ(villan->getMaxHealth(), health);
}

TEST(SkeletonTests, getCurrHealth){
    int health = 20;
    Enemy* villan = new Skeleton("Skeleton",1,health,3,4,5);

    EXPECT_EQ(villan->getCurrHealth(), health);
}

TEST(SkeletonTests, getDefense){
    int defense = 20;
    Enemy* villan = new Skeleton("Skeleton",1,2,3,defense,5);

    EXPECT_EQ(villan->getDefense(), defense);
}

TEST(SkeletonTests, getAttack){
    int attack = 5;
    Enemy* villan = new Skeleton("Skeleton",1,2,attack,4,5);

    EXPECT_EQ(villan->getAttack(), attack);
}

TEST(SkeletonTests, getSpeed){
    int speed = 5;
    Enemy* villan = new Skeleton("Skeleton",1,2,3,4,speed);

    EXPECT_EQ(villan->getSpeed(), speed);
}

TEST(SkeletonTests, getExp){
    int exp = 3;
    Enemy* villan = new Skeleton("Skeleton",exp,2,3,4,5);

    EXPECT_EQ(villan->getExp(), exp);
}

