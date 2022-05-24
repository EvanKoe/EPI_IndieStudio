/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Enemy
*/

#pragma once

#include "../IControl.hpp"

class Enemy: public IControl {
    enum Difficulty {
        EASY,
        MEDIUM,
        HARD
    };
    public:
        Enemy();
        int getEvents(void) override;
        int movement(int) override;
        int dropBomb(void) override;
        void setPosition(void); // Set the position of the enemy at the beginning of the game
        void death(void); // The enemy is dead
        void setDifficulty(Difficulty d); // Set the difficulty of the game
        void getPosition(void); // Get the position of the enemy
        ~Enemy();

    protected:
    private:
};
