/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** Player
*/

#include "Player.hpp"

void Player::getEvents() {
    if (IsKeyPressed(
        KEY_UP))
        this->movement(
            Indie::UP);
    if (IsKeyPressed(
        KEY_DOWN))
        this->movement(
            Indie::DOWN);
    if (IsKeyPressed(
        KEY_LEFT))
        this->movement(
            Indie::LEFT);
    if (IsKeyPressed(
        KEY_RIGHT))
        this->movement(
            Indie::RIGHT);
    if (IsKeyPressed(
        KEY_SPACE))
        this->dropBomb();
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
