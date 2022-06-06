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
            void onHover(void) override {};
            void play(void);
            ~Noise();

        protected:
        private:
            Sound _noise;
            std::string _path;
    };
};