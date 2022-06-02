/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** Display
*/

#include "raylib.h"
#include <iostream>
#include <list>
#include "./IGraphic.hpp"
#include "../Globals.hpp"
#include <memory>

namespace Indie {
  class Display {
    public:
      Display(int w = 1440, int h = 900, std::string title = "Raylib Window");
      int openWindow(State);
      ~Display();
    private:
      Coordinates _size;
  };
  //
  // void disp_menu(void);
  // void disp_diff(void);
  // void disp_load(void);
  // void disp_quit(void);
  // void disp_game(void);
  // void disp_lose(void);
  // void disp_pause(void);
  //
  // const StateAction stateArray[7] = {
  //   { MAIN_MENU, [](){ return disp_menu(); } },
  //   { DIFF_MENU, [](){ return disp_diff(); } },
  //   { LOAD_MENU, [](){ return disp_load(); } },
  //   { QUIT_MENU, [](){ return disp_quit(); } },
  //   { CURR_GAME, [](){ return disp_game(); } },
  //   { LOSE_GAME, [](){ return disp_lose(); } },
  //   { PAUSE_MENU, [](){ return disp_pause(); } }
  // };
};