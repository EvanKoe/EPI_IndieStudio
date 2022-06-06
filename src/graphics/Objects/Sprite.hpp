/*
** EPITECH PROJECT, 2022
** EPI_IndieStudio
** File description:
** Sprite
*/

#pragma once

#include "../IGraphic.hpp"

namespace Indie {
    class Sprite : public IGraphic {
        public:
            Sprite(std::string);
            void onHover(void) override {};
            void setSprite(std::string);
            void getSprite(std::string);
            ~Sprite();
        private:
    };
};