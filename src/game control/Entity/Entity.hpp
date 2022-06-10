/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** Entity.hpp
*/

#include "../Globals.hpp"
#include "GameObject.hpp"

#ifndef BOMBERMAN_ENTITY_HPP
#define BOMBERMAN_ENTITY_HPP

class Entity : public GameObject {
public:
    Entity(int health);
    ~Entity() = default;
protected:
    int _health;

private:
};

#endif //BOMBERMAN_ENTITY_HPP
