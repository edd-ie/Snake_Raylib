//
// Created by _edd.ie_ on 28/05/2024.
//

#ifndef FOOD_H
#define FOOD_H

#include  "gameVar.h"

class Food
{
    Vector2 pos{};
    Texture2D texture;

public:
    Food()
    {
        pos = {5,6};

        const Image image = LoadImage("../graphics/food.png");
        texture = LoadTextureFromImage(image);
        UnloadImage(image);
    }

    ~Food()
    {
        UnloadTexture(texture);
    }

    void Draw() const
    {
        // DrawRectangle(pos.x*cellSize, pos.y*cellSize, cellSize, cellSize, darkGreen);
        DrawTexture(texture, pos.x*cellSize, pos.y*cellSize, WHITE);
    }
};

#endif //FOOD_H
