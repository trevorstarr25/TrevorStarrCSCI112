#ifndef STARWARS_H
#define STARWARS_H

#include <string>

namespace starwars {
    class Jedi{
        private:
            std::string name;
            int health;
            int lightsaberSkill;
            int forcePower;

        public:
            Jedi(std::string n = "Unknown Jedi", int h = 100, int ls = 50, int fp = 75);


            std::string getName() const;
            int getHealth() const;
            int getLightsaberSkill() const;
            int getForcePower() const;

            void setName(std::string n);
            void setHealth(int h);
            void setLightsaberSkill(int ls);
            void setForcePower(int fp);

            int attack() const;
            void useForce(int power);
            void takeDamage(int damager);

            void saveToFile(const std::string& filename) const;
            void loadFromFile(const std::string& filename);
    };

    class Sith {
        private:
            std::string name;
            int health;
            int lightsaberSkill;


        public:
            Sith(std::string n = "Unknown Sith", int h = 120, int ls = 60);

            std::string getName() const;
            int getHealth() const;
            int getLightsaberSkill() const;

            void takeDamage(int damager);
            int attack() const;
    };
}

#endif