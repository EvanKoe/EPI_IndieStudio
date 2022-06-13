/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** Player
*/

#include "Player.hpp"

void Indie::Player::getEvents() {
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

int Indie::Player::dropBomb()
{
    if (this->_bomb_nb > 0) {
        Bomb bomb(this->_x, this->_y, this->_z, this->_bomb_range, 3);
        this->_bomb_nb--;
    }
}

bool Indie::Player::checkCollision(GameObject object)
{
    if (this->getX() == object.getX() && this->getY() == object.getY())
        return true;
    return false;
}

int Indie::Player::getScore() const
{
    return this->_score;
}

void Indie::Player::addScore(int score)
{
    this->_score += score;
}

void Indie::Player::removeScore(int score)
{
    this->_score -= score;
}

int Indie::Player::getSpeed() const
{
    return this->_speed;
}

void Indie::Player::addSpeed(int speed)
{
    this->_speed += speed;
    if (this->_speed > 3)
        this->_speed = 3;
}

void Indie::Player::removeSpeed(int speed)
{
    this->_speed -= speed;
    if (this->_speed < 1)
        this->_speed = 1;
}

int Indie::Player::getBombRange() const
{
    return this->_bomb_range;
}

void Indie::Player::addBombRange(int bomb_range)
{
    this->_bomb_range += bomb_range;
}

void Indie::Player::removeBombRange(int bomb_range)
{
    this->_bomb_range -= bomb_range;
}

void Indie::Player::grantWallpass()
{
    this->_wallpass = true;
}

void Indie::Player::removeWallpass()
{
    this->_wallpass = false;
}

bool Indie::Player::getWallpass() const
{
    return this->_wallpass;
}

int Indie::Player::getBombNb() const
{
    return this->_bomb_nb;
}

void Indie::Player::addBombNb(int bomb)
{
    this->_bomb_nb += bomb;
}

void Indie::Player::removeBombNb(int bomb)
{
    this->_bomb_nb -= bomb;
    if (this->_bomb_nb < 1)
        this->_bomb_nb = 1;
}
