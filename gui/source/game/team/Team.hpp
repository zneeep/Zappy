/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Team
*/

#ifndef TEAM_HPP_
#define TEAM_HPP_

#include <string>
#include <vector>

namespace zappy
{
    class Team {
    public:
        Team(const std::string &name);
        Team(const std::string& name, int maxLevel);
        Team(const Team& other);
        ~Team() = default;

        std::string getName() const;
        int getMaxLevel() const;

    protected:
    private:
        std::string name;
        int maxLevel;
    };
}

#endif /* !TEAM_HPP_ */
