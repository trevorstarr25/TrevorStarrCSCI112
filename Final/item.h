#pragma once
#include <string>

class Item{
    private:
        std::string name;
        int healAmount;

    public:
        Item(std::string n, int heal);

        std::string use();
        int getHealAmount();
        std::string getName();
};
