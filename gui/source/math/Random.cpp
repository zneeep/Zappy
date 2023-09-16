/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Random
*/

#include <random>

#include "Random.hpp"

double math::Random::generateRandom(const double &min, const double &max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(min, max);
    double value = dis(gen);
    return (value);
}
