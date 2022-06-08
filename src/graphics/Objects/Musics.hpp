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
            void onHover(void) override {  };
            void onHoverEnd(void) override {  };
            void onClick(void) override {  }
            void draw(void) override {  };
            Rectangle getRect(void) override { return {0, 0, 0, 0}; }
            ~Musics();
        private:
            Music _music;
            const std::string *_source;
            float _volume;
    };
};