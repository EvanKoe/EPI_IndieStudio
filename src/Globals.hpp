/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Globals
*/

#pragma once

#include <functional>
#include <raylib.h>
#include <string>

namespace Indie {
    // those are the different screens of the game
    enum State {
        MAIN_MENU,
        DIFF_MENU,
        LOAD_MENU,
        SETT_MENU,
        QUIT_MENU,
        CURR_GAME,
        LOSE_GAME,
        PAUSE_MENU,
        WIN_MENU
    };

    // useless settings : music mode
    enum MusicMode {
        DOOM_OSTS,
        MEDIEVAL_MODE,
        WTF_IS_THAT
    };

    typedef struct {
        MusicMode m;
        std::string to_str;
    } MusicMode_s;

    // difficuties
    enum Difficulty {
        EASY,
        MEDIUM,
        HARD
    };

    // used in Display.hpp
    typedef struct {
        State s;
        std::function<void (void)> fun;
    } StateAction;

    // keys struct
    typedef enum KEY {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        A, B, C, D,
        E, F, G, H,
        I, J, K, L,
        M, N, O, P,
        Q, R, S, T,
        U, V, W, X,
        Y, Z,
        Escape,
        Enter,
        KNull
    } key_e;

    typedef struct {
        KeyboardKey rayKey; // raylib key
        key_e std_key;      // our keys
    } key_s;

    static const key_s key_tab[] = {
        { KEY_UP, UP },
        { KEY_DOWN, DOWN },
        { KEY_LEFT, LEFT },
        { KEY_RIGHT, RIGHT },
        { KEY_A, A },
        { KEY_B, B },
        { KEY_C, C },
        { KEY_D, D },
        { KEY_E, E },
        { KEY_F, F },
        { KEY_G, G },
        { KEY_H, H },
        { KEY_I, I },
        { KEY_J, J },
        { KEY_K, K },
        { KEY_L, L },
        { KEY_M, M },
        { KEY_N, N },
        { KEY_O, O },
        { KEY_P, Q },
        { KEY_Q, Q },
        { KEY_R, R },
        { KEY_S, S },
        { KEY_T, T },
        { KEY_U, U },
        { KEY_V, V },
        { KEY_W, W },
        { KEY_X, X },
        { KEY_Y, Y },
        { KEY_Z, Z },
        { KEY_ENTER, Enter },
        { KEY_ESCAPE, Escape }
    };
};