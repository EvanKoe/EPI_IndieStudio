/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** Entities.hpp
*/

#include "../GameObject.hpp"

#ifndef BOMBERMAN_ENTITY_HPP
#define BOMBERMAN_ENTITY_HPP

namespace Indie{
    class Entity : public GameObject {
    public:
        Entity() = delete;
        ~Entity() { _counter--; }
        int getHealth() const;
        int getCounter() const;
        void movement(int direction);

    protected:
        explicit Entity(float x = 0, float y = 0, float z = 0, int health = 1, Indie::GameObjectsIds id = Indie::NONE)
            : GameObject(x, y, z, id),
              _health(health),
              _speed(1)
        {
            _counter++;
        };
        int _health;
        int _speed;
        static int _counter;

    private:
    };
}

#endif //BOMBERMAN_ENTITY_HPP
