#include "item.h"

Item::Item(std::string n, int e){
    name = n;
    effect = e;
}

std::string Item::use(){
    return name;
}

int Item::getEffect(){
    return effect;
}

std::string Item::getName(){
    return name;
}
