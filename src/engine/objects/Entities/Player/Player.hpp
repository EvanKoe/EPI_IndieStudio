/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** Player.hpp
*/

#include "../Entity.hpp"

#ifndef BOMBERMAN_PLAYER_HPP
#define BOMBERMAN_PLAYER_HPP

class Player : public Entity {
public:
    explicit Player(float x = 0, float y = 0, float z = 0, int health = 2)
        : Entity(x, y, z, health, Indie::PLAYER),
        _score(0),
        _bomb_range(1),
        _bomb_nb(1),
        _wallpass(false)
    {};
    ~Player();

    int dropBomb(void);
    void getEvents();

    bool checkCollision(GameObject object);

    int getScore() const;
    void addScore(int score);
    void removeScore(int score);
    int getSpeed() const;
    void addSpeed(int speed);
    void removeSpeed(int speed);
    int getBombRange() const;
    void addBombRange(int range);
    void removeBombRange(int range);
    int getBombNb() const;
    void addBombNb(int bomb);
    void removeBombNb(int bomb);
    bool getWallpass() const;
    void grantWallpass();

private:
    int _bomb_range;
    int _bomb_nb;
    int _score;
    bool _wallpass;


};

#endif //BOMBERMAN_PLAYER_HPP
