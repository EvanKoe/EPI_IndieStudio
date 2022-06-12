/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** Bomb
*/

#include "Bomb.hpp"

void Bomb::checkExplode()
{
    if (time(nullptr) >= _timer)
        Explode();
}

void Bomb::Explode()
{
    std::cout << "Bomb Explode" << std::endl;
}