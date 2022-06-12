/*
** EPITECH PROJECT, 2022
** EPI_IndieStudio [WSL: Ubuntu]
** File description:
** SpeedUp
*/

#ifndef SPEEDUP_HPP_
#define SPEEDUP_HPP_

#include "PowerUp.hpp"

class SpeedUp : public PowerUp {
public:
    SpeedUp();

    void setAttribute(Indie::PowerUpAttribute attribute) override;

protected:
private:
};

#endif /* !SPEEDUP_HPP_ */
