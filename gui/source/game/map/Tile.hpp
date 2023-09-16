/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Tile
*/

#ifndef TILE_HPP_
#define TILE_HPP_

#include "Ressources.hpp"
#include "../../math/Random.hpp"
#include "graphics.hpp"

#include <vector>

namespace zappy
{
    class Tile {
        public:
            Tile();
            Tile(const zappy::Ressources &, int pos_x, int pos_y);
            Tile(const Tile &);
            ~Tile() = default;

            zappy::Ressources getRessources() const;
            void setRessources(const zappy::Ressources &);
            void setX(int x) { pos_x = x; };
            void setY(int y) { pos_y = y; };

            int getX() const { return pos_x; };
            int getY() const { return pos_y; };

        protected:
        private:
            zappy::Ressources ressources;
            int pos_x;
            int pos_y;
    };
}

#endif /* !TILE_HPP_ */
