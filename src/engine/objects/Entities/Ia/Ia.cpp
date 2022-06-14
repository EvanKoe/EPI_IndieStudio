/*
** EPITECH PROJECT, 2022
** EPI_IndieStudio
** File description:
** ia
*/

#include "Ia.hpp"

void Indie::IA::IAScript(int x, int y, const std::string &filepath)
{
    this->_map.resize(WIDTH_MAP);
    this->_timer_respawn = 0;

    for (int i = 0; i < WIDTH_MAP; i++)
        this->_map[i].resize(HEIGHT_MAP);
    for (int i = 0; i < WIDTH_MAP; i++)
        for (int j = 0; j < HEIGHT_MAP; j++)
            this->_map[i][j] = 0;
}

void Indie::IA::Create()
{
    //créer l'IA comme perso
}

void Indie::IA::Update()
{
	//update l'ia en direct entités etc
}

void Indie::IA::drop_bomb()
{
	//apppeler drop bomb
}

void Indie::IA::move_ia_safe()
{
    for (std::vector<int>::iterator i = this->_path.begin(); i != this->_path.end(); i++) {
        if (*i == 1)
            this->set_x_ia(this->get_x_ia() - 1);
        if (*i == 2)
            this->set_y_ia(this->get_y_ia() - 1);
        if (*i == 3)
            this->set_x_ia(this->get_x_ia() + 1);
        if (*i == 4)
            this->set_y_ia(this->get_y_ia() + 1);
    }
    this->_path.clear();
    this->choice();
}

int Indie::IA::find_safe_path(int x, int y)
{
    if (this->get_map()[x][y] == 0)
        return 1;
    if (this->get_map()[x - 1][y] != 2)
        if (find_safe_path(x - 1, y))
            this->_path.push_back(1);
    if (this->get_map()[x][y - 1] != 2)
        if (find_safe_path(x, y))
            this->_path.push_back(2);
    if (this->get_map()[x + 1][y] != 2)
        if (find_safe_path(x + 1, y))
            this->_path.push_back(3);
    if (this->get_map()[x][y + 1] != 2)
        if (find_safe_path(x, y + 1))
            this->_path.push_back(4);
    return 0;
}

void Indie::IA::choice()
{
	short a = rand() % 4;
    
    if (a == 0) {
        this->drop_bomb();
    //voir pour le forcer à se déplacer quand il pose une bombe
    }
}

std::vector<std::string> Indie::IA::get_map()
{
    return this->map_ia.getMap();
}

int Indie::IA::get_x_ia()
{
    return this->pos_x_ia;
}

int Indie::IA::get_y_ia()
{
    return this->pos_y_ia;
}

void Indie::IA::set_x_ia(int x)
{
    this->pos_x_ia = x;
}

void Indie::IA::set_y_ia(int y)
{
    this->pos_y_ia = y;
}