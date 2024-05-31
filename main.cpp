#include <iostream>
#include "raylib.h"

#include  "gameVar.h"
#include  "Game.h"

using namespace std;


int main()
{
    InitWindow(static_cast<int>(2*border)+cellSize*cellCount,
        static_cast<int>(2*border)+cellSize*cellCount,
        "Vintage Snake");
    Game game = Game();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        game.Actions();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
