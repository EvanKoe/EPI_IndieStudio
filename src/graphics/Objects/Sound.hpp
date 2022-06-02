/*
** EPITECH PROJECT, 2022
** EPI_IndieStudio
** File description:
** Sound
*/

#pragma once

#include "../IGraphic.hpp"

namespace Indie {
    class Sound : public IGraphic {
        public:
            Sound(std::string);
            void play(void);
            ~Sound();

        protected:
        private:
    };
};