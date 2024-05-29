//
// Created by _edd.ie_ on 29/05/2024.
//

#ifndef GAME_H
#define GAME_H
#include "raylib.h"

struct Game{

    //Game Fps
    int game_fps;

    //Game state
    bool paused;

    // Game theme:
    Color green;
    Color darkGreen;

    // Game grid:
    int cellSize;
    int cellCount;

    // Game actions timer
    double lastUpdatetime;
    double snakeUpdateInterval; //seconds

    Game(){
        game_fps = 30;
        paused = false;
        green = {173,204,96,255};
        darkGreen = {43, 51, 24, 255};
        cellSize = 20;
        cellCount = 30;
        lastUpdatetime = 0;
        snakeUpdateInterval = 0.3; //seconds
    }


    bool eventTriggered(const double interval)
    {
        if(const double currentTime = GetTime(); currentTime-lastUpdatetime >= interval)
        {
            lastUpdatetime = currentTime;
            return true;
        }
        return false;
    }

};

#endif //GAME_H
