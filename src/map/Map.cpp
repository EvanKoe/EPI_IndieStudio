/*
** EPITECH PROJECT, 2022
** EPI_IndieStudio [WSL : Ubuntu-22.04]
** File description:
** Map
*/

#include "./Map.hpp"
#include <fstream>

// void Map::Generator(size_t x, size_t y)
// {
//     std::string tmp;
//     for (int i = 0; i < y; i++) {
//         tmp.clear();
//         for (int j = 0; j < x; j++) {
//             if (i == 0 || i == 31 || j == 0 || j == 31)
//                 tmp += 'x';
//             else
//                 if (rand() % 2 == 0)
//                     tmp += ' ';
//                 else if (rand() % 10 == 0)
//                     tmp += '#';
//                 else
//                     tmp += 'x';
//         }
//         _map.push_back(tmp);
//     }
//     for (int i = 0; i < _map.size(); i++)
//         std::cout << _map[i] << std::endl;
//     SaveMap("map.txt");
// }

std::vector<std::string> Indie::Map::getMap() const
{
    return _map;
}

void Indie::Map::LoadMap(std::string path)
{
    std::filesystem::path my_path = path;
    if (!std::filesystem::exists(my_path.c_str())) {
        std::cout << "Error: map doesn't exist" << std::endl;
        return;
    }
    std::ifstream stream(my_path.string().c_str(), std::ios::binary);
    if (!stream)
        throw std::runtime_error("Cannot open file");
    std::string line;
    while (std::getline(stream, line)) {
        _map.push_back(line);
    }
    stream.close();
}

void Indie::Map::SaveMap(std::string path)
{
    std::filesystem::path my_path = path;
    if (!std::filesystem::exists(my_path.c_str())) {
        std::cout << "Error: file doesn't exist" << std::endl;
        return;
    }
    std::ofstream stream(my_path.string().c_str(), std::ios::binary);
    if (!stream)
        throw std::runtime_error("Cannot open file");
    for (int i = 0; i < _map.size(); i++)
        stream << _map[i] << std::endl;
    std::cout << "SaveMap" << std::endl;
    stream.close();
}
