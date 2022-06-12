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

class GameObject {
    public:
        GameObject(float x = 0, float y = 0, float z = 0, int id = 0):
            _x(x), _y(y), _z(z), _id(id)
        {};
        ~GameObject();
        int getId() const;
    protected:
        int _id;
        float _x;
        float _y;
        float _z;
    private:
};
