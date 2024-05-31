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
    Sound eatSound;
    Sound wallSound;

    Game(){
        SetTargetFPS(game_fps);
        InitAudioDevice();
        eatSound = LoadSound("../Audio/crunchy.wav");
        wallSound = LoadSound("../Audio/wall.mp3");
    }

    ~Game()
    {
        UnloadSound(eatSound);
        UnloadSound(wallSound);
        CloseAudioDevice();
    }

    void displayText()
    {
        if(!paused)
        {
            DrawText("Vintage Snake",
                static_cast<int>(offset)+10, 4, 25, darkGreen);
        }

        DrawText(TextFormat("Score = %i", score),
                (cellSize*cellCount)-(static_cast<int>(offset)+40), 6, 22, darkGreen);
    }

    void Draw()
    {
        //Game Background
        ClearBackground(green);

        displayText();

        //Renering the game borders
        DrawRectangleLinesEx(Rectangle(border-offset,
            border-offset,
            static_cast<float>(cellSize*cellCount)+(offset*2),
            static_cast<float>(cellSize*cellCount)+(offset*2)),
            6,darkGreen);

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
            PlaySound(eatSound);
            score++;
        }
        else eatFood = false;
    }

    void checkSnakeCollision()
    {
        snake.checkBorderCollision();
        snake.checkBodyCollision();
        if(gameOver) {
            // PlaySound(wallSound);
            GameOver();
        }
    }

    void GameOver()
    {
        snake.reset();
        Food::GenerateRandomPos(snake.body);
        score = 0;
    }

};

#endif //GAME_H
