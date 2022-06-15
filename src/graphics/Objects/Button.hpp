/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Text
*/

#pragma once

#include "../IGraphic.hpp"
#include "Noise.hpp"
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
            void onHover(void) override;
            void onHoverEnd(void) override;
            void onClick(void) override {
                _noise.play();
                return _onClick();
            }
            void draw(void) override;
            Rectangle getRect(void) override { return _rec; }
            void setPosition(Vector2);
            bool isHover(void) override;
            Vector2 getPosition(void);
            bool getIs3D(void) override { return false; }
            void setText(std::string);
            std::string getText(void);
            void setDisabled(bool);
            bool isDisabled(void);
            ~Button();
        protected:
        private:
            Color _hcolor;
            Color _ncolor;
            Color _color;
            Color _borderColor;
            Rectangle _rec;
            std::function<void (void)> _onClick;
            std::string _name;
            std::string _text;
            bool _is_enabled;
            Noise _noise;
    };
};
