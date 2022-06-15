/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** engine
*/
#include "Engine.hpp"
#include "Wall/Wall.hpp"

Indie::Engine::Engine(const std::vector<std::string> &map, int nb_players) {
    float x = 0;
    float y = 0;

    for (auto &line: map) {
        for (auto &character: line) {
            switch (character) {
                case ('x'): this->addObject(new Indie::Brick(x, y, 0)); break;
                case ('#'): this->addObject(new Indie::Wall(x, y, 0)); break;
                case ('P'): this->addObject(new Indie::Player(x, y, 0)); break;
                case ('I'): this->addObject(new Indie::IA(x, y, 0)); break;
                default: break;
            }
            y++;
        }
        y = 0;
        x++;
    }
}

void Indie::Engine::addObject(Indie::GameObject *object) {
    _map.push_back(std::unique_ptr<Indie::GameObject>(object));
}

Indie::GameObjectsIds Indie::Engine::checkCollision(float x, float y, float z) {
    Indie::GameObjectsIds id = Indie::NONE;
    pos_t position = { 0 };

    for (auto &object: _map) {
        position = object->getPosition();
        if (position.x == x &&
            position.y == y &&
            position.z == z
        ) {
            id = object->getId();
        }
    }
    return id;
}
void Indie::Engine::printMap() {
    pos_t position = { 0 };

    std::cout << "Map:" << _map.size() << std::endl;
    for (auto &object: _map) {
        position = object->getPosition();
        std::cout << object->getId() << " x: " << position.x << " y: " << position.y << " z: " << position.z << std::endl;
    }
}

void Indie::Engine::run(int k) {
    // switch (k) {
        // case (KEY_Q):
    // }
}