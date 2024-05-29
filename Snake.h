//
// Created by _edd.ie_ on 28/05/2024.
//

#ifndef SNAKE_H
#define SNAKE_H

#include "gameVar.h"
#include "deque"

class Snake
{
    std::deque<Vector2> body;

public:
    Snake()
    {
        body = {Vector2{6,9}, Vector2{5,9}, Vector2{4,9}};
    }

    void Draw()
    {
        for(Vector2& i : body)
        {
            DrawRectangle(i.x*cellSize, i.y*cellSize, cellSize, cellSize, darkGreen);
        }
    }

};

#endif //SNAKE_H
