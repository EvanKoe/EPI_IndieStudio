/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** Power up
*/

#include "PowerUp.hpp"

Indie::PowerUpAttribute Indie::PowerUp::getAttribute()
{
    return _attribute;
}

void Indie::PowerUp::setAttribute(Indie::PowerUpAttribute attribute)
{
    Player *player;
    if (attribute == Indie::PowerUpAttribute::SPEED_UP) {
        if (player) {
            player->addSpeed(1);
        }
    }
    if (attribute == Indie::PowerUpAttribute::BOMB_UP) {
        if (player) {
            player->addBombNb(1);
        }
    }
    if (attribute == Indie::PowerUpAttribute::FIRE_UP) {
        if (player) {
            player->addFire(1);
        }
    }
    if (attribute == Indie::PowerUpAttribute::BOMB_DOWN) {
        if (player) {
            player->removeBombNb(1);
        }
    }
    if (attribute == Indie::PowerUpAttribute::SPEED_DOWN) {
        if (player) {
            player->removeSpeed(1);
        }
    }
    if (attribute == Indie::PowerUpAttribute::FIRE_DOWN) {
        if (player) {
            player->removeFire(1);
        }
    }
    if (attribute == Indie::PowerUpAttribute::WALL_PASS_UP) {
        if (player) {
            player->grantWallpass();
        }
    }
    if (attribute == Indie::PowerUpAttribute::WALL_PASS_DOWN) {
        if (player) {
            player->removeWallpass();
        }
    }
}
