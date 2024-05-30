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



public:
    Food(const std::deque<Vector2>& snakeBody)
    {
        pos = GenerateRandomPos(snakeBody);

        const Image image = LoadImage("../graphics/food.png");
        texture = LoadTextureFromImage(image);
        UnloadImage(image);
    }

    ~Food()
    {
        UnloadTexture(texture);
    }

    static Vector2 GenerateRandomPos(const std::deque<Vector2>& body)
    {
        int x = GetRandomValue(0, cellCount-1);
        int y = GetRandomValue(0, cellCount-1);

        Vector2 newPos = {static_cast<float>(x), static_cast<float>(y)};
        while(Snake::bodyCollision(newPos, body))
        {
            x = GetRandomValue(0, cellCount-1);
            y = GetRandomValue(0, cellCount-1);

            newPos = {static_cast<float>(x), static_cast<float>(y)};
        }

        return newPos;
    }

    void Draw() const
    {
        DrawTexture(texture, static_cast<int>(pos.x)*cellSize, static_cast<int>(pos.y)*cellSize, WHITE);
    }

    Vector2 getPos()
    {
        return pos;
    }

    void setPos(const std::deque<Vector2>& body)
    {
        pos = GenerateRandomPos(body);
    }
};

#endif //FOOD_H
