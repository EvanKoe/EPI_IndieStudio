/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** Game Object
*/

#include "GameObject.hpp"

Indie::GameObject::GameObject(float x, float y, float z, game_object_id_e id):
    _x(x),
    _y(y),
    _z(z),
    _id(id),
    _sp(nullptr)
{
    for (auto e: textures_tab) {
        if (e.id == id) {
            _sp = new Sprite(0, e.path, e.texture, e.animate);
            break;
        }
    }
}

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

Indie::pos_t Indie::GameObject::getPosition(void) const
{
    pos_t position = { _x, _y, _z };
    return position;
}