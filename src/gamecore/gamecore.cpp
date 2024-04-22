#include "gamecore.h"
#include "gamestate.h"
#include "../controller/controller.h"

GameCore::GameCore() {
    
}

GameCore::~GameCore() {
    
}

GameState GameCore::lifeCycle(InputState action) {
    return gameController.run(action);
}

InputState GameCore::ConvertInputToAction(int input) {
    switch (input) {
        case 'w':
        case 'W':
            return GAME_ACTION_UP;
        case 's':
        case 'S':
            return GAME_ACTION_DOWN;
        case 'a':
        case 'A':
            return GAME_ACTION_LEFT;
        case 'd':
        case 'D':
            return GAME_ACTION_RIGHT;

        case 32: // space
            return GAME_ACTION_CONFIRN;
        case 10: // enter
            return GAME_ACTION_CONFIRN;

        case -1:
            return GAME_ACTION_INIT;

        default:
            return GAME_ACTION_NONE;
    }
}