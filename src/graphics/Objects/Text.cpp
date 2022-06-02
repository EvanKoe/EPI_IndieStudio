/*
** EPITECH PROJECT, 2022
** EPI_IndieStudio
** File description:
** Text
*/

#include "Text.hpp"

namespace Indie {
    Text::Text(std::string str, int x = 0, int y = 0, int size = 20, Color col = LIGHTGRAY)
    {
        _font = GetFontDefault();
        _pos = (Vector2){ x, y };
        _col = col;
        _size = size
        _value = str;
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
        DrawText(_value, _pos.x, _pos.y, _size, _col);
    }
    
    Text::~Text()
    {
        if (_font)
            UnloadFont(_font);
    }
};