#include "starWars.h"
#include <iostream>
#include<fstream>

namespace starwars {
    Character::Character(std::string n, int h, int ap) : name(n), health(h), attackPower(ap) {}
    std::string Character::getName() const {return name;}
    int Character::getHealth() const {return health;}
    void Character::takeDamage(int damage) {
        health -= damage; 
        if(health < 0) 
             health = 0;
    }
    int Character::attack() const {return attackPower;}

    Character Character::operator+(int value) const {
        Character temp = *this;
        temp.health += value;
        return temp;
    }

    Character Character::operator-(int value) const {
        Character temp = *this;
        temp.health -= value;
        if(temp.health < 0)
            temp.health = 0;
        return temp;
    }

    Jedi::Jedi(std::string n, int h, int ls, int fp) : Character(n,h,ls), lightsaberSkill(ls), forcePower(fp) {}

    std::string Jedi::getName() const {return name;}
    int Jedi::getHealth() const {return health;}
    int Jedi::getForcePower() const {return forcePower;}
    int Jedi::getLightsaberSkill() const {return lightsaberSkill;}

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
        Character::takeDamage(damage);
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

    Sith::Sith(std::string n, int h, int ap) : Character(n,h,ap) {}

    void Sith::takeDamage(int damage){
        Character::takeDamage(damage);
    }

    int Sith::attack() const {return attackPower;}

    Guardian::Guardian(std::string n) : Jedi(n,150,70,75) {}
    Consular::Consular(std::string n) : Jedi(n,100,50,120) {}

    Acolyte::Acolyte(std::string n) : Sith(n,80,40) {}
    Darth::Darth(std::string n) : Sith(n,200,100) {}
}
