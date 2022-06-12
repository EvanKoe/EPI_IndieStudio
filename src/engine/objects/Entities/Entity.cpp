/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** Entity
*/

#include "Entity.hpp"

int Entity::getHealth() const
{
    return _health;
}

int Entity::getCounter() const
{
    return _counter;
}

void Entity::movement(int direction)
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