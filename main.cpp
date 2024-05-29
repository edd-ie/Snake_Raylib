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

        food.Draw();
        snake.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
