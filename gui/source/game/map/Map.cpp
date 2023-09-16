/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Map
*/

#include "Map.hpp"

zappy::Map::Map(int width, int height)
{
    this->width = width;
    this->height = height;

    this->tiles.resize(height);
    for (std::size_t i = 0; i < height; i++)
        this->tiles[i].resize(width);
}

int zappy::Map::getWidth() const
{
    return (this->width);
}

int zappy::Map::getHeight() const
{
    return (this->height);
}

void zappy::Map::setTile(int x, int y, const zappy::Ressources &ressources)
{
    this->tiles[y][x].setRessources(ressources);
    this->tiles[y][x].setX(x);
    this->tiles[y][x].setY(y);
}

zappy::Tile zappy::Map::getTile(int x, int y) const
{
    return (this->tiles[y][x]);
}

std::ostream &zappy::operator<<(std::ostream &os, const zappy::Map &map)
{
    int width = map.getWidth();
    int height = map.getHeight();

    os << "width: " << width << " height: " << height << std::endl;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            os << "x: " << j << " y: " << i << " " << map.getTile(j, i).getRessources() << std::endl;
    return (os);
}
