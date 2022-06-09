/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** Display
*/

#include "Display.hpp"
#include "Objects/Cam.hpp"
#include "Objects/Musics.hpp"
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
        int size = _comp.size();

        for (int i = 0; i < size; ++i) {
            _comp.pop_back();
        }

        for (auto e: stateArray) {
            std::cout << e.s << " loul\n";
            if (e.s == s) {
                std::cout << "Switch to " << s << " type" << std::endl;
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
        std::unique_ptr<Picture> p1(new Picture("src/assets/img/title.png"));
        std::unique_ptr<Cam> p2(new Cam());
        std::unique_ptr<Text>p3(new Text("DoomerMan", 100, 50, 70));
        std::unique_ptr<Button> p4(new Button(
            "Play",
            [&](){
                std::cout << Indie::LOAD_MENU << std::endl;
                changeState(Indie::LOAD_MENU);
            },
            { 100, 200 }, { 350, 100 }, BLACK, RED
        ));
        std::unique_ptr<Button> p5(new Button(
            "Settings",
            [&](){
                std::cout << Indie::SETT_MENU << std::endl;
                changeState(Indie::SETT_MENU);
            },
            { 100, 350 }, { 350, 100 }, BLACK, RED
        ));
        std::unique_ptr<Button> p6(new Button(
            "Quit",
            [&](){ changeState(Indie::QUIT_MENU); },
            { 100, 500 }, { 350, 100 }, BLACK, RED
        ));
        _comp.push_back(std::move(p1));
        _comp.push_back(std::move(p2));
        _comp.push_back(std::move(p3));
        _comp.push_back(std::move(p4));
        _comp.push_back(std::move(p5));
        // _comp.push_back(std::make_unique<Musics>(Musics("src/assets/sounds/main_title.ogg", 50}\)));
    }

    void Display::create_load(void) {
        _comp.push_back(std::make_unique<Picture>(Picture("src/assets/img/title.png")));
        _comp.push_back(std::make_unique<Text>(Text("LOAD", 100, 50, 70)));
    }
    void Display::create_diff(void) {}
    void Display::create_quit(void) {
        _comp.push_back(std::make_unique<Picture>(Picture("src/assets/img/title.png")));
        _comp.push_back(std::make_unique<Text>(Text("QUIT", 100, 50, 70)));
    }
    void Display::create_game(void) {}
    void Display::create_settings(void) {
        _comp.push_back(std::make_unique<Picture>(Picture("src/assets/img/title.png")));
        _comp.push_back(std::make_unique<Text>(Text("SETTINGS", 100, 50, 70)));
    }

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