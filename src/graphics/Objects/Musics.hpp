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
            Musics(const std::string, float);
            void draw(void) override;
            void setSound(float);
            bool isPlaying(void);
            void setLoop(void);
            void play(void);
            void pause(void);
            void stop(void);
            bool isHover(void) override {  };
            void onHover(void) override {  };
            void onHoverEnd(void) override {  };
            void onClick(void) override {  }
            Rectangle getRect(void) override { return {0, 0, 0, 0}; }
            ~Musics();
        private:
            Music _music;
            std::string _source;
            float _volume;
    };
};