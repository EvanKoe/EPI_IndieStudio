/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Text
*/

#pragma once

#include "../IGraphic.hpp"

namespace Indie {
    class Text : public IGraphic {
        public:
            Text(std::string, float x = 0, float y = 0, float size = 20, Color col = LIGHTGRAY);
            void onHover(void) override { return; }
            bool isHover(void) override { return false; }
            Rectangle getRect(void) override { return (Rectangle){
                _pos.x, _pos.y,
                (float)(_size * _value.size()),
                (float)(_size * 2)
            }; }
            std::string getText(void);
            void draw(void) override;
            void setText(std::string);
            void onHoverEnd(void) override { return; }
            void onClick(void) override { return; }
            ~Text();
        protected:
        private:
            Vector2 _pos;
            size_t _size;
            Color _col;
            std::string _value;
    };
};
