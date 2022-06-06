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

enum Difficulty {
    EASY,
    MEDIUM,
    HARD
};

class Map {
    public:
        Map() {};
        void Generator(size_t x, size_t y); // Generate a map in a txt file with a random map
        void LoadMap(std::string path); // Load a map from a txt file
        void SaveMap(std::string path); // Save a map in a txt file
        void ParseMap(std::string path); // Parse a map from a txt file
        ~Map() {};
    protected:
        Vector2 _size;
        // char[33][33] _map;
};
