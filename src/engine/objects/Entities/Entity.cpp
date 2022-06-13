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

int Indie::Entity::getCounter() const
{
    return _counter;
}

void Indie::Entity::movement(int direction)
{
    switch (direction) {
        case Indie::UP:
            _y += _speed;
            break;
        case Indie::DOWN:
            _y -= _speed;
            break;
        case Indie::LEFT:
            _x -= _speed;
            break;
        case Indie::RIGHT:
            _x += _speed;
            break;
        default:
            break;
    }
}