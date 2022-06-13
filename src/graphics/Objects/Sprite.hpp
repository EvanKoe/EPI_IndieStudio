/*
** EPITECH PROJECT, 2022
** EPI_IndieStudio
** File description:
** Sprite
*/

#pragma once

#include "../IGraphic.hpp"
#include "../../Globals.hpp"
#include <raylib.h>
#include <vector>
#include <filesystem>

namespace Indie {
    class Sprite : public IGraphic {
        public:
            Sprite(std::string, std::string texture = "EMPTY", std::string animate = "EMPTY");
            void onHover(void) override {};
            void setPos(float x = 0, float y = 0, float z = 0) { _pos = { x, y, z }; }
            void setSprite(std::string);
            void getSprite(std::string);
            void onHoverEnd(void) override {  };
            bool isHover(void) override { return false; };
            void onClick(void) override {  }
            void setAnimation(std::string path = "EMPTY");
            void draw(void) override;
            bool getIs3D(void) override { return true; }
            Rectangle getRect(void) override { return { 0, 0, 0, 0 }; }
            ~Sprite();
        private:
            Model _model;
            unsigned int animCount;
            std::string _tpath;
            std::string _path;
            std::string _apath;
            ModelAnimation *anim;
            Texture2D _texture;
            int frameCounter;
            Vector3 _pos;
    };
};