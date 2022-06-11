/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Cam
*/

#include "Cam.hpp"
#include <raylib.h>

namespace Indie {
    Cam::Cam(CameraMode mode, Vector3 pos, Vector3 target, Vector3 up)
    {
        _cam = { 0 };
        _cam.projection = CAMERA_PERSPECTIVE;
        _cam.position = pos;
        _cam.target = target;
        _cam.up = up;
        SetCameraMode(_cam, mode);
    }

    void Cam::start(void)
    {
        BeginMode3D(_cam);
    }

    void Cam::end(void)
    {
        EndMode3D();
    }

    void Cam::draw(void)
    {
        UpdateCamera(&_cam);
    }

    Cam::~Cam()
    {
    }
}