/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** events
*/

#ifndef EVENTS_HPP_
#define EVENTS_HPP_

#include <ostream>

namespace zappy
{
    enum Events {
        NONE,
        MOVE_UP,
        MOVE_DOWN,
        MOVE_LEFT,
        MOVE_RIGHT,
        ZOOM_IN,
        ZOOM_OUT,
        TIME_UP,
        TIME_DOWN,
    };

    std::ostream &operator<<(std::ostream &, const zappy::Events &);
}

#endif /* !EVENTS_HPP_ */
