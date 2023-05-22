#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>

class Item {
    protected:
        std::string name;
        std::string description;
        int property;
        int id;
    public:
        Item();
        Item(std::string, std::string, int, int);
        ~Item();
        std::string getName() const;
        std::string displayDescription() const;
        int getProperty() const;
        int getID() const;
};

#endif