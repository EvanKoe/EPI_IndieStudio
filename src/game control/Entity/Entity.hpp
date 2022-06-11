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

enum EntityType {
    PLAYER,
    IA
};

class Entity : public GameObject {
public:
    virtual ~Entity() = default;
    virtual int getEvents(void) = 0;
    virtual int movement(int) = 0;
    virtual int dropBomb(void) = 0;
protected:
    int _health;

private:
};

#endif //BOMBERMAN_ENTITY_HPP
