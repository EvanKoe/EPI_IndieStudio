/*
** EPITECH PROJECT, 2022
** EPI_IndieStudio
** File description:
** Button
*/

#include "Button.hpp"

namespace Indie {
    Button::Button(std::string str)
    {
        _name = str;
    }

    void Button::setText(std::string str)
    {
        _text = str;
    }

    std::string Button::getText(void)
    {
        return "AAAAAAAAAA";
    }

    void Button::setDisabled(bool)
    {

    }

    bool Button::isDisabled(void)
    {
        return false;
    }
    
    Button::~Button()
    {
    }
};