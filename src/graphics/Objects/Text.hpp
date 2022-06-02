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
            Text(std::string, int x = 0, int y = 0, Color col = LIGHTGRAY);
            std::string getText(void);
            void draw(void);
            void setText(std::string);
            ~Text();
        protected:
        private:
            Font _font;
            Vector2 _pos;
            size_t _size;
            Color _col;
            std::string _value;
    };
};