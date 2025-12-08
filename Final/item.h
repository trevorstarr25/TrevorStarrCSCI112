#pragma once
#include <string>

class Item{
    private:
        std::string name;
        int effect;

    public:
        Item(std::string n, int e);

        std::string use();
        int getEffect();
        std::string getName();
};
