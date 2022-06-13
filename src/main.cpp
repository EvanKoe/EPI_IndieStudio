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

int main(int ac, char **av) {
    Indie::Display d(Indie::MAIN_MENU, 1280, 720, "Indie studio");
    // just create a GameEngine class
    // Indie::GameEngine g;
    Indie::key_e k;

    Map m;
    m.Generator(32, 32);
    while (!WindowShouldClose()) {
        d.draw();
        k = d.getEvents();
        // g.play(k);
    }
    exit(0);
}
