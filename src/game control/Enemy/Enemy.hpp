/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Enemy
*/

#pragma once

#include "../IControl.hpp"

class Enemy: public IControl {
    public:
        Enemy();
        int getEvents(void) override;
        int movement(int) override;
        int dropBomb(void) override;
        ~Enemy();

    protected:
    private:
};
