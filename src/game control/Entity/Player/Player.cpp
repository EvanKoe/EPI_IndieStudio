/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** Player
*/

#include "Player.hpp"

Player::Player(int id, int x, int y, int speed, int bomb_range, int bomb_nb, bool wallpass = false)
{
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
}

int Player::getBombRange() const
{
    return this->_bomb_range;
}

void Player::setBombRange(int bomb_range)
{
    this->_bomb_range = bomb_range;
}
