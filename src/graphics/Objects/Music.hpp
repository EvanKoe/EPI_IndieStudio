/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Text
*/

#pragma once

#include "../IGraphic.hpp"

namespace Indie {
    class Music : public IGraphic {
        public:
            Music(std::string);
            void setLoop(void);
            bool isPlaying(void);
            void play(void);
            void pause(void);
            void stop(void);
            void setSound(void);
            ~Music();
        private:
    };
};