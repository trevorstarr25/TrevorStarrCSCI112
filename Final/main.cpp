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
    r1->setItem(new Item("Health Potion", 25));

    r2->setItem(new Item("Health Potion", 25));
    r2->setEnemy(new Enemy("Orc", 50, 25));

    r3->setEnemy(new Enemy("Dragon", 100, 20));
    r3->setItem(new Item("Health Potion", 25));

    dungeon.addRoom(r1);
    dungeon.addRoom(r2);
    dungeon.addRoom(r3);

    Room* current = dungeon.getHead();

    while(current != nullptr){
        cout << "--- " << current->getDescription() << "---" << endl;

        if(current->getEnemy()){
            Enemy* e = current->getEnemy();
            cout << "An enemy appears and blocks your path: " << e->getName() << " (HP: " << e->getHealth() << ")" << endl;

            while(!e->isDead() && player.getHealth() > 0){
                cout << "1. Attack\n2. Check Inventory" << endl;
                int choice;
                std::cin >> choice;

                if(choice == 1){
                    player.attack();
                    e->takeDamage(20);

                    if(!e->isDead()){
                        std::cout << "\nThe " << e->getName() << " swings back and deals " << e->attack() << " damage!" << std::endl;
                        player.takeDamage(e->attack());
                    }
                }
                else if(choice == 2){
                    player.showInventory();

                    if(player.getInventory().empty()){
                        std::cout << "You have nothing in your inventory." << std::endl;
                    }
                    else{
                        std::cout << "Would you like to use a potion? (y/n): ";
                        char p;
                        cin >> p;

                        if(p =='y'){
                            Item* potion = player.getInventory()[0];

                            int healAmount = potion->getEffect();
                            player.heal(healAmount);

                            player.getInventory().erase(player.getInventory().begin());
                        }
                    }
                }
            }

            std::cout << e->getName() << " has been defeated!\n" << std::endl;
            current->removeEnemy();
        }

        if(current->getItem()){
            Item* i = current->getItem();
            std::cout << "You found an item: " << i->getName() << std::endl;

            player.addToInventory(i);
            current->removeItem();
        }

        if(current->getNext() == nullptr){
            std::cout << "\nYou have reached the treasure room! Enjoy your loot.\n" << std::endl;
            break;
        }

        std::cout << "\nMove to next room? (y/n): ";
        char c;
        cin >> c;
        if(c == 'y'){
            current = current->getNext();
        }
        else{
            cout << "You give up and turn tail to run.\n";
            break;
        }
    }

    return 0;
}

