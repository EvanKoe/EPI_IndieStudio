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

void Indie::Player::dropBomb()
{
    if (this->_bomb_nb > 0) {
        Bomb bomb(this->_x, this->_y, this->_z, this->_bomb_range, 3);
        this->_bombs.push_back(std::unique_ptr<Bomb>(&bomb));
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

void Indie::Player::addSpeed()
{
    if (this->_speed >= 3)
        this->_speed = 3;
    else
        this->_speed ++;
}

void Indie::Player::removeSpeed()
{

    if (this->_speed <= 1)
        this->_speed = 1;
    else
        this->_speed --;
}

int Indie::Player::getBombRange() const
{
    return this->_bomb_range;
}

void Indie::Player::addBombRange()
{
    this->_bomb_range ++;
}

void Indie::Player::removeBombRange()
{
    if (_bomb_range <= 1)
        this->_bomb_range = 1;
    else
        this->_bomb_range --;
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

void Indie::Player::addBombNb()
{
    this->_bomb_nb ++;
}

void Indie::Player::removeBombNb()
{
    if (this->_bomb_nb <= 1)
        this->_bomb_nb = 1;
    else
        this->_bomb_nb --;
}
