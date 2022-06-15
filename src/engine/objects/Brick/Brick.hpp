/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** Bricks
*/
#include "GameObject.hpp"

#ifndef BOMBERMAN_BRICK_HPP
#define BOMBERMAN_BRICK_HPP

namespace Indie{

    class Brick : public Indie::GameObject {
    public:
        explicit Brick(float x = 0, float y = 0, float z = 0):
        GameObject(x, y, z, Indie::BRICK){};
        ~Brick() = default;
    };
}

#endif //BOMBERMAN_BRICK_HPP
