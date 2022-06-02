/*
** EPITECH PROJECT, 2022
** EPI_IndieStudio
** File description:
** Text
*/

#include "Text.hpp"

namespace Indie {
    Text::Text(std::string str, float x, float y, float size, Color col)
    {
        _font = GetFontDefault();
        _pos = (Vector2){ x, y };
        _col = col;
        _size = size;
        _value = std::string(str);
    }

    std::string Text::getText(void)
    {
        return _value;
    }

    void Text::setText(std::string str)
    {
        _value = str;
    }

    void Text::draw(void) {
        DrawText(_value.c_str(), _pos.x, _pos.y, _size, _col);
    }

    Text::~Text()
    {
        UnloadFont(_font);
    }
};
