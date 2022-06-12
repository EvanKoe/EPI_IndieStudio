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

class GameObject {
    public:
        GameObject(float x = 0, float y = 0, float z = 0, int id = -1):
            _x(x), _y(y), _z(z), _id(id)
        {};
        ~GameObject();
        float getX() const;
        float getY() const;
        float getZ() const;
        std::vector<float> getPosition() const;
        virtual void setX(float x) = 0;
        virtual void setY(float y) = 0;
        virtual void setZ(float z) = 0;
        virtual int getId() const;
    protected:
        float _x;
        float _y;
        float _z;
        int _id;

    private:
};
