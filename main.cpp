#include <iostream>
#include "raylib.h"

using namespace std;

// Game theme:
Color green = {173,204,96,255};
Color darkGreen = {43, 51, 24, 255};

// Game grid:
int cellSize = 30;
int cellCount = 24;

int main()
{
    InitWindow(cellSize*cellCount, cellSize*cellCount, "Vintage Snake");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(green);


        EndDrawing();
    }

    CloseWindow();
    return 0;
}
