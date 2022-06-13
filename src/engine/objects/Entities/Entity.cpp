/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** Entity
*/

#include "Entity.hpp"

int Indie::Entity::getHealth() const
{
    return _health;
}

void Indie::Entity::movement(int direction)
{
    switch (direction) {
        case Indie::UP:
            _y += float(_speed);
            break;
        case Indie::DOWN:
            _y -= float(_speed);
            break;
        case Indie::LEFT:
            _x -= float(_speed);
            break;
        case Indie::RIGHT:
            _x += float(_speed);
            break;
        default:
            break;
    }
}