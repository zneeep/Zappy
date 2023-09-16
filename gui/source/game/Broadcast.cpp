/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Broadcast.cpp
*/

#include "Broadcast.hpp"

zappy::Broadcast::Broadcast(int x, int y, int playerId, const std::string message)
        : _x(x), _y(y), _playerId(playerId), _message(message) {}

zappy::Broadcast::Broadcast(const zappy::Broadcast &other)
        : _x(other._x), _y(other._y), _playerId(other._playerId), _message(other._message) {}


const std::string &zappy::Broadcast::formatString() const
{
    // return a string of the form "(id)[x][y] message"
    static std::string str; // Static variable to hold the string

    str = "(" + std::to_string(_playerId) + ")[" + std::to_string(_x) + "][" + std::to_string(_y) + "] " + _message;

    return str;
}
