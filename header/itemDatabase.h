#ifndef ITEMDATABASE_HPP
#define ITEMDATABASE_HPP
#include <string>
#include <vector>

class ItemDatabase {
    private:
        std::vector<std::vector<std::string>> allItems;
        std::vector<std::string> singleItem(std::string name, std::string des, std::string prop, std::string id);
    public:
        ItemDatabase();
        ~ItemDatabase();
        int getSize();
        std::string returnItem(int, int);
};

#endif