/*
** EPITECH PROJECT, 2022
** EPI_IndieStudio
** File description:
** Button
*/

#include "Button.hpp"
#include <raylib.h>

namespace Indie {
    Button::Button(
        std::string str,
        std::function<void (void)> fun,
        Vector2 pos,
        Vector2 size,
        Color textColor,
        Color hoverColor
    ) {
        _text = str;
        _hoverColor = hoverColor;
        _color = textColor;
        _rec = { pos.x, pos.y, size.x, size.y };
        _onClick = fun;
        _name = str;
    }

    void Button::setPosition(Vector2 pos) {
        _rec = { pos.x, pos.y, _rec.width, _rec.height };
    }

    Vector2 Button::getPosition(void) {
        return (Vector2){ _rec.x, _rec.y };
    }

    void Button::setText(std::string str)
    {
        _text = str;
    }

    void Button::setHover(void) {
        DrawText(_text.c_str(), _rec.x, _rec.y, 30, _hoverColor);
    }

    void Button::draw(void) {
        DrawText(_text.c_str(), _rec.x, _rec.y, 30, _color);
    }

    std::string Button::getText(void)
    {
        return _text;
    }

    void Button::setDisabled(bool b)
    {
        _is_enabled = b;
    }

    bool Button::isDisabled(void)
    {
        return _is_enabled;
    }

    Button::~Button() {}
};
