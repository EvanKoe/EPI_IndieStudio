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

int Player::dropBomb()
{
    if (this->_bomb_nb > 0) {
        Bomb bomb(this->_x, this->_y, this->_z, this->_bomb_range, 3);
        this->_bomb_nb--;
    }
}

bool Player::checkCollision(GameObject object)
{
    if (this->getX() == object.getX() && this->getY() == object.getY())
        return true;
    return false;
}

int Player::getScore() const
{
    return this->_score;
}

void Player::addScore(int score)
{
    this->_score += score;
}

void Player::removeScore(int score)
{
    this->_score -= score;
}

int Player::getSpeed() const
{
    return this->_speed;
}

void Player::addSpeed(int speed)
{
    this->_speed += speed;
    if (this->_speed > 3)
        this->_speed = 3;
}

void Player::removeSpeed(int speed)
{
    this->_speed -= speed;
    if (this->_speed < 1)
        this->_speed = 1;
}

int Player::getBombRange() const
{
    return this->_bomb_range;
}

void Player::addBombRange(int bomb_range)
{
    this->_bomb_range += bomb_range;
}

void Player::removeBombRange(int bomb_range)
{
    this->_bomb_range -= bomb_range;
}

void Player::grantWallpass()
{
    this->_wallpass = true;
}

bool Player::getWallpass() const
{
    return this->_wallpass;
}

int Player::getBombNb() const
{
    return this->_bomb_nb;
}

void Player::addBombNb(int bomb)
{
    this->_bomb_nb += bomb;
}

void Player::removeBombNb(int bomb)
{
    this->_bomb_nb -= bomb;
    if (this->_bomb_nb < 1)
        this->_bomb_nb = 1;
}
