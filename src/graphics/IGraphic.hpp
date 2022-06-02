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
            virtual void draw(void);
            virtual ~IGraphic();
        protected:
        private:
    };
}