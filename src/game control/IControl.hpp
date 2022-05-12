/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** IControl
*/

#pragma once

class IControl {
    public:
        virtual int getEvents(void);
        virtual int movement(int);
        virtual int dropBomb(void);
        virtual ~IControl();

    protected:
    private:
};
