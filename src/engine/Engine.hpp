/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** game engine
*/

#include "Globals.hpp"
#include "GameObject.hpp"
#include "Player.hpp"
#include "objects/Brick/Brick.hpp"
#include "PowerUp.hpp"
#include "Bomb.hpp"
#include "Ia/Ia.hpp"

#ifndef BOMBERMAN_ENGINE_HPP
#define BOMBERMAN_ENGINE_HPP

class Engine {
public:
    Engine();
    ~Engine();
    void run();
private:
    std::vector<std::vector<Indie::GameObject *>> _map;
};

#endif //BOMBERMAN_ENGINE_HPP
