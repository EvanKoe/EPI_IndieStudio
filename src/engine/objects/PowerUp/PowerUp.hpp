/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** Power up
*/

#include "../GameObject.hpp"

#ifndef BOMBERMAN_POWERUP_HPP
#define BOMBERMAN_POWERUP_HPP

class PowerUp : public GameObject {
    public:
        PowerUp(Indie::PowerUpAttribute attribute, float x = 0, float y = 0, float z = 0):
            GameObject(x, y, z, Indie::POWERUP),
            _attribute(attribute)
        {};
        ~PowerUp() = default;
        Indie::PowerUpAttribute gatAttribute();
    private:
        Indie::PowerUpAttribute _attribute;

};

#endif //BOMBERMAN_POWERUP_HPP
