/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** Power up
*/

#include "../GameObject.hpp"

#ifndef BOMBERMAN_POWERUP_HPP
#define BOMBERMAN_POWERUP_HPP

enum Attribute {
    BOMB_UP,
    SPEED_UP,
    FIRE_UP,
    BOMB_DOWN,
    SPEED_DOWN,
    FIRE_DOWN,
    WALL_PASS,
};

class PowerUp : public GameObject {
    public:
        PowerUp(Attribute attribute);
        ~PowerUp() = default;
        Attribute getAttribute();
    private:
        Attribute _attribute;

};

#endif //BOMBERMAN_POWERUP_HPP
