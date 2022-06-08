/*
** EPITECH PROJECT, 2022
** EPI_IndieStudio
** File description:
** Musics
*/

#include "../IGraphic.hpp"
#include "Musics.hpp"
#include <raylib.h>

namespace Indie {
    Musics::Musics(std::string file, float vol)
    {
        _source = file;
        _volume = vol;
        _music = LoadMusicStream(_source.c_str());
    }

    void Musics::draw(void)
    {
        InitAudioDevice();
        play();
    }

    void Musics::setLoop(void)
    {
        // ResumeMusicStream(_music);
    }

    bool Musics::isPlaying(void)
    {
        return IsMusicStreamPlaying(_music);
    }

    void Musics::play(void)
    {
        UpdateMusicStream(_music);
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
        CloseAudioDevice();
    }
};