#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "entity.h"

class Player : public Entity {
private:
    int magic;

public:
    // Constructor
    Player();
    ~Player();

    // Getters and setters
    int getMagic() const;
    void setMagic(int);
    void setName(std::string);
    void updateStat(int, int);
};

#endif  // ENTITY_H
