/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** Display
*/

#include "Display.hpp"
#include "Objects/Cam.hpp"
#include <memory>
#include <raylib.h>

namespace Indie {
    Display::Display(State s, int w, int h, std::string title) {
        _size.x = w;
        _size.y = h;
        InitWindow(w, h, title.c_str());
        changeState(s);
        SetTargetFPS(60);
    }

    void Display::changeState(State s) {
        for (auto e: stateArray) {
            if (e.s == s) {
                return e.fun();
            }
        }
        return;
    }

    int Display::draw(void) {
        BeginDrawing();
        ClearBackground(BLACK);
        for (auto e: _comp) {
            e->draw();
        }
        EndDrawing();
        return 0;
    }

    key_e Display::getEvents(void)
    {
        for (auto e: _comp) {
            if (e->isHover()) {
                std::cout << "putthe" << std::endl;
                e->onHover();
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    e->onClick();
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
        _comp.push_back(std::make_shared<Picture>(Picture("src/assets/img/title.png")));
        _comp.push_back(std::make_shared<Cam>(Cam()));
        _comp.push_back(std::make_shared<Text>(Text("DoomerMan", 100, 50, 70)));
        _comp.push_back(std::make_shared<Button>(Button(
            "Play",
            [&](){ changeState(Indie::LOAD_MENU); },
            { 100, 200 },
            { 350, 100 },
            BLACK,
            RED
        )));
        _comp.push_back(std::make_shared<Button>(Button(
            "Settings",
            [&](){ changeState(Indie::SETT_MENU); },
            { 100, 350 },
            { 350, 100 },
            BLACK,
            RED
        )));
        _comp.push_back(std::make_shared<Button>(Button(
            "Quit",
            [&](){ changeState(Indie::QUIT_MENU); },
            { 100, 500 },
            { 350, 100 },
            BLACK,
            RED
        )));
        _comp.push_back(std::make_shared<Picture>(Picture("src/assets/sounds/main_title.ogg")));
    }

    void Display::create_diff(void) {}
    void Display::create_load(void) {}
    void Display::create_quit(void) {}
    void Display::create_game(void) {}
    void Display::create_settings(void) {}

    bool Display::is_pressed(Rectangle rec) {
        return (
            IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
            rec.x < GetMouseX() && GetMouseY() < rec.y &&
            GetMouseX() < rec.x + rec.width && GetMouseY() < rec.y + rec.height
        );
    }

    void Display::create_lose(void) {};

    void Display::create_pause(void) {};

    void disp_game(void) {

    }

    Display::~Display() {
        CloseWindow();
    }
};