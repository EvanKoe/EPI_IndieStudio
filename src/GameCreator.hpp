/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** GameCreator
*/

#pragma once

#include "./graphics/Display.hpp"
#include "./graphics/IGraphic.hpp"
#include <filesystem>

/** This is our global game class. Everything will be
 * initialized through this class.
**/

namespace Indie {
    class GameCreator {
        public:
            GameCreator();
            void startGame(void) { return; };
            Display getDisp(void) { return _disp; };
            ~GameCreator();
        protected:
            Display _disp;
        private:
    };
};