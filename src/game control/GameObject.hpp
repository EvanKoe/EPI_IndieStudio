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
        GameObject(float px = 0, float py = 0, float vx = 0, float vy = 0, int id = 0) {
            _position.x = px;
            _position.y = py;
            _velocity.x = vx;
            _velocity.y = vy;
            _id = id;
        };
        ~GameObject();
        int getId() const;
    protected:
        int _id;
        Position _position;     // position
        Position _velocity;     // velocity
    private:
};
