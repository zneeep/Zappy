/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** events
*/

#include "events.hpp"

std::ostream &zappy::operator<<(std::ostream &os, const zappy::Events &event)
{
    switch (event)
    {
        case zappy::Events::NONE:
            os << "NONE";
            break;
        case zappy::Events::MOVE_UP:
            os << "MOVE_UP";
            break;
        case zappy::Events::MOVE_DOWN:
            os << "MOVE_DOWN";
            break;
        case zappy::Events::MOVE_LEFT:
            os << "MOVE_LEFT";
            break;
        case zappy::Events::MOVE_RIGHT:
            os << "MOVE_RIGHT";
            break;
        case zappy::Events::ZOOM_IN:
            os << "ZOOM_IN";
            break;
        case zappy::Events::ZOOM_OUT:
            os << "ZOOM_OUT";
            break;
        default:
            os << "UNKNOWN";
            break;
    }
    return (os);
}