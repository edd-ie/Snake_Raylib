//
// Created by _edd.ie_ on 28/05/2024.
//

#ifndef GAMEVAR_H
#define GAMEVAR_H

//Game Fps
inline int game_fps = 45;

//Game state
inline bool paused = false;
inline bool gameOver = false;

// Game theme:
inline Color green = {173,204,96,255};
inline Color darkGreen = {43, 51, 24, 255};

// Game grid:
inline int cellSize = 20;
inline int cellCount = 30;
inline float border = 50;
inline float offset = 19;;

// Game actions timer
inline double lastUpdatetime = 0;
inline double snakeUpdateInterval = 0.2; //seconds
inline int score = 0;

//Eating action
inline bool eatFood = false;

#endif //GAMEVAR_H
