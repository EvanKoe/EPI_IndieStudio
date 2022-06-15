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
            Sprite(int id, std::string, std::string texture = "EMPTY", std::string animate = "EMPTY", float scale = 1.0f);
            void onHover(void) override {};
            void setPos(float x = 0.0f, float y = 0.0f, float z = 0.0f) { _pos = { x, y, z }; }
            void setSprite(std::string);
            void getSprite(std::string);
            void onHoverEnd(void) override {  };
            bool isHover(void) override { return false; };
            void onClick(void) override {  }
            void setAnimation(std::string path = "EMPTY");
            void draw(void) override;
            bool getIs3D(void) override { return true; }
            Rectangle getRect(void) override { return { 0, 0, 0, 0 }; }
            int getID(void) { return _id; }
            Vector3 getPos(void) { return _pos; }
            void setRotation(float angle = 0.0f) { _rot = angle; }
            ~Sprite();
        private:
            int _id;
            Model _model;
            unsigned int animCount;
            std::string _tpath;
            std::string _path;
            std::string _apath;
            ModelAnimation *anim;
            float _rot;
            float _scale;
            Texture2D _texture;
            int frameCounter;
            Vector3 _pos;
    };
};