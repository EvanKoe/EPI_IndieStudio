/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Map
*/

#pragma once

#include <iostream>
#include <list>
#include "../GameObject.hpp"

enum Difficulty {
    EASY,
    MEDIUM,
    HARD
};

class Map {
    public:
        // If no save
        Map(Difficulty d = EASY) {
            switch (d) {
                case (EASY): _size.x = 20; _size.y = 10; break;
                case (MEDIUM): _size.x = 30; _size.y = 20; break;
                default: _size.x = 50; _size.y = 30; break;
            }
        }

        // If save
        Map(std::list<std::list<int>> &map): _map(map) {};
        ~Map();

    protected:
        Position _size;
        std::list<std::list<int>> _map;
    private:
};
