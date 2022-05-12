/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** GameObject
*/

#pragma once

#include <iostream>
#include <list>
#include <map>

typedef struct {
    float x;
    float y;
} Position;

class GameObject {
    public:
        GameObject(float px = 0, float py = 0, float vx = 0, float vy = 0) {
            pos.x = px;
            pos.y = py;
            vel.x = vx;
            vel.y = vy;
        };
        ~GameObject();

    protected:
        Position pos;     // position
        Position vel;     // velocity
    private:
};
