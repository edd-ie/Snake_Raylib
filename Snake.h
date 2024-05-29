//
// Created by _edd.ie_ on 28/05/2024.
//

#ifndef SNAKE_H
#define SNAKE_H

#include "gameVar.h"
#include "deque"
#include "raymath.h"

class Snake
{
    std::deque<Vector2> body; //Linked list
    Rectangle segment{};
    Vector2 direction{};

public:
    Snake()
    {
        body = {Vector2{6,9}, Vector2{5,9}, Vector2{4,9}};
        direction = Vector2(1,0); // Moves to the right
    }

    void Draw()
    {
        for(Vector2& i : body)
        {
            segment = Rectangle(i.x*static_cast<float>(cellSize), i.y*static_cast<float>(cellSize),
                static_cast<float>(cellSize), static_cast<float>(cellSize));
            DrawRectangleRounded(segment, 0.5, 6, darkGreen);
        }
    }

    /**
     * This handles the moving of the snake
     * It removes the last node in the deque/linkedList
     * checks the direction
     * Adds a new node at the front in the direction specified
     */
    void Update()
    {
        body.pop_back();
        body.push_front(Vector2Add(body[0],direction));
    }

};

#endif //SNAKE_H
