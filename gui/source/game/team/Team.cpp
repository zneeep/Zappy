#include "Team.hpp"

namespace zappy
{
    Team::Team(const std::string& name) : name(name), maxLevel(0) {}

    Team::Team(const std::string& name, int maxLevel)
            : name(name), maxLevel(maxLevel) {}

    Team::Team(const Team& other)
            : name(other.name), maxLevel(other.maxLevel) {}

    std::string Team::getName() const
    {
        return name;
    }

    int Team::getMaxLevel() const
    {
        return maxLevel;
    }
}
