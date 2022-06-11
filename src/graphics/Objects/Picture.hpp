/*
** EPITECH PROJECT, 2022
** EPI_IndieStudio
** File description:
** Image
*/

#include "../IGraphic.hpp"
#include <raylib.h>
#include <filesystem>
#include <iostream>
#include <unistd.h>

#pragma once

namespace Indie {
    class Picture: public IGraphic {
    public:
        Picture(
            std::string path,
            Vector2 pos = { 0, 0 },
            Vector2 size = { 0, 0 },
            float scale = 1.0
        );
        void draw(void) override;
        void setPicture(std::string file);
        void unLoadPicture(void);
        Rectangle getRect(void) override { return _rec; }
        bool isHover(void) override { return false; };
        void onHover(void) override { return; }
        void onHoverEnd(void) override { return; }
        void onClick(void) override { return; }
        bool getIs3D(void) override { return false; }
        ~Picture();

    private:
        std::string _source;
        Image _img;
        Texture2D _textr;
        Vector2 _pos;
        Vector2 _size;
        Rectangle _rec;
    };
}