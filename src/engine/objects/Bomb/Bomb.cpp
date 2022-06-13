/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** Bomb
*/

#include "Bomb.hpp"

void Indie::Bomb::checkExplode()
{
    if (time(nullptr) >= _timer)
        Explode();
}

void Indie::Bomb::Explode()
{
    std::cout << "Bomb Explode" << std::endl;
}