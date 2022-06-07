/*
** EPITECH PROJECT, 2022
** EPI_IndieStudio
** File description:
** Musics
*/

#include "../IGraphic.hpp"
#include "Musics.hpp"

namespace Indie {
    Musics::Musics(const std::string *file, float vol)
    {
        _source = file;
        _volume = vol;
        _music = LoadMusicStream(_source->c_str());
    }

    void Musics::setLoop(void)
    {
        ResumeMusicStream(_music);
    }

    bool Musics::isPlaying(void)
    {
        return IsMusicStreamPlaying(_music);
    }

    void Musics::play(void)
    {
        PlayMusicStream(_music);
    }

    void Musics::pause(void)
    {
        PauseMusicStream(_music);
    }

    void Musics::stop(void)
    {
        StopMusicStream(_music);
    }

    void Musics::setSound(float vol)
    {
        SetMusicVolume(_music, _volume);
    }

    Musics::~Musics()
    {
        UnloadMusicStream(_music);
    }
};