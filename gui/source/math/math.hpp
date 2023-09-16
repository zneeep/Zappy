/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** math
*/

#ifndef MATH_HPP_
#define MATH_HPP_

#include "Complex3D.hpp"
#include "Random.hpp"

/**
** @brief the pi value with 25 decimal places
*/
#define __PI__ 3.1415926535897932384626434

#define __RANDOM__ math::Random::generateRandom


typedef math::Complex3D point3d;
typedef math::Complex3D vector3d;
typedef math::Complex3D complex3d;

typedef std::shared_ptr<math::Complex3D> point3d_n;
typedef std::shared_ptr<math::Complex3D> vector3d_n;
typedef std::shared_ptr<math::Complex3D> complex3d_n;

#endif /* !MATH_HPP_ */
