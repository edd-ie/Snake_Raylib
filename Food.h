//
// Created by _edd.ie_ on 28/05/2024.
//

#ifndef FOOD_H
#define FOOD_H

#include  "gameVar.h"

class Food
{
    Vector2 pos{};
    Texture2D texture{};

    static Vector2 GenerateRandomPos()
    {
        float x = GetRandomValue(0.0f, cellCount-1);
        float y = GetRandomValue(0.0f, cellCount-1);

        return Vector2{x, y};
    }

public:
    Food()
    {
        pos = GenerateRandomPos();

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
        DrawTexture(texture, pos.x*cellSize, pos.y*cellSize, WHITE);
    }
};

#endif //FOOD_H
