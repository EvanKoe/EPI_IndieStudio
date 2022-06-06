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
            Musics(std::string);
            void setLoop(void);
            bool isPlaying(void);
            void play(void);
            void pause(void);
            void stop(void);
            void setSound(std::string);
            ~Musics();
        private:
            Music _music;
    };
};