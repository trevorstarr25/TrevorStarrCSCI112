#include "sith.h"

namespace starwars{
    Sith::Sith(std::string n, int h, int ls) : name(n), health(h), lightsaberSkill(ls) {}

    std::string Sith::getName() const {return name;}
    int Sith::getHealth() const {return health;}
    int Sith::getLightsaberSkill() const {return lightsaberSkill;}

    void Sith::setName(const std::string& n) {name = n;}
    void Sith::setHealth(int h) {health = h;}
    void Sith::setLightsaberSkill(int ls) {lightsaberSkill = ls;}

    int Sith::attack() const{
        return lightsaberSkill;
    }

    void Sith::takeDamage(int damage){
        health -= damage;
        if(health < 0) health = 0;
    }
}
