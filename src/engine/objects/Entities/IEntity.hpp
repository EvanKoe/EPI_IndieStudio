/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** Entities.hpp
*/

#include "../Globals.hpp"
#include "engine/objects/GameObject.hpp"

#ifndef BOMBERMAN_ENTITY_HPP
#define BOMBERMAN_ENTITY_HPP

class IEntity : public GameObject {
public:
    IEntity()
    : GameObject(),
    _health(0)
    {_counter ++;};
    virtual ~IEntity() {_counter --;};
    virtual void movement(void) = 0;
protected:
    int _health;
    static int _counter;
private:
};

#endif //BOMBERMAN_ENTITY_HPP
