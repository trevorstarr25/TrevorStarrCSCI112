#pragma once
#include <string>
#include "enemy.h"
#include "item.h"

class Room{
    private:
        std::string description;
        Enemy* enemy;
        Item* item;
        Room* next;
    
    public:
        Room(std::string desc);
        void setEnemy(Enemy* e);
        void setItem(Item* i);
        void setNext(Room* n);

        Enemy* getEnemy();
        Item* getItem();
        Room* getNext();
        std::string getDescription();

        void removeEnemy();
        void removeItem();
};
