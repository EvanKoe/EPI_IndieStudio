/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** Power up
*/

#include "PowerUp.hpp"

Indie::PowerUpAttribute Indie::PowerUp::getAttribute() {
    return _attribute;
}

void Indie::PowerUp::ApplyEffect(Indie::Player player) {

    switch (_attribute) {
        case Indie::PowerUpAttribute::BOMB_UP:
            player.addBombRange();
            break;
        case Indie::PowerUpAttribute::SPEED_UP:
            player.addSpeed();
            break;
        case Indie::PowerUpAttribute::FIRE_UP:
            player.addBombRange();
            break;
        case Indie::PowerUpAttribute::WALL_PASS_UP:
            player.grantWallpass();
            break;
        case Indie::PowerUpAttribute::BOMB_DOWN:
            player.removeBombRange();
            break;
        case Indie::PowerUpAttribute::SPEED_DOWN:
            player.removeSpeed();
            break;
        case Indie::PowerUpAttribute::FIRE_DOWN:
            player.removeBombRange();
            break;
        case Indie::PowerUpAttribute::WALL_PASS_DOWN:
            player.removeWallpass();
            break;
        default:
            break;
    }
}
