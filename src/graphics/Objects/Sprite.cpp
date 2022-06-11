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
    Sprite::Sprite(std::string path, std::string texture)
    {
        if (access(path.c_str(), F_OK) == -1) {
            std::cout << "Error: " << path << " doesn't exist\n";
            return;
        }

        _model = LoadModel(path.c_str());
        if (texture != "EMPTY") {
            _texture = LoadTexture(texture.c_str());
            SetMaterialTexture(&_model.materials[0], MATERIAL_MAP_DIFFUSE, _texture);
        }
        animCount = 0;
        frameCounter = 0;
        anim = LoadModelAnimations("assets/icon-of-sin-toy/standing_1_1.iqm", &animCount);
    }

    void Sprite::setSprite(std::string)
    {

    }

    void Sprite::draw(void)
    {
        // Update
        frameCounter++;
        UpdateModelAnimation(_model, anim[0], frameCounter);
        if (frameCounter >= anim[0].frameCount)
            frameCounter = 0;

        // Draw
        DrawModelEx(_model, (Vector3){ 0.0f, 0.0f, 0.0f }, (Vector3){ 1.0f, 0.0f, 0.0f }, -90.0f, (Vector3){ 1.0f, 1.0f, 1.0f }, WHITE);
        if (anim == nullptr) {
            return;
        }
    }

    void Sprite::getSprite(std::string)
    {

    }

    Sprite::~Sprite()
    {
    }
};
