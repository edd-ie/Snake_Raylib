#include <iostream>
#include "raylib.h"

#include  "gameVar.h"
#include  "Game.h"

using namespace std;


int main()
{
    InitWindow(cellSize*cellCount, cellSize*cellCount, "Vintage Snake");
    Game game = Game();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        game.Draw();

        game.Actions();

        game.checkKeyPresses();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
