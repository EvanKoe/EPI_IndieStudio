/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** main
*/

#include "./GameCreator.hpp"

int main(int ac, char **av) {
  Indie::GameCreator g;
  g.getDisp().openWindow(Indie::MAIN_MENU);
  return 0;
}
