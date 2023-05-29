#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <string>

class Entity {
public:
    // Constructor
    Entity();

    // Getters and setters
    int getMaxHealth() const;
    int getCurrHealth() const;
    int getDefense() const;
    int getAttack() const;
    int getSpeed() const;
    int getExp() const;
    std::string getName() const;
    void setStats(int, int, int, int, int, int, std::string);
protected:
    std::string name;
    int exp;
    int max_health;
    int curr_health;
    int defense;
    int attack;
    int speed;
};

#endif  // ENTITY_H
