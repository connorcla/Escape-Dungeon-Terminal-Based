#ifndef ROOMTESTS_H
#define ROOMTESTS_H

#include "../header/room.h"
#include "../header/enemy.h"
#include "../header/witch.h"
#include "gtest/gtest.h"
using namespace std;

TEST(RoomTests, testConstructor){
    Room* roomPtr = nullptr;
    EXPECT_NO_THROW(roomPtr = new Room(1));
    roomPtr->deleteEnemies();
    delete roomPtr;
}

TEST(RoomTests, generateEnemies){
    Room room;
    EXPECT_NO_THROW(room.generateEnemies(0));
    room.deleteEnemies();
}

TEST(RoomTests, getRandomNumberLTFive){
    srand(0);
    Room room;
    int roomIndex= 1;
    int enemyQuantity;

    while(roomIndex <= 10){
        enemyQuantity = room.getRandomNumber(roomIndex);
        cout << "\n\t\tRoom # " << roomIndex 
                <<" with Enemy Quantity: " << enemyQuantity << endl;
        roomIndex++;
    }

    EXPECT_LT(room.getRandomNumber(1),5);
    room.deleteEnemies();
}

TEST(RoomTests, getRaondomNumberGTZero){
    srand(0);
    Room room;
    int roomIndex= 1;
    int enemyQuantity;

    while(roomIndex <= 10){
        enemyQuantity = room.getRandomNumber(roomIndex);
        cout << "\n\t\tRoom # " << roomIndex 
                <<" with Enemy Quantity: " << enemyQuantity << endl;
        roomIndex++;
    }

    EXPECT_GT(room.getRandomNumber(10),0);
    room.deleteEnemies();
}

TEST(RoomTests, setEnemiesBeforeLastRoom){
    Room room;
    EXPECT_NO_THROW(room.setEnemiesBeforeLastRoom(5,1));
    room.deleteEnemies();
}

TEST(RoomTests, getEnemyNULLPTR){
    Room room;
    Enemy* empty = nullptr;
    EXPECT_EQ(room.getEnemy(6,1),empty);
    delete empty;
    room.deleteEnemies();
}

TEST(RoomTests, setRMStatus){
    Room room;
    EXPECT_NO_THROW(room.setRmStatus("Clear "));
    room.deleteEnemies();
}

//TEST(RoomTests, startBattle){ }

TEST(RoomTests, getRMStatus){
    Room room;
    string currStatus = "Clear ";
    
    room.setRmStatus("Clear ");

    EXPECT_EQ(room.getRmStatus(),currStatus);
    room.deleteEnemies();
}

TEST(RoomTests, getNumOfEnemiesGTZero){
    Room room(1);
    EXPECT_GT(room.getNumOfEnemies(),0);
    room.deleteEnemies();
}

TEST(RoomTests, getNumOfEnemiesLTFive){
    Room room(1);
    EXPECT_LT(room.getNumOfEnemies(),5);
    room.deleteEnemies();
}

TEST(RoomTests, getEnemyName){
    Room room;
    room.generateEnemies(9);
    string emptyName = " ";
    int firstEnemyIndex = 0;

    EXPECT_NE(room.getEnemyName(firstEnemyIndex), emptyName);
    room.deleteEnemies();
}

TEST(RoomTests, getCURRNTHealth){
    Room room;
    room.generateEnemies(4);

    EXPECT_NE(room.getEnemyCURRNTHealth(0),0);
    room.deleteEnemies();
}

TEST(RoomTests, getMAXHealth){
    Room room;
    room.generateEnemies(3);

    EXPECT_NE(room.getEnemyMAXHealth(0),0);
    room.deleteEnemies();
}

TEST(RoomTests, getItem) {
    srand(0);
    Room room(2);

    vector<string> compareItem;
    compareItem.push_back("Stone Sword");
    compareItem.push_back("A short blade made out of stone. It has worn down over time. --- Damage: 10");
    compareItem.push_back("10");
    compareItem.push_back("121");

    EXPECT_EQ(compareItem, room.getItem());
    room.deleteEnemies();
}

#endif