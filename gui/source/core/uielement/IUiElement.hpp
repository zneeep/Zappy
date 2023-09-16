/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** IUiElement.hpp
*/

#ifndef INVENTORY_HPP_
#define INVENTORY_HPP_

#include <iostream>
#include <vector>
#include "../Core.hpp"

namespace zappy
{
    class IUiElement {
    public:
        virtual void render(my::nullable<zappy::SFML> &renderer, int offset = 0) = 0;
    };
}

#endif /* !INVENTORY_HPP_ */