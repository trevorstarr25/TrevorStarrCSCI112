#include "player.h"
#include <iostream>

Player::Player(std::string n){
    name = n;
    health = 100;
}

void Player::attack(){
    std::cout <<  "You attack the enemy!" << std::endl;
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

void Player::addToInventory(std::string item){
    inventory.push_back(item);
    std::cout << item << " added to inventory." << std::endl;
}

void Player::showInventory(){
    std::cout << "Inventory: ";
    for(std::string i : inventory){
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}

int Player::getHealth(){
    return health;
}

std::string Player::getName(){
    return name;
}