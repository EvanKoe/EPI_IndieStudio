/*
** EPITECH PROJECT, 2022
** EPI_IndieStudio
** File description:
** Mouse
*/

#include "Mouse.hpp"
#include <list>
#include <raylib.h>

namespace Indie {
    Mouse::Mouse(int x, int y)
    {
        x = _pos.x;
        y = _pos.y;
    }

    Vector2 Mouse::getPos(void)
    {
        _pos.x = static_cast<float>(GetMouseX());
        _pos.y = static_cast<float>(GetMouseY());
        return _pos;
    }

    Mouse::~Mouse()
    {
    }
};

