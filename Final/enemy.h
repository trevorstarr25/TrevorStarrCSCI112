#pragma once
#include <string>

class Enemy{
    private:
        std::string name;
        int health;
        int damage;

    public:
        Enemy(std::string n, int h, int d);

        int attack();
        void takeDamage(int amount);

        bool isDead();
        std::string getName();
        int getHealth();
};
