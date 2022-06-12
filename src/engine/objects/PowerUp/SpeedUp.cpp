/*
** EPITECH PROJECT, 2022
** EPI_IndieStudio [WSL: Ubuntu]
** File description:
** SpeedUp
*/

#include "SpeedUp.hpp"
#include "../Entities/Player/Player.hpp"

SpeedUp::SpeedUp(): PowerUp(Indie::PowerUpAttribute::SPEED_UP, 0, 0, 0)
{
}

void SpeedUp::setAttribute(Indie::PowerUpAttribute attribute)
{
    Player *player;
    if (player) {
        player->addSpeed(1);
    }
}
