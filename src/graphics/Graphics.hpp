/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** Graphics
*/

#include "raylib.h"
#include <iostream>
#include <functional>
#include <list>
#include "./IGraphic.hpp"
#include <memory>

typedef struct {
  float x;
  float y;
} Coordinates;

enum States {
  MAIN_MENU,  // main menu
  DIFF_MENU,  // choosing difficulty
  LOAD_MENU,  // choosing which save to load
  QUIT_MENU,  // before quitting
  CURR_GAME,  // while playing
  LOSE_GAME,  // if loose
  PAUSE_MENU  // if pause
};

class Graphics {
  public:
    Graphics(int w = 1440, int h = 900, std::string title = "Raylib Window");
    int openWindow(States);
    ~Graphics();
  private:
    Coordinates _size;
};

void disp_menu(void);
void disp_diff(void);
void disp_load(void);
void disp_quit(void);
void disp_game(void);
void disp_lose(void);
void disp_pause(void);

typedef struct {
  States s;
  std::function<void (void)> fun;
} StateAction;

const StateAction stateArray[7] = {
  { MAIN_MENU, [](){ return disp_menu(); } },
  { DIFF_MENU, [](){ return disp_diff(); } },
  { LOAD_MENU, [](){ return disp_load(); } },
  { QUIT_MENU, [](){ return disp_quit(); } },
  { CURR_GAME, [](){ return disp_game(); } },
  { LOSE_GAME, [](){ return disp_lose(); } },
  { PAUSE_MENU, [](){ return disp_pause(); } }
};