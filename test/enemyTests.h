#ifndef ENEMYTESTS_H
#define ENEMYTESTS_H
#include "../header/enemy.h"
#include "../header/witch.h"
#include "../header/spider.h"
#include "../header/golem.h"
#include "../header/skeleton.h"
#include "../header/boss.h"
#include "../header/player.h"
#include "gtest/gtest.h"
using namespace std;

/*********** Witch Tests **********/
TEST(WitchTests, testConstructor){
    Enemy* villan = nullptr;
    EXPECT_NO_THROW(villan = new Witch("Witch",1,2,3,4,5,6));
    delete villan;
}

TEST(WitchTests, getName){
    string name = "Witch";
    Enemy* villan = new Witch("Witch",1,2,3,4,5,6);

    EXPECT_EQ(villan->getName(), name);
    delete villan;
}

TEST(WitchTests, getMaxHealth){
    int health = 20;
    Enemy* villan = new Witch("Witch",1,health,3,4,5,6);

    EXPECT_EQ(villan->getMaxHealth(), health);
    delete villan;
}

TEST(WitchTests, getCurrHealth){
    int health = 20;
    Enemy* villan = new Witch("Witch",1,health,3,4,5,6);

    EXPECT_EQ(villan->getCurrHealth(), health);
    delete villan;
}

TEST(WitchTests, getDefense){
    int defense = 20;
    Enemy* villan = new Witch("Witch",1,2,3,defense,5,6);

    EXPECT_EQ(villan->getDefense(), defense);
    delete villan;
}

TEST(WitchTests, getAttack){
    int attack = 5;
    Enemy* villan = new Witch("Witch",1,2,attack,4,5,6);

    EXPECT_EQ(villan->getAttack(), attack);
    delete villan;
}

TEST(WitchTests, getSpeed){
    int speed = 5;
    Enemy* villan = new Witch("Witch",1,2,3,4,speed,6);
    
    EXPECT_EQ(villan->getSpeed(), speed);
    delete villan;
}

TEST(WitchTests, getExp){
    int exp = 3;
    Enemy* villan = new Witch("Witch",exp,2,3,4,5,6);

    EXPECT_EQ(villan->getExp(), exp);
    delete villan;
}

TEST(WitchTests, Action){
    Enemy* villan = new Witch("Witch",1,2,3,4,5,6);
    Player player;
    string empty = " ";

    villan->action(player);
    villan->action(player);
    villan->action(player);
    villan->action(player);
    villan->action(player);
    villan->action(player);
    villan->action(player);
    villan->action(player);
    villan->action(player);

    EXPECT_NE(villan->action(player), empty);
    delete villan;
}

TEST(WitchTests, AttackedByPlayer){
    Enemy* villan = new Witch("Witch",10,30,10,15,15,30);
    const int currEnemyHealth = villan->getCurrHealth();

    villan->attackedByPlayer(20);

    EXPECT_EQ(villan->getCurrHealth(),23);
    delete villan;
}

/*********** Spider Tests **********/
TEST(SpiderTests, testConstructor){
    Enemy* villan = nullptr;
    EXPECT_NO_THROW(villan = new Spider("Spider",1,2,3,4,5));
    delete villan;
}

TEST(SpiderTests, getName){
    string name = "Spider";
    Enemy* villan = new Spider("Spider",1,2,3,4,5);

    EXPECT_EQ(villan->getName(), name);
    delete villan;
}

TEST(SpiderTests, getMaxHealth){
    int health = 20;
    Enemy* villan = new Spider("Spider",1,health,3,4,5);

    EXPECT_EQ(villan->getMaxHealth(), health);
    delete villan;
}

TEST(SpiderTests, getCurrHealth){
    int health = 20;
    Enemy* villan = new Spider("Spider",1,health,3,4,5);

    EXPECT_EQ(villan->getCurrHealth(), health);
    delete villan;
}

TEST(SpiderTests, getDefense){
    int defense = 20;
    Enemy* villan = new Spider("Spider",1,2,3,defense,5);

    EXPECT_EQ(villan->getDefense(), defense);
    delete villan;
}

TEST(SpiderTests, getAttack){
    int attack = 5;
    Enemy* villan = new Spider("Spider",1,2,attack,4,5);

    EXPECT_EQ(villan->getAttack(), attack);
    delete villan;
}

TEST(SpiderTests, getSpeed){
    int speed = 5;
    Enemy* villan = new Spider("Spider",1,2,3,4,speed);

    EXPECT_EQ(villan->getSpeed(), speed);
    delete villan;
}

TEST(SpiderTests, getExp){
    int exp = 3;
    Enemy* villan = new Spider("Spider",exp,2,3,4,5);

    EXPECT_EQ(villan->getExp(), exp);
    delete villan;
}

TEST(SpiderTests, Action){
    Enemy* villan = new Spider("Spider",1,2,3,4,5);
    Player player;
    string empty = "";

    villan->action(player);
    villan->action(player);
    villan->action(player);
    villan->action(player);
    villan->action(player);
    villan->action(player);
    villan->action(player);
    villan->action(player);
    villan->action(player);

    EXPECT_NE(villan->action(player), empty);
    delete villan;
}


/********** Golem Tests ***********/
TEST(GolemTests, testConstructor){
    Enemy* villan = nullptr;
    EXPECT_NO_THROW(villan = new Golem("Golem",1,2,3,4,5));
    delete villan;
}

TEST(GolemTests, getName){
    string name = "Golem";
    Enemy* villan = new Golem("Golem",1,2,3,4,5);

    EXPECT_EQ(villan->getName(), name);
    delete villan;
}

TEST(GolemTests, getMaxHealth){
    int health = 20;
    Enemy* villan = new Golem("Golem",1,health,3,4,5);

    EXPECT_EQ(villan->getMaxHealth(), health);
    delete villan;
}

TEST(GolemTests, getCurrHealth){
    int health = 20;
    Enemy* villan = new Golem("Golem",1,health,3,4,5);

    EXPECT_EQ(villan->getCurrHealth(), health);
    delete villan;
}

TEST(GolemTests, getDefense){
    int defense = 20;
    Enemy* villan = new Golem("Golem",1,2,3,defense,5);

    EXPECT_EQ(villan->getDefense(), defense);
    delete villan;
}

TEST(GolemTests, getAttack){
    int attack = 5;
    Enemy* villan = new Golem("Golem",1,2,attack,4,5);

    EXPECT_EQ(villan->getAttack(), attack);
    delete villan;
}

TEST(GolemTests, getSpeed){
    int speed = 5;
    Enemy* villan = new Golem("Golem",1,2,3,4,speed);

    EXPECT_EQ(villan->getSpeed(), speed);
    delete villan;
}

TEST(GolemTests, getExp){
    int exp = 3;
    Enemy* villan = new Golem("Golem",exp,2,3,4,5);

    EXPECT_EQ(villan->getExp(), exp);
    delete villan;
}

TEST(GolemTests, Action){
    Enemy* villan = new Golem("Golem",1,2,3,4,5);
    Player player;
    string empty = "";

    villan->action(player);
    villan->action(player);
    villan->action(player);
    villan->action(player);
    villan->action(player);
    villan->action(player);
    villan->action(player);
    villan->action(player);
    villan->action(player);

    EXPECT_NE(villan->action(player), empty);
    delete villan;
}

/*********** Skeleton Tests **********/
TEST(SkeletonTests, testConstructor){
    Enemy* villan = nullptr;
    EXPECT_NO_THROW(villan = new Skeleton("Skeleton",1,2,3,4,5));
    delete villan;
}

TEST(SkeletonTests, getName){
    string name = "Skeleton";
    Enemy* villan = new Skeleton("Skeleton",1,2,3,4,5);

    EXPECT_EQ(villan->getName(), name);
    delete villan;
}

TEST(SkeletonTests, getMaxHealth){
    int health = 20;
    Enemy* villan = new Skeleton("Skeleton",1,health,3,4,5);

    EXPECT_EQ(villan->getMaxHealth(), health);
    delete villan;
}

TEST(SkeletonTests, getCurrHealth){
    int health = 20;
    Enemy* villan = new Skeleton("Skeleton",1,health,3,4,5);

    EXPECT_EQ(villan->getCurrHealth(), health);
    delete villan;
}

TEST(SkeletonTests, getDefense){
    int defense = 20;
    Enemy* villan = new Skeleton("Skeleton",1,2,3,defense,5);

    EXPECT_EQ(villan->getDefense(), defense);
    delete villan;
}

TEST(SkeletonTests, getAttack){
    int attack = 5;
    Enemy* villan = new Skeleton("Skeleton",1,2,attack,4,5);

    EXPECT_EQ(villan->getAttack(), attack);
    delete villan;
}

TEST(SkeletonTests, getSpeed){
    int speed = 5;
    Enemy* villan = new Skeleton("Skeleton",1,2,3,4,speed);

    EXPECT_EQ(villan->getSpeed(), speed);
    delete villan;
}

TEST(SkeletonTests, getExp){
    int exp = 3;
    Enemy* villan = new Skeleton("Skeleton",exp,2,3,4,5);

    EXPECT_EQ(villan->getExp(), exp);
    delete villan;
}

TEST(SkeletonTests, Action){
    Enemy* villan = new Skeleton("Skeleton",1,2,3,4,5);
    Player player;
    string empty = "";

    villan->action(player);
    villan->action(player);
    villan->action(player);
    villan->action(player);
    villan->action(player);
    villan->action(player);
    villan->action(player);
    villan->action(player);
    villan->action(player);

    EXPECT_NE(villan->action(player), empty);
    delete villan;

}

/*********** Boss Tests **********/
TEST(BossTests, testConstructor){
    Enemy* villan = nullptr;
    EXPECT_NO_THROW(villan = new Boss("Boss",1,2,3,4,5,6));
    delete villan;
}

TEST(BossTests, getName){
    string name = "Boss";
    Enemy* villan = new Boss("Boss",1,2,3,4,5,6);

    EXPECT_EQ(villan->getName(), name);
	 delete villan;
}

TEST(BossTests, getMaxHealth){
    int health = 20;
    Enemy* villan = new Boss("Boss",1,health,3,4,5,6);

    EXPECT_EQ(villan->getMaxHealth(), health);
	 delete villan;
}

TEST(BossTests, getCurrHealth){
    int health = 20;
    Enemy* villan = new Boss("Boss",1,health,3,4,5,6);

    EXPECT_EQ(villan->getCurrHealth(), health);
	 delete villan;
}

TEST(BossTests, getDefense){
    int defense = 20;
    Enemy* villan = new Boss("Boss",1,2,3,defense,5,6);

    EXPECT_EQ(villan->getDefense(), defense);
	 delete villan;
}

TEST(BossTests, getAttack){
    int attack = 5;
    Enemy* villan = new Boss("Boss",1,2,attack,4,5,6);

    EXPECT_EQ(villan->getAttack(), attack);
	 delete villan;
}

TEST(BossTests, getSpeed){
    int speed = 5;
    Enemy* villan = new Boss("Boss",1,2,3,4,speed,6);

    EXPECT_EQ(villan->getSpeed(), speed);
	 delete villan;
}

TEST(BossTests, getExp){
    int exp = 3;
    Enemy* villan = new Boss("Boss",exp,2,3,4,5,6);

    EXPECT_EQ(villan->getExp(), exp);
	 delete villan;
}

TEST(BossTests, Action){
    Enemy* villan = new Boss("Boss",1,2,3,4,5,6);
    Player player;
    string empty = "";

    villan->action(player);
    villan->action(player);
    villan->action(player);
    villan->action(player);
    villan->action(player);
    villan->action(player);
    villan->action(player);
    villan->action(player);
    villan->action(player);

    EXPECT_NE(villan->action(player), empty);
    delete villan;
}

/*
TEST(EnemyTests, getMagic){
    int magic = 2;
    Enemy* villan = new Boss("Boss",1,2,3,4,5,magic);

    EXPECT_EQ(villan->getMagic(), magic);
}
*/

#endif