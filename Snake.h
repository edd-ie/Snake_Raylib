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

    Rectangle segment{};
    Vector2 direction{};

public:
    std::deque<Vector2> body; //Linked list
    Snake()
    {
        body = {Vector2{6,9}, Vector2{5,9}, Vector2{4,9}};
        direction = Vector2(1,0); // Moves to the right
    }

    // std::deque<Vector2> getBody()
    // {
    //     return body;
    // }

    void Draw()
    {
        for(Vector2& i : body)
        {
            segment = Rectangle(border+i.x*static_cast<float>(cellSize),
                border + i.y*static_cast<float>(cellSize),
                static_cast<float>(cellSize),
                static_cast<float>(cellSize));

            DrawRectangleRounded(segment, 0.5, 6, darkGreen);
        }
    }

    /**
     * This handles the moving of the snake
     * It removes the last node in the deque/linkedList
     * checks the direction
     * Adds a new node at the front in the direction specified
     */
    void Update(const bool eaten)
    {
        if(!paused){
            body.push_front(Vector2Add(body[0],direction));
            if(!eaten) body.pop_back();
        }
    }


    void changeDirection()
    {
        if(!paused && !gameOver){
            if((IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) && direction.y != 1)
            {
                direction = Vector2{0,-1};
            }

            if((IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) && direction.y != -1)
            {
                direction = Vector2{0,1};
            }

            if((IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) && direction.x != 1)
            {
                direction = Vector2{-1,0};
            }

            if((IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) && direction.x != -1)
            {
                direction = Vector2{1,0};
            }
        }
    }


    static bool bodyCollision(Vector2 node, std::deque<Vector2> body)
    {
        bool found = false;
        for(unsigned int i = 0; i<body.size() && !found; i++)
        {
            found = Vector2Equals(node, body[i]);
        }
        return found;
    }

    void checkBorderCollision()
    {
        //x-axis & y-axis
        if(body[0].x == static_cast<float>(cellCount) || body[0].x == -1 || body[0].y == static_cast<float>(cellCount) || body[0].y == -1)
        {
            gameOver = true;
        }
    }

    void reset()
    {
        body = {Vector2{6,9}, Vector2{5,9}, Vector2{4,9}};
        direction = Vector2(1,0); // Moves to the right
    }

    void checkBodyCollision()
    {
        std::deque<Vector2> copy = body;
        copy.pop_front();
        if(bodyCollision(body[0],copy))
        {
            gameOver = true;
        }

    }

};

#endif //SNAKE_H
