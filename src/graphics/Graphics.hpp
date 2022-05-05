/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** Graphics
*/

#include "raylib.h"
#include <iostream>

typedef struct {
  float x;
  float y;
} Coordinates;

class Graphics {
  public:
    Graphics(int w = 1440, int h = 900, std::string title = "Raylib Window");
    int openWindow();
    ~Graphics();
  private:
    Coordinates _size;
};
