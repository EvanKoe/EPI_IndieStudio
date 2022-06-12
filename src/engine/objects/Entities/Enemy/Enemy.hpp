/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Enemy
*/

#pragma once

#include "../Entity.hpp"

class Enemy: public Entity {
    public:
        Enemy(float x = 0, float y = 0, float z = 0) :
            Entity(x, y, z, 1, Indie::ENEMY)
        {};
        ~Enemy();
        int movement(int);
        int dropBomb(void);

    protected:
    private:
        void death(void); // The enemy is dead
};
