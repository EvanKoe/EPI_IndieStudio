/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Text
*/

#pragma once

#include "../IGraphic.hpp"

namespace Indie {
    class Button : public IGraphic {
        public:
            Button(std::string);
            void setText(std::string);
            std::string getText(void);
            void setDisabled(bool);
            bool isDisabled(void);
            ~Button();
        protected:
        private:
            std::string _name;
            std::string _text;
    };
};