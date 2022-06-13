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
        _pos = { 0 };

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

    void Sprite::setAnimation(std::string path)
    {
        if (!std::filesystem::exists(std::filesystem::path(path.c_str()))) {
            return;
        }
        UnloadModelAnimation(*anim);
        animCount++;
        anim = LoadModelAnimations(path.c_str(), &animCount);
        frameCounter = 0;
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
        if (_path != "EMPTY")
            DrawModel(_model, _pos, { 1.0 }, WHITE);
    }

    void Sprite::getSprite(std::string)
    {

    }

    Sprite::~Sprite() {}
};
