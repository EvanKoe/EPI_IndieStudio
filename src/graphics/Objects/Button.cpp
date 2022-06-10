/*
** EPITECH PROJECT, 2022
** EPI_IndieStudio
** File description:
** Button
*/

#include "Button.hpp"
#include <raylib.h>
#include <iostream>

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
        _hcolor = hoverColor;
        _ncolor = textColor;
        _color = _ncolor;
        _rec = { pos.x, pos.y, size.x, size.y };
        _onClick = fun;
        _name = str;
        _is_enabled = true;
        _borderColor = LIGHTGRAY;
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

    void Button::onHover(void) {
        if (!_is_enabled) {
            return;
        }
        _color = _hcolor;
        _borderColor = _hcolor;
    }

    void Button::onHoverEnd(void) {
        _color = _ncolor;
        _borderColor = LIGHTGRAY;
    }

    void Button::draw(void) {
        DrawRectangleRec(_rec, LIGHTGRAY);
        DrawText(_text.c_str(),
            _rec.x + (_rec.width / 2) - (_text.length() * 5),
            _rec.y + (_rec.height / 2 - 15),
            30, _color);
        DrawRectangleLinesEx(_rec, 4, _borderColor);
    }

    bool Button::isHover(void) {
        Rectangle r = getRect();
        return (
            r.x < GetMouseX() && GetMouseX() < r.x + r.width &&
            r.y < GetMouseY() && GetMouseY() < r.y + r.height
        );
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
