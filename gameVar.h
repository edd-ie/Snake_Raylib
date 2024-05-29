//
// Created by _edd.ie_ on 28/05/2024.
//

#ifndef GAMEVAR_H
#define GAMEVAR_H

//Game Fps
inline int game_fps = 30;

// Game theme:
inline Color green = {173,204,96,255};
inline Color darkGreen = {43, 51, 24, 255};

// Game grid:
inline int cellSize = 20;
inline int cellCount = 30;

// Game actions timer
inline double lastUpdatetime = 0;
inline double snakeUpdateInterval = 0.3; //seconds

inline bool eventTriggered(const double interval)
{
    if(const double currentTime = GetTime(); currentTime-lastUpdatetime >= interval)
    {
        lastUpdatetime = currentTime;
        return true;
    }
    return false;
}

#endif //GAMEVAR_H
