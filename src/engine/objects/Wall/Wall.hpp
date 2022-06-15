/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** TODO: add description
*/
#ifndef BOMBERMAN_WALL_HPP
#define BOMBERMAN_WALL_HPP

#include "GameObject.hpp"

namespace Indie {
    class Wall : public GameObject {
    public:
        explicit Wall(float x = 0, float y = 0, float z = 0):
        GameObject(x, y, z, Indie::WALL){};
        ~Wall()= default;
    };
}

#endif //BOMBERMAN_WALL_HPP
