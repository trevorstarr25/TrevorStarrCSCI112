#pragma once
#include <string>
#include <vector>
#include "item.h"

class Player{
    private:
        std::string name;
        int health;
        std::vector<Item*> inventory;

    public:
        Player(std::string n);

        void attack();
        void takeDamage(int amount);
        void addToInventory(Item* item);
        void showInventory();
        void heal(int amount);

        int getHealth();
        std::string getName();
        std::vector<Item*>& getInventory();
};
