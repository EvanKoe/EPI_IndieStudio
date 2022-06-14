/*
** EPITECH PROJECT, 2022
** EPI_IndieStudio
** File description:
** ia
*/

#ifndef IA_HPP_
#define IA_HPP_

#include "../Entity.hpp"
#include "../../../map/Map.hpp"
#include <iostream>
#include <vector>

#define WIDTH_MAP 15 //mettre la bonne taille de map
#define HEIGHT_MAP 15 //mettre la bonne taille de map

namespace Indie {
    class IA : public Entity {
        private:
            std::string _skinFilepath;
            int pos_x_ia;
            int pos_y_ia;
            std::vector<int> _path;
            std::vector<std::vector<int> > _map;
            float _timer_respawn;

    public:
            IA(float x = 0, float y = 0, float z = 0, int health = 2) : Entity(x, y, z, 2, Indie::ENEMY) {};
            virtual void Create();
            virtual void Update();
            void IAScript(int x, int y, const std::string &);
            void move_ia_safe();
            void set_map();
            int find_safe_path(int, int);
            int get_x_ia();
            int get_y_ia();
            void set_x_ia(int);
            void set_y_ia(int);
            void choice();
            void drop_bomb();
            Map map_ia;
            std::vector<std::string> get_map();
    };
}

#endif /* !IA_HPP_ */
