#include "starWars.h"
#include <iostream>
#include<fstream>

namespace starwars {
    Jedi::Jedi(std::string n, int h, int ls, int fp) : name(n), health(h), lightsaberSkill(ls), forcePower(fp) {}

    std::string Jedi::getName() const {return name;}
    int Jedi::getHealth() const {return health;}
    int Jedi::getForcePower() const {return forcePower;}

    void Jedi::setName(std::string n) {name = n;}
    void Jedi::setHealth(int h) {health = h;}
    void Jedi::setLightsaberSkill(int ls) {lightsaberSkill = ls;}
    void Jedi::setForcePower(int fp) {forcePower = fp;}

    int Jedi::attack() const {return lightsaberSkill;}

    void Jedi::useForce(int power){
        forcePower -= power;
        if(forcePower < 0)
            forcePower = 0;
    }

    void Jedi::takeDamage(int damage){
        health -= damage;
        if(health < 0)
            health = 0;
    }

    void Jedi::saveToFile(const std::string& filename) const{
        std::ofstream outFile(filename);
        if(outFile.is_open()){
            outFile << name << "\n" << health << "\n" << lightsaberSkill << "\n"
                    << forcePower << "\n";
        }
        else{
            std::cout << "Error: Could not open the file for saving\n";
        }
    }

    void Jedi::loadFromFile(const std::string& filename){
        std::ifstream inFile(filename);
        if(inFile.is_open()){
            std::getline(inFile, name);
            inFile >> health >> lightsaberSkill >> forcePower;
        }
        else{
            std::cout << "Error: could not open the file.\n";
        }
    }

    Sith::Sith(std::string n, int h, int ls) : name(n), health(h), lightsaberSkill(ls) {}

    std::string Sith::getName() const {return name;}
    int Sith::getHealth() const {return health;}
    int Sith::getLightsaberSkill() const {return lightsaberSkill;}

    void Sith::takeDamage(int damage){
        health -= damage;
        if(health < 0)
            health = 0;
    }

    int Sith::attack() const {return lightsaberSkill;}
}
