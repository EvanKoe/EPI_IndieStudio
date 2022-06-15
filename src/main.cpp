/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** main
*/

#include "graphics/Display.hpp"
#include "Globals.hpp"
#include <raylib.h>
#include "map/Map.hpp"
#include "Engine.hpp"

int main(int ac, char **av) {
    Indie::Display d(Indie::MAIN_MENU, 1280, 720, "Indie studio");
    Indie::Map m;
    m.LoadMap("map.txt");
    // for (auto & i : m._map)
    //     std::cout << i << std::endl;
    Indie::Engine g(m._map, 1);
    std::vector<std::unique_ptr<GameObject>> gcomps;
    int k;

    while (!WindowShouldClose()) {
        d.draw(gcomps);
        k = d.getEvents(gcomps);
        // g.play(k);
    }
    exit(0);
}
