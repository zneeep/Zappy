/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Complex3D
*/

#include "Complex3D.hpp"

#include "Complex3D.hpp"

math::Complex3D::Complex3D()
{
    this->X = 0.0;
    this->Y = 0.0;
    this->Z = 0.0;
}

math::Complex3D::Complex3D(int x, int y, int z)
{
    this->X = static_cast<double>(x);
    this->Y = static_cast<double>(y);
    this->Z = static_cast<double>(z);
}

math::Complex3D::Complex3D(float x, float y, float z)
{
    this->X = static_cast<double>(x);
    this->Y = static_cast<double>(y);
    this->Z = static_cast<double>(z);
}

math::Complex3D::Complex3D(double x, double y, double z)
{
    this->X = x;
    this->Y = y;
    this->Z = z;
}

math::Complex3D::Complex3D(const math::Complex3D &complex)
{
    *this = complex;
}

math::Complex3D &math::Complex3D::operator=(const math::Complex3D &complex)
{
    this->X = complex.X;
    this->Y = complex.Y;
    this->Z = complex.Z;
    return (*this);
}

bool math::Complex3D::operator==(const math::Complex3D &complex) const
{
    return ((this->X == complex.X) && (this->Y == complex.Y) && (this->Z == complex.Z));
}

bool math::Complex3D::operator!=(const math::Complex3D &complex) const
{
    return (!(*this == complex));
}

math::Complex3D math::Complex3D::operator+(const math::Complex3D &complex) const
{
    return (math::Complex3D(this->X + complex.X, this->Y + complex.Y, this->Z + complex.Z));
}

math::Complex3D math::Complex3D::operator-(const math::Complex3D &complex) const
{
    return (math::Complex3D(this->X - complex.X, this->Y - complex.Y, this->Z - complex.Z));
}

math::Complex3D math::Complex3D::operator+(const double &value) const
{
    return (math::Complex3D(this->X + value, this->Y + value, this->Z + value));
}

math::Complex3D math::Complex3D::operator-(const double &value) const
{
    return (math::Complex3D(this->X - value, this->Y - value, this->Z - value));
}

math::Complex3D math::Complex3D::operator*(const double &value) const
{
    return (math::Complex3D(this->X * value, this->Y * value, this->Z * value));
}

math::Complex3D math::Complex3D::operator/(const double &value) const
{
    if (value == 0.0)
        return (*this);
    return (math::Complex3D(this->X * value, this->Y * value, this->Z * value));
}

math::Complex3D &math::Complex3D::operator+=(const math::Complex3D &complex)
{
    *this = *this + complex;
    return (*this);
}

math::Complex3D &math::Complex3D::operator-=(const math::Complex3D &complex)
{
    *this = *this - complex;
    return (*this);
}

math::Complex3D &math::Complex3D::operator+=(const double &value)
{
    *this = *this + value;
    return (*this);
}

math::Complex3D &math::Complex3D::operator-=(const double &value)
{
    *this = *this - value;
    return (*this);
}

math::Complex3D &math::Complex3D::operator*=(const double &value)
{
    *this = *this * value;
    return (*this);
}

math::Complex3D &math::Complex3D::operator/=(const double &value)
{
    *this = *this / value;
    return (*this);
}

math::Complex3D math::Complex3D::operator-() const
{
    return (math::Complex3D(-this->X, -this->Y, -this->Z));
}

double math::Complex3D::dot(const math::Complex3D &complex) const
{
    return (this->X * complex.X + this->Y * complex.Y + this->Z * complex.Z);
}

double math::Complex3D::lenghtSquared() const
{
    return (this->X * this->X + this->Y * this->Y + this->Z * this->Z);
}

double math::Complex3D::length() const
{
    return (std::sqrt(lenghtSquared()));
}

math::Complex3D &math::Complex3D::normalize()
{
    double length = this->length();
    this->X /= length;
    this->Y /= length;
    this->Z /= length;
    return (*this);
}

std::shared_ptr<math::Complex3D> math::Complex3D::makeNullable(const math::Complex3D &complex)
{
    return (std::make_shared<math::Complex3D>(complex));
}

math::Complex3D math::Complex3D::rotate(const math::Complex3D &position, const math::Complex3D &origin, const math::Complex3D &normal, const double &angle)
{
    math::Complex3D t = position - origin;
    math::Complex3D p = math::Complex3D::cross(t, normal);

    double theta = angle;
    double cos_theta = cos(theta);
    double sin_theta = sin(theta);

    math::Complex3D r = t * cos_theta + p * sin_theta;
    math::Complex3D rotated_vector = origin + r;
    return (rotated_vector);
}

math::Complex3D math::Complex3D::cross(const math::Complex3D &vector_a, const math::Complex3D &vector_b)
{
    double cross_x = vector_a.Y * vector_b.Z - vector_a.Z * vector_b.Y;
    double cross_y = vector_a.Z * vector_b.X - vector_a.X * vector_b.Z;
    double cross_z = vector_a.X * vector_b.Y - vector_a.Y * vector_b.X;

    return (math::Complex3D(cross_x, cross_y, cross_z));
}

std::ostream &math::operator<<(std::ostream &os, const math::Complex3D &complex)
{
    os << "(" << complex.X << ", " << complex.Y << ", " << complex.Z << ")";
    return (os);
}

