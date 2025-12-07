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
    Room* r3 = new Room("A room with a large chest. A troll guards it!");

    r1->setEnemy(new Enemy("Goblin", 30, 5));
    r2->setItem(new Item("Health Potion", 25));
    r3->setEnemy(new Enemy("Dragon", 100, 20));

    dungeon.addRoom(r1);
    dungeon.addRoom(r2);
    dungeon.addRoom(r3);
}

