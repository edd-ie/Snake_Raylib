//
// Created by _edd.ie_ on 28/05/2024.
//

#ifndef FOOD_H
#define FOOD_H

#include  "gameVar.h"

class Food
{
    Vector2 pos{};

public:
    Food()
    {
        pos = {5,6};
    }

    void Draw() const
    {
        DrawRectangle(pos.x*cellSize, pos.y*cellSize, cellSize, cellSize, darkGreen);
    }
};

#endif //FOOD_H
