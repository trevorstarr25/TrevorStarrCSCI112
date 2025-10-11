#include "starWars.h"
#include <iostream>
using namespace std;

using namespace starwars;

int main(){
    string filename = "jedi_data.txt";
    string jediName;

    cout << "Enter Jedi name: ";
    getline(cin, jediName);

    Jedi player(jediName);
    player.saveToFile(filename);
    cout << "\nJedi saved." << endl;

    Jedi loadedJedi;
    loadedJedi.loadFromFile(filename);
    cout << "\nLoaded Jedi" << endl;
    cout << "Name: " << loadedJedi.getName() << endl;
    cout << "Health: " << loadedJedi.getHealth() << endl;
    cout << "Lightsaber Skill: " << loadedJedi.getLightsaberSkill() << endl;
    cout << "Force Power: " << loadedJedi.getForcePower() << endl;

    Sith darth("Darth Maul", 120, 60);
    cout << "\nYour opponent: " << darth.getName() << endl;

    while(loadedJedi.getHealth() > 0 && darth.getHealth() > 0){
        int jediAttack = loadedJedi.attack();
        int sithAttack = darth.attack();

        cout << loadedJedi.getName() << " deals " << jediAttack << " damage." << endl;
        darth.takeDamage(jediAttack);

        if(darth.getHealth() <= 0){
            cout << darth.getName() << " has been defeated." << endl;
            break;
        }

        cout << darth.getName() << " deals " << sithAttack << " damage." << endl;
        loadedJedi.takeDamage(sithAttack);

        if(loadedJedi.getHealth() <= 0){
            cout << loadedJedi.getName() << " has been defeated." << endl;
            break;
        }

        cout << loadedJedi.getName() << " Health: " << loadedJedi.getHealth() << " | " << darth.getName() << " Health: " << darth.getHealth() << endl;
    }

    cout << "\nBattle Over.";
    return 0;
}
