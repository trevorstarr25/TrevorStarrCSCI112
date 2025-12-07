#include "enemy.h"
#include <iostream>

Enemy::Enemy(std::string n, int h, int d){
    name = n;
    health = h;
    damage = d;
}

int Enemy::attack(){
    return damage;
}

void Enemy::takeDamage(int amount){
    health -= amount;
    if(health < 0)
        health = 0;
    
    std::cout << name << " took " << amount << " damage. Enemy health: " << health << std::endl;
}

bool Enemy::isDead(){
    return health <= 0;
}

std::string Enemy::getName(){
    return name;
}

int Enemy::getHealth(){
    return health;
}
