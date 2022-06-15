/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** game engine
*/

#pragma once

#include "Globals.hpp"
#include "GameObject.hpp"
#include "Player.hpp"
#include "objects/Brick/Brick.hpp"
#include "PowerUp.hpp"
// #include "Bomb.hpp"
#include "Ia/Ia.hpp"


namespace Indie {

    class Engine {
    public:
        Engine(const std::vector<std::string> &map, int nb_players);
        ~Engine() = default;
        void run(int k = 0);
        void addObject(Indie::GameObject *object);
        Indie::GameObjectsIds checkCollision(float x, float y, float z);
        void printMap();
    private:
        std::vector<std::unique_ptr<Indie::GameObject>> _map;
        int _nb_players{};
    };
}
