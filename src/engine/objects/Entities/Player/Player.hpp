/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** Player.hpp
*/

#include "../Entity.hpp"
#include "../../Bomb/Bomb.hpp"

#ifndef BOMBERMAN_PLAYER_HPP
#define BOMBERMAN_PLAYER_HPP

namespace Indie {
    class Player : public Entity {
    public:
        explicit Player(float x = 0, float y = 0, float z = 0, int health = 2)
            : Entity(x, y, z, health, Indie::PLAYER),
              _score(0),
              _bomb_range(1),
              _bomb_nb(1),
              _wallpass(false){};
        ~Player() = default;

        void dropBomb(void);
        void getEvents();

        bool checkCollision(GameObject object);

        int getScore() const;
        void addScore(int score);
        void removeScore(int score);
        int getSpeed() const;
        void addSpeed();
        void removeSpeed();
        int getBombRange() const;
        void addBombRange();
        void removeBombRange();
        int getBombNb() const;
        void addBombNb();
        void removeBombNb();
        bool getWallpass() const;
        void grantWallpass();
        void removeWallpass();

    private:
        int _bomb_range;
        int _bomb_nb;
        int _score;
        bool _wallpass;
        std::vector<std::unique_ptr<Bomb>> _bombs;
    };
}

#endif //BOMBERMAN_PLAYER_HPP
