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
#include <cstdlib>
#include <memory>

namespace Indie {
    typedef struct {
        float x;
        float y;
        float z;
    } pos_t;

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
        WIN_MENU,
        SPLASH_SCR
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
        IM_TOO_YOUNG_TO_DIE,
        HURT_ME_PLENTY,
        NIGHTMARE
    };

    // used in Display.hpp
    typedef struct {
        State s;
        std::function<void (void)> fun;
    } StateAction;

    const std::string runToIdTab[] = {
        "assets/doom/run.iqm",
        "assets/icon/run.iqm",
        "assets/marauder/run.iqm"
    };

    const std::string standToIdTab[] = {
        "assets/doom/standing.iqm",
        "assets/icon/standing.iqm",
        "assets/marauder/standing.iqm"
    };

    // musics
    const std::string DOSTS[2] = {
        "src/assets/sounds/bfg10k.ogg",
        "src/assets/sounds/main_title.ogg"
    };

    const std::string MOSTS[2] = {
        "src/assets/sounds/medieval_rip_and_tear.ogg",
        "src/assets/sounds/medieval_bfg_division.ogg"
    };

    const std::string WOSTS[3] = {
        "src/assets/sounds/doomdoomdoom.ogg",
        "src/assets/sounds/code_avec_le_q.ogg",
        "src/assets/sounds/toujours_vivant.ogg"
    };

    const MusicMode_s musicArray[3] = {
        { DOOM_OSTS, "Doom OSTs" },
        { MEDIEVAL_MODE, "Medieval Mode" },
        { WTF_IS_THAT, "WTF is that ?!" }
    };

    const std::string tipsArray[5] = {
        "In order to kill a Tyrant, shoot at it until it dies.",
        "Rip and tear, until it is done.",
        "Did you know you could change the soundtrack in the settings ?",
        "More FPS = more time to appreciate your fight !",
        "Marauder once said that you were a usurper. Make him regret."
    };

    // Events
    typedef struct {
        KeyboardKey key;
        std::function<void (void)> fun;
    } events_t;

    // Sprite
    typedef enum {
        STANDING,
        BLOW_UP,
        STRAFE_LEFT,
        STRAFE_RIGHT,
        GO_UP,
        GO_DOWN,
        DROP_BOMB,
        DEATH,
        RUN
    } AnimType;
    typedef struct {
        ModelAnimation anim;
        AnimType type;
        std::string path;
    } Anims;

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

    // Used in Game Engine

    typedef enum GameObjectsIds {
        PLAYER = 0,
        ENEMY = 1,
        WALL = 2,
        BRICK = 3,
        POWERUP = 4,
        BOMB = 5,
        NONE = -1
    } game_object_id_e;

    typedef struct {
        game_object_id_e id;
        std::string path;
        std::string texture;
        std::string animate;
    } textures_s;

    static const textures_s textures_tab[6] = {
        { PLAYER, "assets/doom/run.iqm", "assets/doom/texture.png", "assets/doom/standing.iqm" },
        { ENEMY, "assets/icon/run.iqm", "assets/icon/texture.png", "assets/icon/standing.iqm" },
        { BRICK, "EMPTY", "EMPTY", "EMPTY" },
        { POWERUP, "EMPTY", "EMPTY", "EMPTY" },
        { BOMB, "EMPTY", "EMPTY", "EMPTY" },
        { WALL, "EMPTY", "EMPTY", "EMPTY" }
    };

    enum PowerUpAttribute {
        BOMB_UP,
        SPEED_UP,
        FIRE_UP,
        BOMB_DOWN,
        SPEED_DOWN,
        FIRE_DOWN,
        WALL_PASS_UP,
        WALL_PASS_DOWN
    };
};