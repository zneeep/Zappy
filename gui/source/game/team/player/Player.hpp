/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <vector>
#include "../../map/Ressources.hpp"
#include "../Team.hpp"

namespace zappy
{
    enum ORIENTATION {
        NORTH = 1,
        EAST = 2,
        SOUTH = 3,
        WEST = 4,
    };

    class Player {
    public:
        Player(const Team& team, int id, int level, const Ressources &ressources = Ressources());
        ~Player() = default;

        Team getTeam() const;

        int getLevel() const;
        void setLevel(int level);

        bool isPlayerAlive() const;
        void kill();

        Ressources getResources() const;
        void setResources(const Ressources &resources);

        int getId() const;

        int getX() const;
        void setX(int x);
        int getY() const;
        void setY(int y);

        ORIENTATION getOrientation() const { return this->orientation; };
        void setOrientation(int orientation);

        std::string getStringOrientation() const;

    protected:
    private:
        Team team;
        int level;
        Ressources resources;
        bool isAlive;
        int id;
        int x = 0;
        int y = 0;
        ORIENTATION orientation = ORIENTATION::NORTH;
    };
}

#endif /* !PLAYER_HPP_ */