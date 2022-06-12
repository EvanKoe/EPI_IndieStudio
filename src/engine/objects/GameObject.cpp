/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** Game Object
*/

#include "GameObject.hpp"

int GameObject::getId() const
{
    return _id;
}

float GameObject::getX() const
{
    return _x;
}

float GameObject::getY() const
{
    return _y;
}

float GameObject::getZ() const
{
    return _z;
}

void GameObject::setX(float x)
{
    _x = x;
}

void GameObject::setY(float y)
{
    _y = y;
}

void GameObject::setZ(float z)
{
    _z = z;
}

std::vector<float> GameObject::getPosition() const
{
    std::vector<float> position;
    position.push_back(_x);
    position.push_back(_z);
    return position;
}