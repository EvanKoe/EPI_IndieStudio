/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Cam
*/

#include "../IGraphic.hpp"
#include <raylib.h>

#pragma once

namespace Indie {
    class Cam : public IGraphic {
        public:
            Cam(Vector3 pos = { 0 }, Vector3 target = { 0 }, Vector3 up = { 0 });
            void start(void);
            void onHover(void) {};
            void onHoverEnd(void) {};
            bool isHover(void) { return false; }
            void onClick(void) {};
            Rectangle getRect(void) { return {0}; }
            void draw(void) {};
            ~Cam();
        private:
            Camera3D _cam;
            Vector3 _pos;       // position
            Vector3 _target;    // object pointed by cam
            Vector3 _up;        // distance from target
    };
}