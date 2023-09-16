/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Broadcast.hpp
*/

#ifndef BROADCAST_HPP_
#define BROADCAST_HPP_

#include <memory>
#include <iostream>
#include <vector>

namespace zappy
{
    class Broadcast {
    public:
        Broadcast(int x, int y, int playerId, const std::string message);
        Broadcast(const Broadcast &other);
        ~Broadcast() = default;

        const std::string &formatString() const;

    protected:
    private:
        int _x;
        int _y;
        int _playerId;
        std::string _message;
    };
}

#endif /* !BROADCAST_HPP_ */
