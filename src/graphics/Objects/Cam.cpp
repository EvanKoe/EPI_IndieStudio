/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Cam
*/

#include "Cam.hpp"
#include <raylib.h>

namespace Indie {
    Cam::Cam(Vector3 pos, Vector3 target, Vector3 up)
    {
        _cam = { 0 };
        _cam.projection = CAMERA_PERSPECTIVE;
        _cam.position = pos;
        _cam.target = target;
        _cam.up = up;
    }

    void Cam::start(void)
    {
        BeginMode3D(_cam);
    }

    Cam::~Cam()
    {
        EndMode3D();
    }
}