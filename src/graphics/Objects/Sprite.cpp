/*
** EPITECH PROJECT, 2022
** EPI_IndieStudio
** File description:
** Sprite
*/

#include "Sprite.hpp"

namespace Indie {
    Sprite::Sprite(std::string path, std::string texture, std::string animate):
    _apath(animate),
    _path(path),
    _tpath(texture)
    {
        std::filesystem::path my_path = path;
        if (!std::filesystem::exists(my_path.c_str())) {
            std::cout << "3D Object Error: " << path << " doesn't exist\n";
            return;
        }

        _model = LoadModel(path.c_str());
        my_path = texture;
        if (!std::filesystem::exists(my_path)) {
            std::cout << "Texture Error: " << texture << " doesn't exist\n";
        } else {
            _texture = LoadTexture(texture.c_str());
            SetMaterialTexture(&_model.materials[0], MATERIAL_MAP_DIFFUSE, _texture);
        }
        my_path = animate;
        if (!std::filesystem::exists(my_path)) {
            std::cout << "Animation Error: " << animate << " doesn't exist\n";
        } else {
            animCount = 0;
            anim = LoadModelAnimations(animate.c_str(), &animCount);
            // std::cout << IsModelAnimationValid(_model, *anim) << std::endl;
            frameCounter = 0;
        }
    }

    void Sprite::setSprite(std::string)
    {

    }

    void Sprite::draw(void)
    {
        // Update
        frameCounter++;
        if (_apath != "EMPTY")
            UpdateModelAnimation(_model, anim[0], frameCounter);
        if (frameCounter >= anim[0].frameCount)
            frameCounter = 0;

        // Draw
        // DrawModelEx(Model, position, rotationAxis, rotationAngle, scale, color );
        if (_path != "EMPTY")
            DrawModel(_model, { 0 }, { 1.0 }, WHITE);
            // DrawModelEx(_model, (Vector3){ 0.0f, 0.0f, 0.0f }, (Vector3){ 0.0f, 0.0f, 0.0f }, 90.0f, (Vector3){ 10.0f, 10.0f, 10.0f }, WHITE);
    }

    void Sprite::getSprite(std::string)
    {

    }

    Sprite::~Sprite() {}
};
