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
    Player(int id, int x, int y, int speed, int bomb_range, int bomb_nb);
    ~Player();
    int getScore() const;
    void setScore(int score);
    void setId(int id);
    int getSpeed() const;
    void setSpeed(int speed);
    int getBombRange() const;
    void setBombRange(int bomb_range);
    int getBombNb() const;
    void setBombNb(int bomb_nb);
private:
    int _speed;
    int _bomb_range;
    int _bomb_nb;
    int _score;
};

#endif //BOMBERMAN_PLAYER_HPP
