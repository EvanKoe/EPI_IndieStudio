/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** Player
*/

#include "Player.hpp"

Player::Player()
{
    this->_speed = 1;
    this->_bomb_range = 1;
    this->_bomb_nb = 1;
    this->_position.x = 0;
    this->_position.y = 0;
    this->_wallpass = false;
}

Player::~Player()
{
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
