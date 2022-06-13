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
#include <exception>
#include <type_traits>
#include <time.h>

namespace Indie {
    class Display {
        public:
            Display(State s, int w = 1440, int h = 900, std::string title = "Raylib Window");
            void changeState(State);
            int draw(void);
            key_e getEvents(void);
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

            void add_image(std::string, std::string, std::string);
            bool is_pressed(Rectangle);

            const StateAction stateArray[9] = {
                { MAIN_MENU, [&](){ return create_menu(); } },
                { DIFF_MENU, [&](){ return create_diff(); } },
                { LOAD_MENU, [&](){ return create_load(); } },
                { QUIT_MENU, [&](){ return create_quit(); } },
                { SETT_MENU, [&](){ return create_settings(); } }, // create settings page
                { CURR_GAME, [&](){ return create_game(); } },
                { LOSE_GAME, [&](){ return create_lose(); } },
                { PAUSE_MENU, [&](){ return create_pause(); } },
                { WIN_MENU, [&](){ return create_win(); } }
            };
    };
};