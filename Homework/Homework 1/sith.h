#ifndef SITH_H
#define SITH_H

#include <string>

namespace starwars{

    class Sith{
        private:
            std::string name;
            int health;
            int lightsaberSkill;

        public:
            Sith(std::string n = "Unknown sith", int h = 120, int ls = 60);

        std::string getName() const;
        int getHealth() const;
        int getLightsaberSkill() const;

        void setName(const std::string& n);
        void setHealth(int h);
        void setLightsaberSkill(int ls);

        int attack() const;
        void takeDamage(int damage);
    };
}

#endif