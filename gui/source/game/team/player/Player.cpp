/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Player
*/

#include "Player.hpp"

namespace zappy
{
    Player::Player(const Team& team, int id, int level, const Ressources &ressources)
        : team(team), id(id), level(level), resources(ressources), isAlive(true) {}

    Team Player::getTeam() const
    {
        return (this->team);
    }

    int Player::getLevel() const
    {
        return (this->level);
    }

    void Player::setLevel(int level)
    {
        this->level = level;
    }

    bool Player::isPlayerAlive() const
    {
        return (this->isAlive);
    }

    void Player::kill()
    {
        this->isAlive = false;
    }

    Ressources Player::getResources() const
    {
        return (this->resources);
    }

    void Player::setResources(const Ressources &ressources)
    {
        this->resources = ressources;
    }

    int Player::getId() const
    {
        return (this->id);
    }

    int Player::getX() const
    {
        return (this->x);
    }

    void Player::setX(int x)
    {
        if (this->isAlive)
            this->x = x;
    }

    int Player::getY() const
    {
        return (this->y);
    }

    void Player::setY(int y)
    {
        if (this->isAlive)
            this->y = y;
    }

    void Player::setOrientation(int orientation)
    {
        if (orientation == 1)
            this->orientation = ORIENTATION::NORTH;
        if (orientation == 2)
            this->orientation = ORIENTATION::EAST;
        if (orientation == 3)
            this->orientation = ORIENTATION::SOUTH;
        if (orientation == 4)
            this->orientation = ORIENTATION::WEST;
    }

    std::string Player::getStringOrientation() const
    {
        if (this->orientation == ORIENTATION::NORTH)
            return ("North");
        if (this->orientation == ORIENTATION::EAST)
            return ("East");
        if (this->orientation == ORIENTATION::SOUTH)
            return ("South");
        if (this->orientation == ORIENTATION::WEST)
            return ("West");
        return ("NORTH");
    }
}
