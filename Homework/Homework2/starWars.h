#ifndef STARWARS_H
#define STARWARS_H

#include <string>

namespace starwars {
    class Character {
        protected:
            std::string name;
            int health;
            int attackPower;
        public:
            Character(std::string n = "Unknown", int h = 100, int ap = 50);
            virtual ~Character() = default;
            std::string getName() const;
            int getHealth() const;
            virtual void takeDamage(int damage);
            virtual int attack() const;
    };

    class Jedi{
        protected:
            int lightsaberSkill;
            int forcePower;

        public:
            Jedi(std::string n = "Unknown Jedi", int h = 100, int ls = 50, int fp = 75);

            int getLightsaberSkill() const;
            int getForcePower() const;
            void setName(std::string n);
            void setHealth(int h);
            void setLightsaberSkill(int ls);
            void setForcePower(int fp);

            int attack() const;
            void useForce(int power);
            void takeDamage(int damage);

            void saveToFile(const std::string& filename) const;
            void loadFromFile(const std::string& filename);
    };

    class Guardian : public Jedi {
        public:
            Guardian(std::string n = "Guardian Jedi");
    };
    class Consular : public Jedi {
        public:
            Consular(std::string n = "Consular Jedi");
    };

    class Sith {
        public:
            Sith(std::string n = "Unknown Sith", int h = 120, int ap = 60);
            void takeDmaage(int damage);
            int attack() const;
    };

    class Acolyte : public Sith {
        public:
            Acolyte(std::string n = "Acolyte Sith");
    };
    class Darth : public Sith {
        public:
            Darth(std::string n = "Darth Sith");
    };
}

#endif