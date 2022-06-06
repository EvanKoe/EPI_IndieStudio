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
            std::string getText(void);
            void draw(void) override;
            void setText(std::string);
            ~Text();
        protected:
        private:
            Vector2 _pos;
            size_t _size;
            Color _col;
            std::string _value;
    };
};
