/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** Display
*/

#include <raylib.h>
#include <iostream>
#include <list>
#include "IGraphic.hpp"
#include "../Globals.hpp"
#include <memory>
#include <vector>
#include <cstdlib>

#include "Objects/Button.hpp"
#include "Objects/Text.hpp"
#include "Objects/Musics.hpp"
#include "Objects/Picture.hpp"
#include "Objects/Text.hpp"
#include "Objects/Cam.hpp"
#include "Objects/MeshMap.hpp"
#include <exception>
#include <type_traits>
#include <time.h>
#include "Sprite.hpp"
#include "GameObject.hpp"
#include "Engine.hpp"
#include <chrono>
namespace Indie {
    class Display {
        public:
            Display(State s, int w = 1440, int h = 900, std::string title = "Raylib Window");
            void changeState(State);
            int draw(void);
            int getEvents(Engine &e);
            Musics getMusic(void) { return _mus; }
            void addComp(IGraphic &);
            ~Display();
        private:
            Vector2 _size;
            std::vector<std::unique_ptr<IGraphic>> _comp;
            Camera3D _cam;
            bool _is3D;
            Difficulty _diff;
            Musics _mus;
            int _fps;
            State _state;
            std::chrono::system_clock::time_point _clock;

            // settings
            MusicMode_s _selected_mus;

            void create_menu(void);
            void create_diff(void);
            void create_load(void);
            void create_quit(void);
            void create_game(void);
            void create_lose(void);
            void create_pause(void);
            void create_settings(void);
            void create_win(void);
            void create_splash(void);

            void add_image(int, std::string, std::string, std::string, std::string, float scale = 1.0f, Vector3 pos = { 0 });
            bool is_pressed(Rectangle);
            void move_slayer(int, float x, float y);

            const StateAction stateArray[10] = {
                { MAIN_MENU, [&](){ return create_menu(); } },
                { DIFF_MENU, [&](){ return create_diff(); } },
                { LOAD_MENU, [&](){ return create_load(); } },
                { QUIT_MENU, [&](){ return create_quit(); } },
                { SETT_MENU, [&](){ return create_settings(); } }, // create settings page
                { CURR_GAME, [&](){ return create_game(); } },
                { LOSE_GAME, [&](){ return create_lose(); } },
                { PAUSE_MENU, [&](){ return create_pause(); } },
                { WIN_MENU, [&](){ return create_win(); } },
                { SPLASH_SCR, [&](){ return create_splash(); } }
            };

            const events_t eventTab[9] = {
                { KEY_A, [&](){ move_slayer(0, -0.1, 0.0); } },
                { KEY_W, [&](){ move_slayer(0, 0.0, -0.1); } },
                { KEY_S, [&](){ move_slayer(0, 0.0, 0.1); } },
                { KEY_D, [&](){ move_slayer(0, 0.1, 0.0); } },
                { KEY_UP, [&](){ move_slayer(1, 0.0, -0.1 ); } },
                { KEY_DOWN, [&](){ move_slayer(1, 0.0, 0.1); } },
                { KEY_LEFT, [&](){ move_slayer(1, -0.1, 0.0 ); } },
                { KEY_RIGHT, [&](){ move_slayer(1, 0.1, 0.0 ); } },
                { KEY_ESCAPE, [&](){ changeState(PAUSE_MENU); } }
            };
    };
};