#include "dungeon.h"

Dungeon::Dungeon(){
    head = nullptr;
}

void Dungeon::addRoom(Room* room){
    if(!head){
        head = room;
        return;
    }

    Room* temp = head;
    while(temp->getNext() != nullptr)
        temp = temp->getNext();

    temp->setNext(room);
}

Room* Dungeon::getHead(){
    return head;
}
