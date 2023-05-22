#ifndef ENTITY_H
#define ENTITY_H

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
    void setStats();
private:
    int max_health;
    int curr_health;
    int defense;
    int attack;
    int speed;
};

#endif  // ENTITY_H
