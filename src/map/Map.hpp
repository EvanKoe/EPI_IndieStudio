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
        // Map(Difficulty d = EASY) {
        //     switch (d) {
        //         case (EASY): _size.x = 20; _size.y = 10; break;
        //         case (MEDIUM): _size.x = 30; _size.y = 20; break;
        //         default: _size.x = 50; _size.y = 30; break;
        //     }
        //  }

        // If save
        // Map(std::list<std::list<int>> &map): _map(map) {};
        Map() {};
        void Generator(size_t x, size_t y); // Generate a map in a txt file with a random map
        void LoadMap(std::string path); // Load a map from a txt file
        void SaveMap(std::string path); // Save a map in a txt file
        void ParseMap(std::string path); // Parse a map from a txt file
        ~Map() {};
        // return en double tableau (protected) Cédric Kélian
        // class error sans std::exception (pas dans classe map) Cedric Kélian

    protected:
        Position _size;
        std::list<std::string>> _map;
    private:
};
