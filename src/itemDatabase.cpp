#include <string>
#include <vector>
#include "../header/itemDatabase.h"

ItemDatabase::ItemDatabase() {
//Weapons (0-13)
allItems.push_back(singleItem("Basic Sword", "A short blade that you woke up with. Looks like it can get the job done. --- Damage: 12", "20", "120")); 
allItems.push_back(singleItem("Stone Sword", "A short blade made out of stone. It has worn down over time. --- Damage: 10", "10", "121")); 
allItems.push_back(singleItem("Iron Sword", "A short blade made of cold iron. A little dull but can cut through a lot. --- Damage: 18", "18", "122")); 
allItems.push_back(singleItem("Flame Blade", "A short blade with fiery runes engraved. It even gives off a little light. --- Damage: 25", "25", "123")); 
allItems.push_back(singleItem("Musket", "Man\'s favored tool. --- Attack: 30", "30", "124"));
allItems.push_back(singleItem("Boxing Gloves", "For those wanting to get personal with their opponents. --- Attack: 15", "15", "125"));
allItems.push_back(singleItem("Stick", "It\'s not impressive, but you can pretend it\'s a powerful weapon. --- Attack: 5", "5", "126"));
allItems.push_back(singleItem("Sword from Stone", "A blade with a blue guard, said to have been wielded by an ancient hero of courage. --- Attack: 30", "30", "127"));
allItems.push_back(singleItem("Broken Sword", "The blade has rusted and snapped. Very ineffective. --- Attack: -5", "-5", "128"));
allItems.push_back(singleItem("Electric Blade", "A short blade charged with intense energy. Your foes will definitely be in shock now. --- Magic: 18", "18", "150"));
allItems.push_back(singleItem("Wooden Staff", "A basic staff to practice the arcane arts. --- Magic: 12", "12", "151"));
allItems.push_back(singleItem("Wand", "A standard tool to concentrate your magic mastery. --- Magic: 20", "20", "152"));
allItems.push_back(singleItem("Necronomicon", "An ancient, malicious book. Its contents sap away your mental strength.--- Magic: 30", "30", "153"));
allItems.push_back(singleItem("Thundercleave", "An electrical switch axe. Made from the usurper of thunder. --- Magic: 35", "35", "154"));

//Equips (14-29)
allItems.push_back(singleItem("Dragon Force", "Take Bal\'s powers, bal!. --- Attack: 25", "25", "220"));
allItems.push_back(singleItem("Cactus Costume", "Doubt you\'ll be hugged again, but you can always bring it to them. --- Attack: 14", "14", "221"));
allItems.push_back(singleItem("Red Scarf", "The feeling of passion is seared into this scarf. --- Attack: 15", "15", "222"));
allItems.push_back(singleItem("Cursed Armor", "A set of enchanted iron armor. Wearing it feels physically draining. --- Attack: -10", "-10", "223"));
allItems.push_back(singleItem("Leather Armor", "Some thick armor made out of rough leather. --- Defense: +5", "5", "230")); 
allItems.push_back(singleItem("Iron Chainmail", "Light chains that can protect from weaker blows. --- Defense: +10", "10", "231"));
allItems.push_back(singleItem("Iron Plating", "Heavy plating made of iron. It weighs you down but not a lot to get through. --- Defense: +18", "18", "232")); 
allItems.push_back(singleItem("Basic Shield", "A medium round shield that can block incoming attacks. --- Defense: +8", "8", "233")); 
allItems.push_back(singleItem("Iron Shield", "A shield made of heavy Iron. --- Defense: 18", "18", "234"));
allItems.push_back(singleItem("Fool\'s Gold Armor", "Not only will these hits still hurt, but you look like an inadequate. --- Defense: -15", "-15", "235"));
allItems.push_back(singleItem("Pegasus Boots", "With these boots, you feel extremely light on your feet. --- Speed: +15", "15", "240")); 
allItems.push_back(singleItem("Cloak", "A hooded item that conceals your presence like a thief. --- Speed: 10", "10", "241"));
allItems.push_back(singleItem("Cyclone", "A bike used by a great hero of legend. --- Speed: 20", "20", "242"));
allItems.push_back(singleItem("Iron Boots", "Boots made out of thick iron. Incredibly heavy. --- Speed: -10", "-10", "243"));
allItems.push_back(singleItem("Gold Armor", "Heavy plating made of gold. These hits will still hurt a lot, but at least you\'ll look nice. --- Magic: 15", "15", "250"));
allItems.push_back(singleItem("Dunce Cap", "A regular paper hat to wear. It does nothing, but you can\'t help but feel humiliated. --- Magic: -15", "-15", "251"));

//Usables (30-44)
allItems.push_back(singleItem("Health Potion I", "A simple red potion that restores some health. --- Heal: 10", "10", "310")); 
allItems.push_back(singleItem("Health Potion II", "A stronger red potion that restores health. --- Heal: 25", "25", "311")); 
allItems.push_back(singleItem("Health Potion III", "A superb red potion that restores a good portion of health. --- Heal: 50", "50", "312"));
allItems.push_back(singleItem("Homemade Pie", "Granny is always there to help in a pinch. --- Heal: 30", "30", "313")); 
allItems.push_back(singleItem("Dog", "A simple companion to cure all those worries. --- Heal: 50", "50", "314"));
allItems.push_back(singleItem("Bottled Fairy", "It doesn\'t look happy in there, but I\'m sure they\'ll lend a hand for their freedom. --- Heal: 40", "40", "315"));
allItems.push_back(singleItem("Magic Potion I", "A simple green potion that increases some magic. --- Magic: 10", "10", "350")); 
allItems.push_back(singleItem("Magic Potion II", "A stronger green potion that increases magic. --- Magic: 20", "20", "351")); 
allItems.push_back(singleItem("MTK: Burst", "A small burst of magic. --- Magic: 15", "15", "352"));
allItems.push_back(singleItem("ATK: Burst", "A small burst of attack power. --- Attack: 15", "15", "320"));
allItems.push_back(singleItem("Chili Pepper", "A spicy snack. Get your blood pumping through the heat. --- Attack: 20", "20", "321"));
allItems.push_back(singleItem("DEF: Burst", "A small burst of defense power. --- Defense: 15", "15", "330"));
allItems.push_back(singleItem("Ironskin Potion I", "A murky yellow potion. Makes your skin as tough as iron. --- Defense: 10", "10", "331"));
allItems.push_back(singleItem("Ironskin Potion II", "A murky yellow potion. Makes your skin as tough as steel. --- Defense: 20", "20", "332"));
allItems.push_back(singleItem("SPE: Burst", "A small burst of speed power. --- Speed: 15", "15", "340"));
}

ItemDatabase::~ItemDatabase() {}

int ItemDatabase::getSize() const {
    return allItems.size();
}

std::string ItemDatabase::returnItem(int item, int returnProperty) const {
    return allItems.at(item).at(returnProperty);
}

std::vector<std::string> ItemDatabase::returnSingleItem(int index) {
    return allItems.at(index);
}

std::vector<std::string> ItemDatabase::singleItem(std::string name, std::string des, std::string prop, std::string id) {
    std::vector<std::string> returnVector;
    returnVector.push_back(name);
    returnVector.push_back(des);
    returnVector.push_back(prop);
    returnVector.push_back(id);
    return returnVector;
}
