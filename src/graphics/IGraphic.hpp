/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** IGraphic
*/

#pragma once
#include <iostream>
#include <raylib.h>

namespace Indie {
    class IGraphic {
        public:
            virtual void draw(void) = 0;
            virtual void onHover(void) = 0;
            virtual void onClick(void) = 0;
            virtual Rectangle getRect(void) = 0;
            virtual ~IGraphic() = default;
        protected:
        private:
    };
}