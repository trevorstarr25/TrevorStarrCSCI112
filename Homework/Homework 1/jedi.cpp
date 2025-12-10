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
}
