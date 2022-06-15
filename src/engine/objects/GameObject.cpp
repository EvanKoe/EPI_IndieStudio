/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** Game Object
*/

#include "GameObject.hpp"

Indie::GameObjectsIds Indie::GameObject::getId() const
{
    return _id;
}

float Indie::GameObject::getX() const
{
    return _x;
}

float Indie::GameObject::getY() const
{
    return _y;
}

float Indie::GameObject::getZ() const
{
    return _z;
}

void Indie::GameObject::setX(float x)
{
    _x = x;
}

void Indie::GameObject::setY(float y)
{
    _y = y;
}

void Indie::GameObject::setZ(float z)
{
    _z = z;
}

std::vector<float> Indie::GameObject::getPosition() const
{
    std::vector<float> position;
    position.push_back(_x);
    position.push_back(_y);
    position.push_back(_z);
    return position;
}