/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Text
*/

#pragma once

#include "../IGraphic.hpp"
#include <functional>
#include <raylib.h>
#include <iostream>

namespace Indie {
    class Button : public IGraphic {
        public:
            Button(
                std::string str = "Click here",
                std::function<void (void)> fun = [](){ return; },
                Vector2 pos = { 0, 0 },
                Vector2 size = { 100, 100 },
                Color textColor = GRAY,
                Color hoverColor = ORANGE
            );
            void onHover(void) override {
                DrawText(_text.c_str(), _rec.x, _rec.y, 30, _hoverColor);
            }
            void onClick(void) override { return _onClick(); }
            Rectangle getRect(void) override { return _rec; }
            void setPosition(Vector2);
            void setHover(void);
            bool isHover(void);
            Vector2 getPosition(void);
            void setText(std::string);
            std::string getText(void);
            void setDisabled(bool);
            bool isDisabled(void);
            void draw(void) override;
            ~Button();
        protected:
        private:
            Color _hoverColor;
            Color _color;
            Rectangle _rec;
            std::function<void (void)> _onClick;
            std::string _name;
            std::string _text;
            bool _is_enabled;
    };
};
