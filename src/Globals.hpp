/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Globals
*/

#pragma once

#include <functional>

namespace Indie {
    // those are the different screens of the game
    enum State {
        MAIN_MENU,
        DIFF_MENU,
        LOAD_MENU,
        QUIT_MENU,
        CURR_GAME,
        LOSE_GAME,
        PAUSE_MENU
    };

    // difficuties
    enum Difficulty {
        EASY,
        MEDIUM,
        HARD
    };

    // a struct with a position x and y
    typedef struct {
        float x;
        float y;
    } Coordinates;

    // used in Display.hpp
    typedef struct {
        State s;
        std::function<void (void)> fun;
    } StateAction;
}