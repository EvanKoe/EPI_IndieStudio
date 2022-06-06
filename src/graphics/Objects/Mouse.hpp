/*
** EPITECH PROJECT, 2022
** EPI_IndieStudio
** File description:
** Mouse
*/

#pragma once

#include "../IGraphic.hpp"
#include <vector>
#include <list>

namespace Indie {
    class Mouse : public IGraphic {
        public:
            Mouse(int, int);
            Vector2 getPos(void);
            ~Mouse();
        private:
            Vector2 _pos;
    };
};
