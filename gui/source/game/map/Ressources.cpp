/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Ressources
*/

#include "Ressources.hpp"

zappy::Ressources::Ressources(int food, int linemate, int deraumere, int sibur, int mendiane, int phiras, int thystame)
{
    this->food = food;
    this->linemate = linemate;
    this->deraumere = deraumere;
    this->sibur = sibur;
    this->mendiane = mendiane;
    this->phiras = phiras;
    this->thystame = thystame;
}

zappy::Ressources::Ressources(const zappy::Ressources &ressources)
{
    this->food = ressources.food;
    this->linemate = ressources.linemate;
    this->deraumere = ressources.deraumere;
    this->sibur = ressources.sibur;
    this->mendiane = ressources.mendiane;
    this->phiras = ressources.phiras;
    this->thystame = ressources.thystame;
}

void zappy::Ressources::operator=(const zappy::Ressources &ressources)
{
    this->food = ressources.food;
    this->linemate = ressources.linemate;
    this->deraumere = ressources.deraumere;
    this->sibur = ressources.sibur;
    this->mendiane = ressources.mendiane;
    this->phiras = ressources.phiras;
    this->thystame = ressources.thystame;
}

std::ostream &zappy::operator<<(std::ostream &os, const zappy::Ressources &ressources)
{
    os << "food: " << ressources.food
       << " linemate: " << ressources.linemate
       << " deraumere: " << ressources.deraumere
       << " sibur: " << ressources.sibur
       << " mendiane: " << ressources.mendiane
       << " phiras: " << ressources.phiras
       << " thystame: " << ressources.thystame;
    return (os);
}
