/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** Bricks
*/
#include "GameObject.hpp"

#ifndef BOMBERMAN_BRICK_HPP
#define BOMBERMAN_BRICK_HPP

class Brick : public Indie::GameObject {
public:
    explicit Brick(float x = 0, float y = 0, float z = 0):
    GameObject(x, y, z, Indie::BRICK){};
};

#endif //BOMBERMAN_BRICK_HPP
