#include <iostream>
#include "raylib.h"

#include  "gameVar.h"
#include "Food.h"
#include "Snake.h"

using namespace std;


int main()
{
    InitWindow(cellSize*cellCount, cellSize*cellCount, "Vintage Snake");
    SetTargetFPS(game_fps);

    Food food = Food();
    Snake snake = Snake();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(green);

        // Object rendering
        food.Draw();
        snake.Draw();

        // Snake motion
        if(eventTriggered(snakeUpdateInterval))
        {
            snake.Update();
        }

        //Event listeners
        if(IsKeyPressed(KEY_SPACE))
        {
            paused = !paused;
        }

        snake.changeDirection();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
