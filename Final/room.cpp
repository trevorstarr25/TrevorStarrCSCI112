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
