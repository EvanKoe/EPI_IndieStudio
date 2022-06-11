/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** Display
*/

#include "Display.hpp"
#include "IGraphic.hpp"
#include "Objects/Button.hpp"
#include "Objects/Cam.hpp"
#include "Objects/Musics.hpp"
#include "Objects/Picture.hpp"
#include "Objects/Sprite.hpp"
#include <iostream>
#include <memory>
#include <raylib.h>

namespace Indie {
    const std::string BGIMG = "./src/assets/img/title.png";

    Display::Display(State s, int w, int h, std::string title): _mus(Musics(DOSTS[0])) {
        _size.x = w;
        _size.y = h;
        _cam = { 0 };
        InitWindow(w, h, title.c_str());
        changeState(s);
        _selected_mus = musicArray[0];
        SetTargetFPS(60);
    }

    void Display::changeState(State s) {
        _comp.clear();

        for (auto e: stateArray) {
            if (e.s == s) {
                e.fun();
                if (!_is3D) {
                    _cam = { 0 };
                }
                break;
            }
        }
        return;
    }

    int Display::draw(void) {
        BeginDrawing();
        ClearBackground(BLACK);
        if (_is3D) {
            UpdateCamera(&_cam);
            BeginMode3D(_cam);
            DrawGrid(32, 1.0f);
            for (const auto &e: _comp) {
                if (e->getIs3D()) {
                    e->draw();
                }
            }
            EndMode3D();
        }
        DrawFPS(1200, 50);
        for (const auto &e: _comp) {
            if (!e->getIs3D()) {
                e->draw();
            }
        }
        EndDrawing();
        return 0;
    }

    key_e Display::getEvents(void)
    {
        if (_comp.size() == 0)
            return KNull;
        UpdateMusicStream(_mus.getStream());
        for (const auto &e: _comp) {
            if (e->isHover()) {
                e->onHover();
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    e->onClick();
                    break;
                }
            } else {
                e->onHoverEnd();
            }
        }

        for (int i = 0; i < 33; ++i) {
            if (IsKeyDown(key_tab[i].rayKey))
                return key_tab[i].std_key;
        }
        return KNull;
    }

    void Display::create_menu(void) {
        std::cout << "create menu\n";
        _is3D = false;
        std::unique_ptr<Picture> p1(new Picture(BGIMG));
        std::unique_ptr<Cam> p2(new Cam());
        std::unique_ptr<Text>p3(new Text("DoomerMan", 100, 50, 70));
        std::unique_ptr<Button> p4(new Button("Play",
            [&](){ changeState(Indie::LOAD_MENU); },
            { 100, 200 }, { 350, 100 }, BLACK, RED
        ));
        std::unique_ptr<Button> p5(new Button("Settings",
            [&](){ changeState(Indie::SETT_MENU); },
            { 100, 350 }, { 350, 100 }, BLACK, RED
        ));
        std::unique_ptr<Button> p6(new Button("Quit",
            [&](){ changeState(Indie::QUIT_MENU); },
            { 100, 500 }, { 350, 100 }, BLACK, RED
        ));
        _comp.push_back(std::move(p1));
        _comp.push_back(std::move(p2));
        _comp.push_back(std::move(p3));
        _comp.push_back(std::move(p4));
        _comp.push_back(std::move(p5));
        _comp.push_back(std::move(p6));
    }

    void Display::create_load(void) {
        std::cout << "create load\n";
        _is3D = false;
        _comp.push_back(std::make_unique<Picture>(Picture(BGIMG)));
        _comp.push_back(std::make_unique<Text>(Text("LOAD", 100, 50, 70)));
        _comp.push_back(std::make_unique<Button>(Button("New game",
            [&](){ changeState(Indie::DIFF_MENU); },
            { 100, 350 }, { 350, 100 }, BLACK, RED
        )));
    }
    void Display::create_diff(void) {
        std::cout << "create diff\n";
        _is3D = false;

        _comp.push_back(std::make_unique<Picture>(Picture(BGIMG)));
        _comp.push_back(std::make_unique<Text>(Text("New game - difficulty", 100, 50, 60)));
        _comp.push_back(std::make_unique<Button>(Button("I'm too young to die",
            [&](){ _diff = IM_TOO_YOUNG_TO_DIE; changeState(Indie::CURR_GAME); },
            { 100, 150 }, { 550, 100 }, BLACK, RED
        )));
        _comp.push_back(std::make_unique<Button>(Button("Hurt me plenty",
            [&](){ _diff = HURT_ME_PLENTY; changeState(Indie::CURR_GAME); },
            { 100, 300 }, { 550, 100 }, BLACK, RED
        )));
        _comp.push_back(std::make_unique<Button>(Button("Nightmare",
            [&](){ _diff = NIGHTMARE; changeState(Indie::CURR_GAME); },
            { 100, 450 }, { 550, 100 }, BLACK, RED
        )));
    }

    void Display::create_quit(void) {
        std::cout << "create quit\n";
        _is3D = false;
        _comp.push_back(std::make_unique<Picture>(Picture(BGIMG)));
        _comp.push_back(std::make_unique<Text>(Text("QUIT", 100, 50, 70)));
        _comp.push_back(std::make_unique<Text>(Text("Voulez-vous vraiment quitter ?", 150, 200, 40)));
        _comp.push_back(std::make_unique<Button>(Button(
            "Oui (pour les faibles)",
            [&](){ CloseWindow(); exit(0); }, { 100, 350 }, { 500, 100 }, BLACK, RED
        )));
        _comp.push_back(std::make_unique<Button>(Button(
            "Non (pour les héros)",
            [&](){ changeState(Indie::MAIN_MENU); }, { 700, 350 }, { 500, 100 }, BLACK, RED
        )));
    }

    void Display::create_game(void) {
        std::cout << "create game\n";
        _is3D = true;
        _cam = Cam().getCamera();

        _comp.push_back(std::make_unique<Text>(Text("Game", 10, 10, 40, WHITE)));
        _comp.push_back(std::make_unique<Sprite>(Sprite(
            "assets/icon-of-sin-toy/Icon of sin Toy.iqm"
        )));
    }

    void Display::create_settings(void) {
        _is3D = false;

        _comp.push_back(std::make_unique<Picture>(Picture(BGIMG)));
        _comp.push_back(std::make_unique<Button>(Button("<-",
            [&](){ changeState(Indie::MAIN_MENU); },
            { 100, 50 }, { 90, 50 }, BLACK, RED
        )));
        _comp.push_back(std::make_unique<Text>(Text("SETTINGS", 200, 50, 70)));
        _comp.push_back(std::make_unique<Text>(Text("Music :", 100, 150, 70)));
        _comp.push_back(std::make_unique<Button>(Button(_selected_mus.to_str,
            [&](){ _selected_mus = _selected_mus.m == 2 ? musicArray[0] : musicArray[_selected_mus.m + 1]; },
            { 100, 350 }, { 500, 100 }, BLACK, RED
        )));
    }

    void Display::create_lose(void) {
        _is3D = false;

        _comp.push_back(std::make_unique<Picture>(Picture(BGIMG)));
        _comp.push_back(std::make_unique<Text>(Text("YOU LOST", 100, 50, 70)));
        _comp.push_back(std::make_unique<Text>(Text("But you won't let the demons win again, will you ?", 150, 200, 40)));
        _comp.push_back(std::make_unique<Button>(Button(
            "Let's kick their ass (play again)",
            [&](){ changeState(CURR_GAME); }, { 100, 350 }, { 800, 100 }, BLACK, RED
        )));
        _comp.push_back(std::make_unique<Button>(Button(
            "I think Imma take a nap (Quit)",
            [&](){ changeState(Indie::MAIN_MENU); }, { 100, 500 }, { 800, 100 }, BLACK, RED
        )));
    };

    void Display::create_win(void) {
        _is3D = false;

        _comp.push_back(std::make_unique<Picture>(Picture(BGIMG)));
        _comp.push_back(std::make_unique<Text>(Text("YOU WON !", 100, 50, 70)));
        _comp.push_back(std::make_unique<Text>(Text("But you're not tired yet, are you ?", 150, 200, 40)));
        _comp.push_back(std::make_unique<Button>(Button(
            "I'm still hungry ! (play again)",
            [&](){ changeState(CURR_GAME); }, { 100, 350 }, { 800, 100 }, BLACK, RED
        )));
        _comp.push_back(std::make_unique<Button>(Button(
            "I need to sleep a bit (Quit)",
            [&](){ changeState(Indie::MAIN_MENU); }, { 100, 500 }, { 800, 100 }, BLACK, RED
        )));
    };

    void Display::create_pause(void) {
        _is3D = false;
    };

    bool Display::is_pressed(Rectangle rec) {
        return (
            IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
            rec.x < GetMouseX() && GetMouseY() < rec.y &&
            GetMouseX() < rec.x + rec.width && GetMouseY() < rec.y + rec.height
        );
    }

    Display::~Display() {
        CloseWindow();
    }
};