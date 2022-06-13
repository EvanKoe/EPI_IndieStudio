/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** Bomb
*/

#include "../GameObject.hpp"
#include <ctime>

#ifndef BOMBERMAN_BOMB_HPP
#define BOMBERMAN_BOMB_HPP

namespace Indie {
    class Bomb : public GameObject {
    public:
        explicit Bomb(float x = 0, float y = 0, float z = 0, int range = 1, int timer = 3)
            : GameObject(x, y, z, Indie::BOMB),
              _range(range)
        {
            _timer = time(nullptr) + timer * 1000;
        };
        ~Bomb();
        void checkExplode(void);
        static void Explode(void);

    private:
        int _range;
        std::time_t _timer;
    };
}

#endif //BOMBERMAN_BOMB_HPP
