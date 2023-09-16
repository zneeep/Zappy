/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include "Ressources.hpp"
#include "Tile.hpp"

#include <vector>
#include <iostream>

namespace zappy
{
    class Map {
        public:
            Map(int width, int height);
            ~Map() = default;

            int getWidth() const;
            int getHeight() const;

            void setTile(int x, int y, const zappy::Ressources &);
            zappy::Tile getTile(int x, int y) const;

        protected:
        private:
            int width;
            int height;
            std::vector<std::vector<zappy::Tile>> tiles;
    };
    std::ostream &operator<<(std::ostream &, const zappy::Map &);
}

#endif /* !MAP_HPP_ */
