/*
** EPITECH PROJECT, 2022
** EPI_IndieStudio
** File description:
** Sprite
*/

#include "Sprite.hpp"
#include <raylib.h>
#include <unistd.h>

namespace Indie {
    Sprite::Sprite(std::string path)
    {
        if (access(path.c_str(), F_OK) == -1) {
            std::cout << "Error: " << path << " doesn't exist\n";
            return;
        }

        _model = LoadModel(path.c_str());
        animCount = 0;
        anim = LoadModelAnimations("assets/icon-of-sin-toy/standing_1_1.iqm", &animCount);
    }

    void Sprite::setSprite(std::string)
    {

    }

    void Sprite::draw(void)
    {
        animCount++;
        UpdateModelAnimation(_model, anim[0], animCount);
        if (animCount >= anim[0].frameCount)
            animCount = 0;
        DrawModelEx(_model, (Vector3){ 100, 100, 0 }, (Vector3){ 1.0f, 0.0f, 0.0f }, -90.0f, (Vector3){ 1.0f, 1.0f, 1.0f }, WHITE);
    }

    void Sprite::getSprite(std::string)
    {

    }

    Sprite::~Sprite()
    {
    }
};
