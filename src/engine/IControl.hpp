/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** IControl
*/

#pragma once

class IControl {
public:
    virtual ~IControl() = default;
    virtual int getEvents(void) = 0;
    virtual int movement(int) = 0;
    virtual int dropBomb(void) = 0;

protected:
private:
};
