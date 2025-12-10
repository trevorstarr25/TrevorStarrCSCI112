#ifndef JEDI_H
#define JEDI_H

#include <string>

namespace starwars{

    class Jedi{
        private:
            std::string name;
            int health;
            int lightsaberSkill;
            int forcepower;

        public:
            Jedi(std::string n = "Unknown Jedi";
                int h = 100;
                int ls = 50;
                int fp = 75;

            std::string getName() const;
            int getHealth() const;
            int getLightsaberSkill() const;
            int getForcePower() const;

            void setName(const std::string& n);
            void setHealth(int h);
            void setLightsaberSkill(int ls);
            void setForcePower(int fp);

            int attack() const;
            void useForce(int power);
            void takeDamage(int damage);

            void saveToFile(const std::string& filename = "jedi.txt") const;
            void loadFromFile(const std::string& filename = "jedi.txt");
    };
}

#endif