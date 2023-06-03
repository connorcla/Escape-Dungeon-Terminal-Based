#include "../header/room.h"
#include "../header/enemy.h"
#include "../header/witch.h"
#include "gtest/gtest.h"
using namespace std;

TEST(RoomTests, testConstructor){
    EXPECT_NO_THROW(Room roomTest(1));
}

TEST(RoomTests, generateEnemies){
    Room room;
    EXPECT_NO_THROW(room.generateEnemies(0));
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
}

TEST(RoomTests, setEnemiesBeforeLastRoom){
    Room room;
    EXPECT_NO_THROW(room.setEnemiesBeforeLastRoom(5));
}

TEST(RoomTests, getEnemyNULLPTR){
    Room room;
    Enemy* empty = nullptr;
    EXPECT_EQ(room.getEnemy(6),empty);
    delete empty;
}

TEST(RoomTests, setRMStatus){
    Room room;
    EXPECT_NO_THROW(room.setRmStatus("Clear "));

}

//TEST(RoomTests, startBattle){ }

TEST(RoomTests, getRMStatus){
    Room room;
    string currStatus = "Clear ";
    
    room.setRmStatus("Clear ");

    EXPECT_EQ(room.getRmStatus(),currStatus);
}

TEST(RoomTests, getItem) {
    srand(0);
    Room room(2);

    vector<string> compareItem;
    compareItem.push_back("Health Potion II");
    compareItem.push_back("A stronger red potion that restores health. --- Heal: 25");
    compareItem.push_back("25");
    compareItem.push_back("311");

    EXPECT_EQ(compareItem, room.getItem());
}


