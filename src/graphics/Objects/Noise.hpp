/*
** EPITECH PROJECT, 2022
** EPI_IndieStudio
** File description:
** Sound
*/

#pragma once

#include "../IGraphic.hpp"

namespace Indie {
    class Noise : public IGraphic {
        public:
            Noise(std::string);
            void play(void);
            void onHover(void) override {};
            bool getIs3D(void) override { return false; }
            void onHoverEnd(void) override {};
            void onClick(void) override {}
            void draw(void) override {};
            Rectangle getRect(void) override { return {0, 0, 0, 0}; }
            ~Noise();

        protected:
        private:
            Sound _noise;
            std::string _path;
    };
};