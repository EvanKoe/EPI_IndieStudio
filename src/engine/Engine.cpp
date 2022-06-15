/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** engine
*/
#include "Engine.hpp"
#include "Wall/Wall.hpp"

Indie::Engine::Engine(const std::vector<std::string>& map, int nb_players) {

    float x = 0;
    float y = 0;
    for (auto &line: map) {
        for (auto &character: line) {
            if (character == 'x') {

                this->addObject(new Indie::Brick(x, y, 0));
            } else if (character == '#') {

                this->addObject(new Indie::Wall(x, y, 0));
            } else if (
                character == 'P') {

                this->addObject(new Indie::Player(x, y, 0));
            } else if (character == 'I') {
                this->addObject(new Indie::IA(x, y, 0));
            }
            y++;
        }
        y = 0;
        x++;
    }
    this->printMap();
}

void Indie::Engine::addObject(Indie::GameObject *object) {
    _map.push_back(std::unique_ptr<Indie::GameObject>(object));
}

Indie::GameObjectsIds Indie::Engine::checkCollision(float x, float y, float z) {
    Indie::GameObjectsIds id = Indie::NONE;
    std::vector<float> position(3, 0);
    for (auto &object: _map) {
        position = object->getPosition();
        if (position[0] == x &&
            position[1] == y &&
            position[2] == z) {
            id = object->getId();
        }
    }
    return id;
}
void Indie::Engine::printMap() {
    std::vector<float> position(3, 0);
    std::cout << "Map:" << _map.size() << std::endl;
    for (auto &object: _map) {
        position = object->getPosition();
        std::cout << object->getId() << " x: " << position[0] << " y: " << position[1] << " z: " << position[2] << std::endl;
    }
}