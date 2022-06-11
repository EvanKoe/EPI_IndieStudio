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
            Musics(const std::string src, float vol = 0.9);
            void draw(void) override;
            void setSound(float);
            bool isPlaying(void);
            void setLoop(void);
            void play(void);
            void pause(void);
            void stop(void);
            bool getIs3D(void) override { return false; }
            Music getStream(void) { return _music; };
            bool isHover(void) override { return false; }
            void onHover(void) override {  };
            void onHoverEnd(void) override {  };
            void onClick(void) override {  }
            Rectangle getRect(void) override { return { 0, 0, 0, 0 }; }
            ~Musics();
        private:
            Music _music;
            std::string _source;
            float _volume;
    };
};