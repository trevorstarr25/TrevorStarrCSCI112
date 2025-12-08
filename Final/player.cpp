#include "player.h"
#include <iostream>

Player::Player(std::string n){
    name = n;
    health = 100;
}

void Player::attack(){
    std::cout <<  "\nYou swing your broadsword at the enemy!" << std::endl;
}

void Player::takeDamage(int amount){
    health -= amount;
    if(health < 0){
        health = 0;
        std::cout << "You took " << amount << " damage and have perished." << std::endl;
    }
    else{
        std::cout << "You took " << amount << " damage. Health: " << health << std::endl;
    }

}

void Player::addToInventory(Item* item){
    inventory.push_back(item);
    std::cout << item->getName() << " added to inventory." << std::endl;
}

void Player::showInventory(){
    std::cout << "Inventory: ";
    if(inventory.empty()){
        std::cout << "(empty)";
    } else {
        for(Item* i : inventory){
            std::cout << i->getName() << " (+" << i->getEffect() << " HP), ";
        }
    }
    std::cout << std::endl;
}


void Player::heal(int amount){
    health += amount;

    std::cout << "The health potion increased your HP by: " << amount << std::endl;
    std::cout << "Current HP: " << health << std::endl;
}

int Player::getHealth(){
    return health;
}

std::string Player::getName(){
    return name;
}

std::vector<Item*>& Player::getInventory(){
    return inventory;
}
