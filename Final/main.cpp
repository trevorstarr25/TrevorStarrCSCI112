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
}

