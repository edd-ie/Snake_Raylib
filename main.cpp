#include <iostream>
#include "raylib.h"

#include  "gameVar.h"
#include  "Game.h"

using namespace std;


int main()
{
    InitWindow((2*border)+cellSize*cellCount, (2*border)+cellSize*cellCount, "Vintage Snake");
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
