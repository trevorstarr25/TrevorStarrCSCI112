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
}
