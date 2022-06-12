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

namespace Indie {
    class Sprite : public IGraphic {
        public:
            Sprite(std::string, std::string texture = "EMPTY", std::string texture2 = "EMPTY", std::string animate = "EMPTY");
            void onHover(void) override {};
            void setSprite(std::string);
            void getSprite(std::string);
            void onHoverEnd(void) override {  };
            bool isHover(void) override { return false; };
            void onClick(void) override {  }
            void draw(void) override;
            bool getIs3D(void) override { return true; }
            Rectangle getRect(void) override { return {0, 0, 0, 0}; }
            ~Sprite();
        private:
            Model _model;
            // std::vector<Anims> _anims;
            unsigned int animCount;
            ModelAnimation *anim;
            Texture2D _texture;
            Texture2D _texture2;
            int frameCounter;
    };
};