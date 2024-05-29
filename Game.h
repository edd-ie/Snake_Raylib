//
// Created by _edd.ie_ on 29/05/2024.
//

#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "gameVar.h"
#include "Snake.h"
#include "Food.h"

class  Game{
    static bool eventTriggered(const double interval)
    {
        if(const double currentTime = GetTime(); currentTime-lastUpdatetime >= interval)
        {
            lastUpdatetime = currentTime;
            return true;
        }
        return false;
    }

    static void changeFPS(const int fps)
    {
        game_fps = (fps>120) ? 120 :
                    (fps < 12) ? 12: fps;
    }

public:
    //Objects
    Food food = Food();
    Snake snake = Snake();

    Game(){
        SetTargetFPS(game_fps);
    }


    void Draw()
    {
        //Game Background
        ClearBackground(green);

        // Object rendering
        food.Draw();
        snake.Draw();
    }

    void Actions()
    {
        //Drawing on the canvas
        Draw();

        // Snake motion
        if(eventTriggered(snakeUpdateInterval))
        {
            snake.Update();
        }

        // Event Listeners
        checkKeyPresses();
    }

    void checkKeyPresses()
    {
        //Event listeners
        if(IsKeyPressed(KEY_SPACE))
        {
            paused = !paused;
        }

        snake.changeDirection();
    }




};

#endif //GAME_H
