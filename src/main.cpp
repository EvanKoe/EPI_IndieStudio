/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** main
*/

#include "./graphics/Graphics.hpp"

int main(void) {
  Graphics *g = new Graphics();
  g->openWindow();
  std::cout << "Hello World !" << std::endl;
  delete(g);
  return 0;
}
