#include "starWars.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

using namespace starwars;

int main(){
    srand(time(0));
    string filename = "jedi_data.txt";
    string jediName;
    int jediChoice;

    cout << "Enter Jedi name: ";
    getline(cin, jediName);

    cout << "Choose Jedi type:\n1. Guardian\n2. Consular\nChoice: ";
    cin >> jediChoice;

    Jedi* player;
    if(jediChoice == 1)
        player = new Guardian(jediName);
    else
        player = new Consular(jediName);

    player->saveToFile(filename);
    cout << "\nJedi saved." << endl;

    Jedi loadedJedi;
    loadedJedi.loadFromFile(filename);
    cout << "\nLoaded Jedi" << endl;
    cout << "Name: " << loadedJedi.getName() << endl;
    cout << "Health: " << loadedJedi.getHealth() << endl;
    cout << "Lightsaber Skill: " << loadedJedi.getLightsaberSkill() << endl;
    cout << "Force Power: " << loadedJedi.getForcePower() << endl;

   Sith* darth;
    if(rand()%2 == 0)
        darth = new Acolyte();
    else
        darth = new Darth();

    cout << "\nYour opponent: " << darth->getName() << endl;

    while(player->getHealth() > 0 && darth->getHealth() > 0){
        int jediAttack = player->attack();
        int sithAttack = darth->attack();

        cout << player->getName() << " deals " << jediAttack << " damage." << endl;
        darth->takeDamage(jediAttack);

        if(darth->getHealth() <= 0){
            cout << darth->getName() << " has been defeated." << endl;
            break;
        }

        cout << darth->getName() << " deals " << sithAttack << " damage." << endl;
        player->takeDamage(sithAttack);

        if(player->getHealth() <= 0){
            cout << player->getName() << " has been defeated." << endl;
            break;
        }

        cout << player->getName() << " Health: " << player->getHealth() << " | " << darth->getName() << " Health: " << darth->getHealth() << endl;
    }

    cout << "\nBattle Over.";
    delete player;
    delete darth;
    return 0;
}
