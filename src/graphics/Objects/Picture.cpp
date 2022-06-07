/*
** EPITECH PROJECT, 2022
** EPI_IndieStudio
** File description:
** Picture
*/

#include "IGraphic.hpp"
#include "Picture.hpp"

#pragma once

namespace Indie {
    Picture::Picture(Image img, Texture2D textr, std::string *file, Vector2 vec)
    {
        _source = file;
        _img = img;
        _textr = textr;
        _pos.x = vec.x;
        _pos.y = vec.y;

        display();
    }

    void Picture::display(void)
    {
        loadPicture();
        ClearBackground(RAYWHITE);
        DrawTexture(_textr, _pos.x, _pos.y, RAYWHITE);

    }
    void Picture::loadPicture()
    {
        _img = LoadImage(_source->c_str());
        _textr = LoadTextureFromImage(_img);

        // Is texture necessary ?
    }

    void Picture::setPicture(std::string *file)
    {
        _source = file;
        _img = LoadImage(_source->c_str());
    }

    void unloadPicture(Image img)
    {
        unloadPicture(img);
    }

    Picture::~Picture()
    {
        unloadPicture(_img);
        UnloadTexture(_textr);

        // Should it  appear in  destructor only ?
    }
};