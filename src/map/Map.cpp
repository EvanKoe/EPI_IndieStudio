/*
** EPITECH PROJECT, 2022
** EPI_IndieStudio [WSL : Ubuntu-22.04]
** File description:
** Map
*/

#include "./Map.hpp"
#include <fstream>

void Map::Generator(size_t x, size_t y)
{
    std::cout << "Generator" << std::endl;
}

void Map::LoadMap(std::string path)
{
    std::filesystem::path my_path = path;
    std::filesystem::exists(my_path.c_str());
    std::ifstream stream(my_path.string().c_str(), std::ios::binary);
    if (!stream)
        throw std::runtime_error("Cannot open file");
    std::string line;
    for (int i = 0; std::getline(stream, line); ++i) {
        std::cout << line << std::endl;
        _map[i] = line;
    }
    stream.close();
}

void Map::SaveMap(std::string path)
{
    std::filesystem::path my_path = path;
    std::filesystem::exists(my_path.c_str());
    std::ifstream stream(my_path.string().c_str(), std::ios::binary);
    if (!stream)
        throw std::runtime_error("Cannot open file");
    // for (int i = 0; i < _map.size(); i++) {
    //     // stream << std::ifstream(_map[i]) << std::endl;
    // }
    std::cout << "SaveMap" << std::endl;
    stream.close();
}

void Map::ParseMap(std::string path)
{
    std::cout << "ParseMap" << std::endl;
}
