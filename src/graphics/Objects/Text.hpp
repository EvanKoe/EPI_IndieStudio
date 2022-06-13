/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Text
*/

#pragma once

#include "../IGraphic.hpp"
#include <raylib.h>

namespace Indie {
    class Text : public IGraphic {
        public:
            Text(std::string, float x = 0, float y = 0, float size = 20, Color col = LIGHTGRAY);
            void onHover(void) override { return; }
            bool isHover(void) override { return false; }
            std::string getText(void);
            Rectangle getRect(void) override;
            void draw(void) override;
            void setText(std::string);
            void onHoverEnd(void) override { return; }
            bool getIs3D(void) override { return false; }
            void onClick(void) override { return; }
            ~Text();
        private:
            Vector2 _pos;
            size_t _size;
            Color _col;
            std::string _value;
    };
};