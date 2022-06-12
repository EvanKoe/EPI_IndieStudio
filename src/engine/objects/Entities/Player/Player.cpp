/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** Player
*/

#include "Player.hpp"

Player::Player(int _health, int _speed, int _bomb_range, int _bomb_nb, int _id)
{
    _health = _health;
    _speed = _speed;
    _bomb_range = _bomb_range;
    _bomb_nb = _bomb_nb;
    _id = _id;
    this->_position.x = 0;
    this->_position.y = 0;
    this->_wallpass = false;
}

Player::~Player()
{
}

int Player::getEvents()
{
    while (!WindowShouldClose) {
        if (IsKeyPressed(KEY_UP))
            this->_position.y -= this->_speed;
        if (IsKeyPressed(KEY_DOWN))
            this->_position.y += this->_speed;
        if (IsKeyPressed(KEY_LEFT))
            this->_position.x -= this->_speed;
        if (IsKeyPressed(KEY_RIGHT))
            this->_position.x += this->_speed;
        if (IsKeyPressed(KEY_SPACE)) {
            // call dropBomb()
            setBombNb(getBombNb() - 1);
        }
    }
}

void Player::setId(int id)
{
    this->_id = id;
}

int Player::getScore() const
{
    return this->_score;
}

void Player::setScore(int score)
{
    this->_score = score;
}

int Player::getSpeed() const
{
    return this->_speed;
}

void Player::setSpeed(int speed)
{
    this->_speed = speed;
    if (this->_speed < 1)
        this->_speed = 1;
    if (this->_speed > 3)
        this->_speed = 3;
}

int Player::getBombRange() const
{
    return this->_bomb_range;
}

void Player::setBombRange(int bomb_range)
{
    this->_bomb_range = bomb_range;
}

void Player::setWallpass(bool wallpass)
{
    this->_wallpass = wallpass;
}

bool Player::getWallpass() const
{
    return this->_wallpass;
}

int Player::getBombNb() const
{
    return this->_bomb_nb;
}

void Player::setBombNb(int bomb_nb)
{
    this->_bomb_nb = bomb_nb;
    if (this->_bomb_nb < 1)
        this->_bomb_nb = 1;
}
