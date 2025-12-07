#include "room.h"

Room::Room(std::string desc){
    description = desc;
    enemy = nullptr;
    item = nullptr;
    next = nullptr;
}

void Room::setEnemy(Enemy* e) {enemy = e;}
void Room::setItem(Item* i) {item = i;}
void Room::setNext(Room* n) {next = n;}

Enemy* Room::getEnemy() {return enemy;}
Item* Room::getItem() {return item;}
Room* Room::getNext() {return next;}
std::string Room::getDescription() {return description;}

void Room::removeEnemy() {enemy = nullptr;}
void Room::removeItem() {item = nullptr;}

