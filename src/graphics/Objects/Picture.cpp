 /*
** EPITECH PROJECT, 2022
** EPI_IndieStudio
** File description:
** Picture
*/

#include "Picture.hpp"
namespace Indie {
    Picture::Picture(std::string path, Vector2 pos, Vector2 size, float scale)
    {
        if (!std::filesystem::exists(std::filesystem::path(path))) {
            std::cout << path << ": no such file or directory" << std::endl;
            return;
        }
        _source = path;
        _textr = LoadTexture(_source.c_str());
        _pos = pos;
        _size = size;
        // _img = LoadImageFromTexture(_textr);
        _rec = { pos.x, pos.y, pos.x + size.x, pos.y + size.y };
    }

    void Picture::draw(void)
    {
        DrawTexture(_textr, _pos.x, _pos.y, WHITE);
    }

    void Picture::setPicture(std::string file)
    {
        _source = file;
        _textr = LoadTexture(file.c_str());
    }

    void Picture::unLoadPicture(void) {}

    Picture::~Picture() {}
};