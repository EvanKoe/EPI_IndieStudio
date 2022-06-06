/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** Display
*/

#include "Display.hpp"
#include "IGraphic.hpp"
#include "Button.hpp"
#include "Text.hpp"
#include <exception>
#include <memory>

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
        for (int i = 0; i < 33; ++i) {
            if (IsKeyDown(key_tab[i].rayKey))
                return key_tab[i].std_key;
        }
        return KNull;
    }

    void Display::free_comps(void) {
        if (_comp.size() == 0) {
            return;
        }
        for (auto e: _comp) {
            if (e == nullptr) {
                break;
            }
            delete(e);
        }
        return;
    }

    void Display::create_menu(void) {};
    void Display::create_diff(void) {};
    void Display::create_load(void) {};
    void Display::create_quit(void) {};

    void Display::create_game(void) {
        free_comps();
        _comp.push_back(new Button(
            "Button",
            [](){ std::cout << "putthe" << std::endl; },
            { 500, 500 }
        ));
        _comp.push_back(new Text("hello world !"));
        for (auto e: _comp) {
            std::cout << "putthe" << std::endl;
        }
    };

    void Display::create_lose(void) {};

    void Display::create_pause(void) {};

    void disp_game(void) {

    }

    Display::~Display() {
        CloseWindow();
    }
};