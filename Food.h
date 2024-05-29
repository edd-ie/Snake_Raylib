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
        int x = GetRandomValue(0, cellCount-1);
        int y = GetRandomValue(0, cellCount-1);

        return Vector2{static_cast<float>(x), static_cast<float>(y)};
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
        DrawTexture(texture, static_cast<int>(pos.x)*cellSize, static_cast<int>(pos.y)*cellSize, WHITE);
    }
};

#endif //FOOD_H
