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

namespace Indie {

    class Engine {
    public:
        Engine(const std::vector<std::string>& map, int nb_players);
        ~Engine() = default;
        void run();
        void addObject(Indie::GameObject *object);
        Indie::GameObjectsIds checkCollision(float x, float y, float z);
        void printMap();
    private:
        std::vector<std::unique_ptr<Indie::GameObject>> _map;
        int _nb_players{};
    };
}
#endif //BOMBERMAN_ENGINE_HPP
