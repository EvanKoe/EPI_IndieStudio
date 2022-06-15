/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** GameObject
*/

#pragma once

#include <iostream>
#include <list>
#include <map>
#include <vector>
#include "Globals.hpp"
#include "Sprite.hpp"

namespace Indie {
    class GameObject {
    public:
        GameObject(
            float x = 0.0f,
            float y = 0.0f,
            float z = 0.0f,
            game_object_id_e id = NONE
        );
        void draw(void) { return _sp->draw(); }
        Sprite *getSprite(void) { return _sp; }
        bool getIs3d(void) { return _sp->getIs3D(); }
        float getX(void) const;
        float getY(void) const;
        float getZ(void) const;
        pos_t getPosition(void) const;
        void setX(float x);
        void setY(float y);
        void setZ(float z);
        GameObjectsIds getId() const;
        ~GameObject() { delete(_sp); }

    protected:
        Sprite *_sp;
        float _x;
        float _y;
        float _z;
        GameObjectsIds _id;
    };
}

