/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** GameObject
*/

#pragma once

#include <iostream>
#include <list>
#include <map>
#include <vector>
#include "../Globals.hpp"

namespace Indie {
    class GameObject {
    public:
        GameObject(float x = 0, float y = 0, float z = 0, Indie::game_object_id_e id = Indie::NONE)
            : _x(x), _y(y), _z(z), _id(id){};
        ~GameObject();
        float getX() const;
        float getY() const;
        float getZ() const;
        std::vector<float> getPosition() const;
        void setX(float x);
        void setY(float y);
        void setZ(float z);
        int getId() const;

    protected:
        float _x;
        float _y;
        float _z;
        int _id;

    private:
    };
}
