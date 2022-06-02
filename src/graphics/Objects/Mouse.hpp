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
            Mouse(std::vector<int>, std::vector<int>);
            std::list<std::vector<int>> getPos(void);
            ~Mouse();

        protected:
        private:
            std::vector<int> _x;
            std::vector<int> _y;
    };
};
