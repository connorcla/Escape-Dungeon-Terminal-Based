#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "entity.h"

class Player : public Entity {
private:
    int max_magic;
    int curr_magic;

public:
    // Constructor
    Player();
    ~Player();

    // Getters and setters
    int getMaxMagic() const;
    int getCurrMagic() const;
    void setName(std::string);
    void updateStat(int, int);
};

#endif  // ENTITY_H
