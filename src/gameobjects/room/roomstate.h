#ifndef ROOMSTATE_H
#define ROOMSTATE_H

#include <vector>

enum RoomObject {
    ROOM_OBJECT_NONE = 0,
    ROOM_OBJECT_DOOR = 1,
    ROOM_OBJECT_WALL = 2,
    ROOM_OBJECT_GRASS = 3,
    ROOM_OBJECT_ROCK = 4,
    ROOM_OBJECT_WATER = 5,
};

struct RoomData {
    int id;
    std::string name;
    std::string description;
    Position playerInitialPosition;
    int defaultRoomObjectMap[GAME_WINDOW_SIZE_Y][GAME_WINDOW_SIZE_X];
};


#endif