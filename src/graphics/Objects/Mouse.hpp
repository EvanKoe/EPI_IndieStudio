/*
** EPITECH PROJECT, 2022
** EPI_IndieStudio
** File description:
** Mouse
*/

#pragma once

#include "../IGraphic.hpp"
#include <vector>
#include <list>

namespace Indie {
    class Mouse : public IGraphic {
        public:
            Mouse(int, int);
            void onHover(void) override {  };
            void onHoverEnd(void) override {  };
            void onClick(void) override {  }
            bool getIs3D(void) override { return false; }
            void draw(void) override {  };
            Rectangle getRect(void) override { return {0, 0, 0, 0}; }
            Vector2 getPos(void);
            ~Mouse();
        private:
            Vector2 _pos;
    };
};
