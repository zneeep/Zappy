/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Tile
*/

#include "Tile.hpp"

zappy::Tile::Tile()
{
    this->ressources = zappy::Ressources();
}

zappy::Tile::Tile(const zappy::Ressources &__ressources, int pos_x, int pos_y)
{
    this->ressources = __ressources;
    this->pos_x = pos_x;
    this->pos_y = pos_y;
}

zappy::Tile::Tile(const zappy::Tile &__tile)
{
    this->ressources = __tile.ressources;
    this->pos_x = __tile.pos_x;
    this->pos_y = __tile.pos_y;
}

zappy::Ressources zappy::Tile::getRessources() const
{
    return (this->ressources);
}

void zappy::Tile::setRessources(const zappy::Ressources &__ressources)
{
    this->ressources = __ressources;
}
