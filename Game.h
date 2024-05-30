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
    Snake snake = Snake();
    Food food = Food(snake.body);

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
            checkSnakeCollision();
            check_food_collision();
            snake.Update(eatFood);
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

        if (gameOver){
            if(IsKeyPressed(KEY_A)||IsKeyPressed(KEY_D)||
                IsKeyPressed(KEY_S)||IsKeyPressed(KEY_W) ||
                IsKeyPressed(KEY_UP)||IsKeyPressed(KEY_DOWN)||
                IsKeyPressed(KEY_LEFT)||IsKeyPressed(KEY_RIGHT)
                ) gameOver = false;
        }
    }

    void check_food_collision()
    {
        if(Vector2Equals(snake.body[0], food.getPos()))
        {
            std::cout << "Eating";
            food.setPos(snake.body);
            eatFood = true;
        }
        else eatFood = false;
    }

    void checkSnakeCollision()
    {
        snake.checkBorderCollision();
        snake.checkBodyCollision();
        if(gameOver) GameOver();
    }

    void GameOver()
    {
        snake.reset();
        Food::GenerateRandomPos(snake.body);
    }

};

#endif //GAME_H
