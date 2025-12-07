#pragma once
#include <string>
#include <vector>

class Player{
    private:
        std::string name;
        int health;
        std::vector<std::string> inventory;

    public:
        Player(std::string n);

        void attack();
        void takeDamage(int amount);
        void addToInventory(std::string item);
        void showInventory();

        int getHealth();
        std::string getName();
};
