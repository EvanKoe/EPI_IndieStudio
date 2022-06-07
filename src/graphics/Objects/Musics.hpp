/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Text
*/

#pragma once

#include "../IGraphic.hpp"

namespace Indie {
    class Musics : public IGraphic {
        public:
            Musics(const std::string*, float);
            void setLoop(void);
            bool isPlaying(void);
            void play(void);
            void pause(void);
            void stop(void);
            void setSound(float);
            ~Musics();
        private:
            Music _music;
            const std::string *_source;
            float _volume;
    };
};