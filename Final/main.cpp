#include <iostream>
#include "dungeon.h"
#include "player.h"
#include "enemy.h"
#include "item.h"

using namespace std;

int main(){
    cout << "Welcome to the dungeon! What is your name? ";
    string pname;
    cin >> pname;

    Player player(pname);

    Dungeon dungeon;

    Room* r1 = new Room("You are in the entrance of a dark dungeon.");
    Room* r2 = new Room("A narrow hallway lit by torchlight.");
    Room* r3 = new Room("A room with a large chest. A dragon guards it!");

    r1->setEnemy(new Enemy("Goblin", 30, 5));
    r1->setItem(new Item("Health Potion", 15));

    r2->setItem(new Item("Health Potion", 25));
    r2->setEnemy(new Enemy("Orc", 50, 25));

    r3->setEnemy(new Enemy("Dragon", 100, 20));
    r3->setItem(new Item("A chest full of gold", 0));

    dungeon.addRoom(r1);
    dungeon.addRoom(r2);
    dungeon.addRoom(r3);

    Room* current = dungeon.getHead();

    while(current != nullptr){
        cout << "\n--- " << current->getDescription() << "\n---" << endl;

        if(current->getEnemy()){
            Enemy* e = current->getEnemy();
            cout << "An enemy appears and blocks your path: " << e->getName() << " (HP: " << e->getHealth() << ")" << endl;

            while(!e->isDead() && player.getHealth() > 0){
                cout << "1. Attack\n2. Check Inventory" << endl;
                int choice;
                cin >> choice;

                if(choice == 1){
                    player.attack();
                    e->takeDamage(20);

                    if(!e->isDead()){
                        std::cout << "\nThe " << e->getName() << " swings back and deals " << e->attack() << " damage!" << std::endl;
                        player.takeDamage(e->attack());
                    }
                }
            }

            std::cout << e->getName() << " has been defeated!" << std::endl;
            current->removeEnemy();
        }

        if(current->getItem()){
            
        }
    }
}

