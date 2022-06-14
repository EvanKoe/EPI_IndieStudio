/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** IGraphic
*/

#pragma once
#include <iostream>
#include <raylib.h>
#include <cstdio>
#include <string>
#include <cstring>

namespace Indie {
    class IGraphic {
        public:
            virtual void draw(void) = 0;
            virtual void onHover(void) = 0;
            virtual void onHoverEnd(void) {};
            virtual bool isHover(void) = 0;
            virtual bool getIs3D(void) = 0;
            virtual void onClick(void) {};
            virtual Rectangle getRect(void) = 0;
            virtual ~IGraphic() = default;
        protected:
        private:
    };
};