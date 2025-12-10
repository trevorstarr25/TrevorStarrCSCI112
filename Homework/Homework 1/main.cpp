#include <iostream>
#include <string>
#include "jedi.h"
#include "sith.h"

using namespace starwars;

int main(){
    std::string jediName;
    std::cout << "Enter your Jedi's name: ";
    std::getline(std::cin, jediName);

    Jedi player(jediName);

    player.saveToFile();

    Jedi loadedJedi;
    loadedJedi.loadFromFile();

    std::cout << "\nLoaded Jedi:\n";
    std::cout << "Name: " << loadedJedi.getName() << "\n"
              << "Health: " << loadedJedi.getHealth() << "\n"
              << "Lightsaber Skill: " << loadedJedi.getLightsaberSkill() << "\n"
              << "Force Power: " << loadedJedi.getForcePower() << "\n\n";

    Sith enemy("Darth Maul");

    std::cout << "A Sith appears: " << enemy.getName() << "\n\n";

    while (loadedJedi.getHealth() > 0 && enemy.getHealth() > 0) {
        int jediDamage = loadedJedi.attack();
        enemy.takeDamage(jediDamage);

        std::cout << loadedJedi.getName() << " strikes for " << jediDamage << " damage!\n";

        if (enemy.getHealth() <= 0) break;

        int sithDamage = enemy.attack();
        loadedJedi.takeDamage(sithDamage);

        std::cout << enemy.getName() << " hits back for " << sithDamage << " damage!\n\n";

        std::cout << loadedJedi.getName() << " Health: " << loadedJedi.getHealth() << "\n";
        std::cout << enemy.getName() << " Health: " << enemy.getHealth() << "\n\n";
    }

    if (loadedJedi.getHealth() > 0)
        std::cout << "\nYou have defeated the Sith!\n";
    else
        std::cout << "\nThe Sith has defeated you.\n";

    return 0;
}
