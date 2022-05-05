/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** Graphics
*/

#include "./Graphics.hpp"
#include "raylib.h"

Graphics::Graphics(int w, int h, std::string title) {
  _size.x = w;
  _size.y = h;
  InitWindow(w, h, title.c_str());
  SetTargetFPS(60);
}

int Graphics::openWindow(void) {
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Hello world !", 100, 200, 30, LIGHTGRAY);
    EndDrawing();
  }
  return 0;
}

Graphics::~Graphics() {
  CloseWindow();
}
