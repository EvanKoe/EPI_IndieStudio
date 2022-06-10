/*
** EPITECH PROJECT, 2022
** EPI_IndieStudio
** File description:
** Text
*/

#include "Text.hpp"
#include <bits/types/__sigset_t.h>
#include <raylib.h>

namespace Indie {
    Text::Text(std::string str, float x, float y, float size, Color col)
    {
        _pos = (Vector2){ x, y };
        _col = col;
        _size = size;
        _value = std::string(str);
    }

    std::string Text::getText(void)
    {
        return _value;
    }

    Rectangle Text::getRect(void)
    {
        float a = _size * _value.size();
        float b = _size * 2;
        Rectangle c = { _pos.x, _pos.y, a, b };

        return c;
    }

    void Text::setText(std::string str)
    {
        _value = str;
    }

    void Text::draw(void)
    {
        DrawText(_value.c_str(), _pos.x, _pos.y, _size, _col);
    }

    Text::~Text() {}
};
