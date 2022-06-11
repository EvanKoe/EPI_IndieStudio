/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Cam
*/

#include "Cam.hpp"
#include <raylib.h>

namespace Indie {
    Cam::Cam(CameraMode mode, Vector3 pos, Vector3 target, Vector3 up, float fovy)
    {
        _cam = { 0 };
        _cam.projection = CAMERA_PERSPECTIVE;
        _cam.position = pos;
        _cam.target = target;
        _cam.up = up;
        _cam.fovy = fovy;
        SetCameraMode(_cam, mode);
        BeginMode3D(_cam);
    }

    void Cam::start(void) {}

    void Cam::end(void) {}

    void Cam::draw(void)
    {
        UpdateCamera(&_cam);
    }

    Cam::~Cam() {}
}