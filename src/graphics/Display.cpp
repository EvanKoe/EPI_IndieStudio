/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** Display
*/

#include "./Display.hpp"

namespace Indie {

Display::Display(int w, int h, std::string title) {
  _size.x = w;
  _size.y = h;
  InitWindow(w, h, title.c_str());
  SetTargetFPS(60);
}

int Display::openWindow(State state) {
  while (!WindowShouldClose()) {
    BeginDrawing();
    // for (auto element: stateArray) {
    //   if (state == element.s) {
    //     element.fun();
    //   }
    // }
    // ClearBackground(RAYWHITE);
    // DrawText("Hello world !", 100, 200, 30, LIGHTGRAY);
    EndDrawing();
  }
  return 0;
}

Display::~Display() {
  CloseWindow();
}

};