/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** Player.hpp
*/

#include "../IEntity.hpp"

#ifndef BOMBERMAN_PLAYER_HPP
#define BOMBERMAN_PLAYER_HPP

class Player : public IEntity {
public:
    Player(int _health, int _speed, int _bomb_range, int _bomb_nb, int _id);
    ~Player();
    int getEvents(void) override;
    int movement(int) override;
    int dropBomb(void) override;

    int getScore() const;
    void setScore(int score);
    void setId(int id);
    int getSpeed() const;
    void setSpeed(int speed);
    int getBombRange() const;
    void setBombRange(int bomb_range);
    int getBombNb() const;
    void setBombNb(int bomb_nb);
    bool getWallpass() const;
    void setWallpass(bool wallpass);
private:
    int _speed;
    int _bomb_range;
    int _bomb_nb;
    int _score;
    bool _wallpass;
};

#endif //BOMBERMAN_PLAYER_HPP
