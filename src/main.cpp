/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** main
*/

#include "./GameCreator.hpp"
#include <raylib.h>

int main(int ac, char **av) {
  Indie::GameCreator g;
  g.getDisp().openWindow(Indie::MAIN_MENU);
  while (!WindowShouldClose()) {

  }
  return 0;
}
