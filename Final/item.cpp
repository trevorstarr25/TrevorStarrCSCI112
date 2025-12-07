#include "item.h"

Item::Item(std::string n, int heal){
    name = n;
    healAmount = heal;
}

std::string Item::use(){
    return name;
}

int Item::getHealAmount(){
    return healAmount;
}

std::string Item::getName(){
    return name;
}
