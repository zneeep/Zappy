/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Ressources
*/

#ifndef RESSOURCES_HPP_
#define RESSOURCES_HPP_

#include "../../math/math.hpp"
#include "../../math/Random.hpp"

#include <ostream>

namespace zappy
{
    struct Ressources {
        Ressources() = default;
        Ressources(int food, int linemate, int deraumere, int sibur, int mendiane, int phiras, int thystame);
        Ressources(const zappy::Ressources &);

        int food;
        int linemate;
        int deraumere;
        int sibur;
        int mendiane;
        int phiras;
        int thystame;

        void operator=(const Ressources &);
    };

    std::ostream &operator<<(std::ostream &, const zappy::Ressources &);

    enum RessourceName {
        Linemate = 0,
        Deraumere = 1,
        Sibur = 2,
        Mendiane = 3,
        Phiras = 4,
        Thystame = 5,
    };
}

#endif /* !RESSOURCES_HPP_ */
