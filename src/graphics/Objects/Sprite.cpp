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
    Sprite::Sprite(std::string path, std::string texture, std::string texture2, std::string animate)
    {
        if (access(path.c_str(), F_OK) == -1) {
            std::cout << "3D Object Error: " << path << " doesn't exist\n";
            return;
        }

        _model = LoadModel(path.c_str());
        if (texture != "EMPTY") {
            if (access(texture.c_str(), F_OK) == -1) {
                std::cout << "Texture Error: " << texture << " doesn't exist\n";
            } else {
                _texture = LoadTexture(texture.c_str());
                SetMaterialTexture(&_model.materials[0], MATERIAL_MAP_DIFFUSE, _texture);
                // _texture2 = LoadTexture(texture.c_str());
                // SetMaterialTexture(&_model.materials[0], MATERIAL_MAP_DIFFUSE, _texture2);
            }
        }
        if (animate != "EMPTY") {
            if (access(animate.c_str(), F_OK) == -1) {
                std::cout << "Animation Error: " << animate << " doesn't exist\n";
            } else {
                animCount = 0;
                // anim = LoadModelAnimations(animate.c_str(), &animCount);
                frameCounter = 0;
            }
        }
    }

    void Sprite::setSprite(std::string)
    {

    }

    void Sprite::draw(void)
    {
        // Draw
        DrawModelEx(_model, (Vector3){ 0.0f, 0.0f, 0.0f }, (Vector3){ 0.0f, 1.0f, 0.0f }, 90.0f, (Vector3){ 5.0f, 5.0f, 5.0f }, WHITE);

        // Update
        frameCounter++;
        // UpdateModelAnimation(_model, anim[0], frameCounter);
        if (frameCounter >= anim[0].frameCount)
            frameCounter = 0;
    }

    void Sprite::getSprite(std::string)
    {

    }

    Sprite::~Sprite() {}
};
