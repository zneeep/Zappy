/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Complex3D
*/

#ifndef COMPLEX3D_HPP_
#define COMPLEX3D_HPP_

#include <ostream>
#include <cmath>
#include <memory>

namespace math
{
    class Complex3D {
        public:
            Complex3D();
            Complex3D(int , int , int = 0);
            Complex3D(float , float , float = 0.0f);
            Complex3D(double , double , double = 0.0);
            Complex3D(const math::Complex3D &);
            ~Complex3D() = default;

            math::Complex3D &operator=(const math::Complex3D &);

            bool operator==(const math::Complex3D &) const;
            bool operator!=(const math::Complex3D &) const;

            math::Complex3D operator+(const math::Complex3D &) const;
            math::Complex3D operator-(const math::Complex3D &) const;
            math::Complex3D operator+(const double &) const;
            math::Complex3D operator-(const double &) const;
            math::Complex3D operator*(const double &) const;
            math::Complex3D operator/(const double &) const;

            math::Complex3D &operator+=(const math::Complex3D &);
            math::Complex3D &operator-=(const math::Complex3D &);
            math::Complex3D &operator+=(const double &);
            math::Complex3D &operator-=(const double &);
            math::Complex3D &operator*=(const double &);
            math::Complex3D &operator/=(const double &);

            math::Complex3D operator-() const;

            double dot(const math::Complex3D &) const;
            double lenghtSquared() const;
            double length() const;

            math::Complex3D &normalize();

            static std::shared_ptr<math::Complex3D> makeNullable(const math::Complex3D &);
            static math::Complex3D cross(const math::Complex3D &, const math::Complex3D &);
            static math::Complex3D rotate(const math::Complex3D &, const math::Complex3D &, const math::Complex3D &, const double &);

            double X;
            double Y;
            double Z;

        protected:
        private:
    };
    std::ostream &operator<<(std::ostream &, const math::Complex3D &);
}

#endif /* !COMPLEX3D_HPP_ */
