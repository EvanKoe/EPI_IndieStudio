/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Map
*/

#pragma once

#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <raylib.h>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>

enum Difficulty {
    EASY,
    MEDIUM,
    HARD
};
namespace Indie {
    class Map {
        public:
            Map() {};// void Generator(size_t x, size_t y); // Generate a map in a txt file with a random map
            void LoadMap(std::string path); // Load a map from a txt file
            void SaveMap(std::string path); // Save a map in a txt file
            std::vector<std::string> getMap() const;
            ~Map() {};
            Vector2 _size;
            std::vector<std::string> _map;
    };
}
