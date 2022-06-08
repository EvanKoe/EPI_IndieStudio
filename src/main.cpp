/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** main
*/

#include "graphics/Display.hpp"
#include "Globals.hpp"
#include <raylib.h>

int main(int ac, char **av) {
    Indie::Display d(Indie::CURR_GAME, 1280, 720, "Indie studio");
    // just create a GameEngine class
    // Indie::GameEngine g;
    Indie::key_e k;

    while (!WindowShouldClose()) {
        d.draw();
        k = d.getEvents();
        // g.play(k);
    }
    return 0;
}
