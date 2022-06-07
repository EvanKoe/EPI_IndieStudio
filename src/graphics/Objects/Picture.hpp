/*
** EPITECH PROJECT, 2022
** EPI_IndieStudio
** File description:
** Image
*/

#include "IGraphic.hpp"

#pragma once

class Picture {
    public:
        Picture(Image, Texture2D, std::string*, Vector2);
        void display();
        void loadPicture(void);
        void setPicture(std::string *file);
        void unloadPicture(Image img);
        ~Picture();

    protected:
    private:
        std::string *_source;
        Image _img;
        Texture2D _textr;
        Vector2 _pos;
};