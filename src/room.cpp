#include "../header/room.h"
#include <vector>
using namespace std;

Room::Room(){}

void Room::setRmStatus(string status){
    rmStatus = status;
}

void Room::startBattle(){

}

string Room::getRoomInfo(){
    return rmInfo;
}

string Room::getRoomStatus(){
    return rmStatus;
}
