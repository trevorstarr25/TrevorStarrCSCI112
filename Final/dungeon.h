#pragma once
#include "room.h"

class Dungeon{
    private:
        Room* head;

    public:
        Dungeon();
        void addRoom(Room* room);
        Room* getHead();
};
