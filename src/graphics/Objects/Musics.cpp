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
        InitAudioDevice();
        _music = LoadMusicStream(_source.c_str());
        SetMusicVolume(_music, _volume);
        PlayMusicStream(_music);
    }

    void Musics::draw(void) {
        UpdateMusicStream(_music);
    }

    void Musics::setMusic(std::string path) {
        stop();
        _music = LoadMusicStream(path.c_str());
        play();
    }

    void Musics::setLoop(void) {}

    bool Musics::isPlaying(void)
    {
        return IsMusicStreamPlaying(_music);
    }

    void Musics::play(void)
    {
        // UpdateMusicStream(_music);
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
        if (IsMusicStreamPlaying(_music)) {
            StopMusicStream(_music);
        }
        UnloadMusicStream(_music);
        CloseAudioDevice();
    }
};