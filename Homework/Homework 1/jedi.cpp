#include "jedi.h"
#include <fstream>
#include <iostream>

namespace starwars{
    Jedi::Jedi(std::string n, int h, int ls, int fp) 
        : name(n), health(h), lightsaberSkill(ls), forcePower(fp) {}
    
    std::string Jedi::getName() const {return name;}
    int Jedi::getHealth() const {return health;}
    int Jedi::getLightsaberSkill() const {return lightsaberSkill;}
    int Jedi::getForcePower() const {return forcePower;}

    void Jedi::setName(const std::string& n) {name = n;}
    void Jedi::setHealth(int h)  {health = h;}
    void Jedi::setLightsaberSkill(int ls) {lightsaberSkill = ls;}
    void Jedi::setForcePower(int fp) {forcePower = fp;}

    int Jedi::attack() const{
        return lightsaberSkill;
    }

    void Jedi::useForce(int power){
        if (power > forcePower)
            power = forcePower;
        forcePower -= power;
    }

    void Jedi::takeDamage(int damage){
        health -= damage;
        if (health < 0) health = 0;
    }

    // Save Jedi properties to file
    void Jedi::saveToFile(const std::string& filename) const{
        std::ofstream file(filename);
        if(!file){
            std::cerr << "Error writing to file.\n";
            return;
        }
        file << name << "\n"
            << health << "\n"
            << lightsaberSkill << "\n"
            << forcePower << "\n";
    }

    // Load Jedi from file
    void Jedi::loadFromFile(const std::string& filename){
        std::ifstream file(filename);
        if(!file){
            std::cerr << "Error reading file.\n";
            return;
        }
        std::getline(file, name);
        file >> health;
        file >> lightsaberSkill;
        file >> forcePower;
    }
}
