#include "../header/room.h"
#include <vector>
using namespace std;

Room::Room() {}

void Room::setRmStatus(string status) {
    rmStatus = status;
}

string Room::getRoomInfo() const {
    return rmInfo;
}

string Room::getRoomStatus() const {
    return rmStatus;
}
