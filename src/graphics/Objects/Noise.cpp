/*
** EPITECH PROJECT, 2022
** EPI_IndieStudio
** File description:
** Noise
*/

#include "Noise.hpp"

namespace Indie {
    Noise::Noise(std::string path, float vol)
    {
        _path = path;
        _noise = LoadSound(path.c_str());
        _vol = vol;
    }

    void Noise::play(void)
    {
        PlaySound(_noise);
    }

    Noise::~Noise()
    {
    }
};