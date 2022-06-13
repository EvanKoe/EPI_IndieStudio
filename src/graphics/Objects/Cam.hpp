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
            Cam(
                CameraMode mode = CAMERA_FREE,
                Vector3 pos = { 0.0f, 10.0f, 10.0f },
                Vector3 target = { 0.0f, 0.0f, 0.0f },
                Vector3 up = { 0.0f, 1.0f, 0.0f },
                float fovy = 45.0f
            );
            void draw(void) override;
            Camera3D getCamera(void) { return _cam; }
            void onHover(void) override {}
            void onHoverEnd(void) override {}
            bool isHover(void) override { return false; }
            void onClick(void) override {}
            Rectangle getRect(void) override { return { 0 }; }
            bool getIs3D(void) override { return true; }
            void start(void);
            void end(void);
            ~Cam();
        private:
            Camera3D _cam;
    };
}