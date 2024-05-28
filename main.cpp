#include <iostream>
#include "raylib.h"
#include  "gameVar.h"
#include "Food.h"

using namespace std;


int main()
{
    InitWindow(cellSize*cellCount, cellSize*cellCount, "Vintage Snake");
    SetTargetFPS(game_fps);

    Food food = Food();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(green);

        food.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
