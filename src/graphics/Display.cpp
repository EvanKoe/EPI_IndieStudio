/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** Display
*/

#include "Display.hpp"
#include "IGraphic.hpp"
#include "Button.hpp"
#include "Cam.hpp"
#include "Musics.hpp"
#include "Picture.hpp"
#include "Sprite.hpp"
#include <iostream>
#include <memory>
#include <raylib.h>

namespace Indie {
    const std::string BGIMG = "./src/assets/img/title.png";

    Display::Display(State s, int w, int h, std::string title): _mus(Musics(DOSTS[0], 0)) {
        _size.x = w;
        _size.y = h;
        _state = s;
        _cam = { 0 };
        _is3D = false;
        InitWindow(w, h, title.c_str());
        changeState(s);
        _selected_mus = musicArray[0];
        SetTargetFPS(30);
    }

    void Display::changeState(State s) {
        _comp.clear();
        _state = s;

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
        ClearBackground(GetColor(0x313131ff));

        if (_is3D) {
            BeginMode3D(_cam);
            UpdateCamera(&_cam);     // Disables zoom on scroll
            // DrawGrid(32, 1.0f);   // Disables grid
            for (const auto &e: _comp) {
                if (e.get()->getIs3D()) {
                    e.get()->draw();
                }
            }
            EndMode3D();
        }
        for (const auto &e: _comp) {
            if (!e->getIs3D()) {
                e->draw();
            }
        }
        DrawFPS(1200, 10);
        EndDrawing();
        if (_state == SPLASH_SCR) {
            float a = std::chrono::duration<double, std::milli>(
                std::chrono::high_resolution_clock::now() - _clock
            ).count();
            if (a > 3000)
                changeState(CURR_GAME);
        }
        return 0;
    }

    void Display::move_slayer(float x, float y)
    {
        if (!_is3D) {
            return;
        }
        Sprite *s = nullptr;
        Vector3 r = { 0 };

        for (const auto &e: _comp) {
            s = (Sprite *)e.get();
            float z = y == 0.0f ? (x == -0.1f ? 270.0f : 90.0f) : (y == 0.1f ? 0.0f : 180.0f);
            r = s->getPos();
            if (e.get()->getID() == 0) {
                if (!s->is_running()) {
                    s->setAnimation("assets/doom/run.iqm");
                    s->set_running(true);
                }
                s->setPos(
                    r.x + x < -15.2f || r.x + x > 17.0f ? r.x : r.x + x,
                    0,
                    r.z + y < -15.7f || r.z + y > 17.0f ? r.z : r.z + y
                );
                s->setRotation(z);
            }
        }
    }

    int Display::getEvents(Engine &e)
    {
        int k = 0;

        if (_comp.size() == 0)
            return KNull;
        UpdateMusicStream(_mus.getStream());

        // Buttons (2D)
        for (const auto &e: _comp) {
            if (e.get()->isHover()) {
                e.get()->onHover();
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    e.get()->onClick();
                    break;
                }
            } else {
                e.get()->onHoverEnd();
            }
        }

        // Keys (3D)
        for (auto e: eventTab) {
            if (IsKeyDown(e.key)) {
                e.fun();
                return 0;
            }
        }
        for (const auto &e: _comp) {
            if (e.get()->getID() == 0 && ((Sprite *)e.get())->is_running()) {
                ((Sprite *)e.get())->setAnimation("assets/doom/standing.iqm");
                ((Sprite *)e.get())->set_running(false);
                return 1;
            }
        }
        return 0;
    }

    void Display::create_splash(void) {
        _is3D = false;
        srand(time(NULL));

        _comp.push_back(std::make_unique<Picture>(Picture("./src/assets/img/loading.png")));
        _comp.push_back(std::make_unique<Text>(Text("DOOMERMAN", 100, 50, 70)));
        _comp.push_back(std::make_unique<Text>(Text("Loading ...", 100, 150, 70)));
        _comp.push_back(std::make_unique<Text>(Text(tipsArray[rand() % 6], 100, 300, 20)));
        _clock = std::chrono::high_resolution_clock::now();
    }

    void Display::create_menu(void) {
        _is3D = false;
        std::unique_ptr<Picture> p1(new Picture(BGIMG));
        std::unique_ptr<Text>p3(new Text("DOOMERMAN", 100, 50, 70));
        std::unique_ptr<Button> p4(new Button("Play",
            [&](){ changeState(Indie::LOAD_MENU); },
            { 100, 200 }, { 350, 100 }, LIGHTGRAY, RED
        ));
        std::unique_ptr<Button> p5(new Button("Settings",
            [&](){ changeState(Indie::SETT_MENU); },
            { 100, 350 }, { 350, 100 }, LIGHTGRAY, RED
        ));
        std::unique_ptr<Button> p6(new Button("Quit",
            [&](){ changeState(Indie::QUIT_MENU); },
            { 100, 500 }, { 350, 100 }, LIGHTGRAY, RED
        ));
        _comp.push_back(std::move(p1));
        _comp.push_back(std::move(p3));
        _comp.push_back(std::move(p4));
        _comp.push_back(std::move(p5));
        _comp.push_back(std::move(p6));
    }

    void Display::create_load(void) {
        _is3D = false;
        _comp.push_back(std::make_unique<Picture>(Picture(BGIMG)));
        _comp.push_back(std::make_unique<Text>(Text("LOAD", 100, 50, 70)));
        _comp.push_back(std::make_unique<Button>(Button("New game",
            [&](){ changeState(Indie::DIFF_MENU); },
            { 100, 350 }, { 350, 100 }, LIGHTGRAY, RED
        )));
    }
    void Display::create_diff(void) {
        _is3D = false;

        _comp.push_back(std::make_unique<Picture>(Picture(BGIMG)));
        _comp.push_back(std::make_unique<Text>(Text("New game - difficulty", 100, 50, 60)));
        _comp.push_back(std::make_unique<Button>(Button("I'm too young to die",
            [&](){ _diff = IM_TOO_YOUNG_TO_DIE; changeState(Indie::SPLASH_SCR); },
            { 100, 150 }, { 550, 100 }, LIGHTGRAY, RED
        )));
        _comp.push_back(std::make_unique<Button>(Button("Hurt me plenty",
            [&](){ _diff = HURT_ME_PLENTY; changeState(Indie::SPLASH_SCR); },
            { 100, 300 }, { 550, 100 }, LIGHTGRAY, RED
        )));
        _comp.push_back(std::make_unique<Button>(Button("Nightmare",
            [&](){ _diff = NIGHTMARE; changeState(Indie::SPLASH_SCR); },
            { 100, 450 }, { 550, 100 }, LIGHTGRAY, RED
        )));
    }

    void Display::create_quit(void) {
        _is3D = false;
        _comp.push_back(std::make_unique<Picture>(Picture(BGIMG)));
        _comp.push_back(std::make_unique<Text>(Text("QUIT", 100, 50, 70)));
        _comp.push_back(std::make_unique<Text>(Text("Voulez-vous vraiment quitter ?", 150, 200, 40)));
        _comp.push_back(std::make_unique<Button>(Button(
            "Oui (pour les faibles)",
            [&](){ CloseWindow(); exit(0); }, { 100, 350 }, { 500, 100 }, LIGHTGRAY, RED
        )));
        _comp.push_back(std::make_unique<Button>(Button(
            "Non (pour les héros)",
            [&](){ changeState(Indie::MAIN_MENU); }, { 700, 350 }, { 500, 100 }, LIGHTGRAY, RED
        )));
    }

    void Display::add_image(int id, std::string path, std::string a, std::string b, std::string c, float scale, Vector3 pos)
    {
        std::unique_ptr<Sprite> s = std::make_unique<Sprite>(Sprite(id, path + a, path + b, path + c, scale));
        s.get()->setPos(pos.x, pos.y, pos.z);
        _comp.push_back(std::move(s));
    }

    void Display::create_game(void) {
        _is3D = true;
        _cam = Cam().getCamera();

        add_image(0, "assets/doom/", "run.iqm", "texture.png", "standing.iqm", 11.0f, { 1.0f, 0.0f, 1.0f });
        add_image(1, "assets/icon/", "run.iqm", "texture.png", "standing.iqm", 10.0f, { 13.0f, 0.0f, 13.0f });
        add_image(2, "assets/gladiator/", "run.iqm", "texture.png", "standing.iqm", 10.0f, { -11.0f, 0.0f, -11.0f });
        _comp.push_back(std::make_unique<MeshMap>(MeshMap("assets/map/map.png")));
        _comp.push_back(std::make_unique<Button>(Button("MENU",
            [&](){ changeState(Indie::PAUSE_MENU); },
            { 10, 10 }, { 150, 50 }, LIGHTGRAY, RED
        )));
    }

    void Display::create_settings(void) {
        _is3D = false;
        srand(time(NULL));

        _comp.push_back(std::make_unique<Picture>(Picture(BGIMG)));
        _comp.push_back(std::make_unique<Button>(Button("<-",
            [&](){ changeState(Indie::MAIN_MENU); },
            { 100, 60 }, { 90, 45 }, LIGHTGRAY, RED
        )));
        _comp.push_back(std::make_unique<Text>(Text("SETTINGS", 250, 50, 70)));

        // Music choice buttons
        _comp.push_back(std::make_unique<Text>(Text("Music :", 100, 150, 70)));
        _comp.push_back(std::make_unique<Button>(Button(musicArray[0].to_str,
            [&](){
                _selected_mus = { musicArray[0].m, musicArray[0].to_str };
                _mus.setMusic(DOSTS[rand() % 2]);
            },
            { 100, 250 }, { 300, 100 }, LIGHTGRAY, RED
        )));
        _comp.push_back(std::make_unique<Button>(Button(musicArray[1].to_str,
            [&](){
                _selected_mus = { musicArray[1].m, musicArray[1].to_str };
                _mus.setMusic(MOSTS[rand() % 2]);
            },
            { 450, 250 }, { 300, 100 }, LIGHTGRAY, RED
        )));
        _comp.push_back(std::make_unique<Button>(Button(musicArray[2].to_str,
            [&](){
                _selected_mus = { musicArray[2].m, musicArray[2].to_str };
                _mus.setMusic(WOSTS[rand() % 3]);
            },
            { 800, 250 }, { 300, 100 }, LIGHTGRAY, RED
        )));

        // FPS choice buttons
        _comp.push_back(std::make_unique<Text>(Text("FPS Limit :", 100, 400, 70)));
        _comp.push_back(std::make_unique<Button>(Button("30 FPS",
            [&](){ SetTargetFPS(30); },
            { 100, 500 }, { 300, 100 }, LIGHTGRAY, RED
        )));
        _comp.push_back(std::make_unique<Button>(Button("60 FPS",
            [&](){ SetTargetFPS(60); },
            { 450, 500 }, { 300, 100 }, LIGHTGRAY, RED
        )));
        _comp.push_back(std::make_unique<Button>(Button("144 FPS",
            [&](){ SetTargetFPS(144); },
            { 800, 500 }, { 300, 100 }, LIGHTGRAY, RED
        )));
    }

    void Display::create_lose(void) {
        _is3D = false;

        _comp.push_back(std::make_unique<Picture>(Picture(BGIMG)));
        _comp.push_back(std::make_unique<Text>(Text("YOU LOST", 100, 50, 70)));
        _comp.push_back(std::make_unique<Text>(Text("But you won't let the demons win again, will you ?", 150, 200, 40)));
        _comp.push_back(std::make_unique<Button>(Button(
            "Let's kick their ass (play again)",
            [&](){ changeState(CURR_GAME); }, { 100, 350 }, { 800, 100 }, LIGHTGRAY, RED
        )));
        _comp.push_back(std::make_unique<Button>(Button(
            "I think Imma take a nap (Quit)",
            [&](){ changeState(Indie::MAIN_MENU); }, { 100, 500 }, { 800, 100 }, LIGHTGRAY, RED
        )));
    };

    void Display::create_win(void) {
        _is3D = false;

        _comp.push_back(std::make_unique<Picture>(Picture(BGIMG)));
        _comp.push_back(std::make_unique<Text>(Text("YOU WON !", 100, 50, 70)));
        _comp.push_back(std::make_unique<Text>(Text("But you're not tired yet, are you ?", 150, 200, 40)));
        _comp.push_back(std::make_unique<Button>(Button(
            "I'm still hungry ! (play again)",
            [&](){ changeState(CURR_GAME); }, { 100, 350 }, { 800, 100 }, LIGHTGRAY, RED
        )));
        _comp.push_back(std::make_unique<Button>(Button(
            "I need to sleep a bit (Quit)",
            [&](){ changeState(Indie::MAIN_MENU); }, { 100, 500 }, { 800, 100 }, LIGHTGRAY, RED
        )));
    };

    void Display::create_pause(void) {
        _is3D = false;

        _comp.push_back(std::make_unique<Picture>(Picture(BGIMG)));
        _comp.push_back(std::make_unique<Text>(Text("Menu pause", 100, 50, 60)));
        _comp.push_back(std::make_unique<Button>(Button("Resume",
            [&](){ changeState(Indie::CURR_GAME); },
            { 100, 150 }, { 550, 100 }, LIGHTGRAY, RED
        )));
        _comp.push_back(std::make_unique<Button>(Button("Settings",
            [&](){ changeState(Indie::SETT_MENU); },
            { 100, 300 }, { 550, 100 }, LIGHTGRAY, RED
        )));
        _comp.push_back(std::make_unique<Button>(Button("Return to menu",
            [&](){ changeState(Indie::MAIN_MENU); },
            { 100, 450 }, { 550, 100 }, LIGHTGRAY, RED
        )));
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