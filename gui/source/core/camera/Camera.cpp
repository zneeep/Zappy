/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Camera
*/

#include "Camera.hpp"

zappy::Camera::Camera()
{
    this->_x = 0.0;
    this->_y = 0.0;
    this->_zoom = 1.0;
}

double zappy::Camera::getX() const
{
    return (this->_x);
}

double zappy::Camera::getY() const
{
    return (this->_y);
}

void zappy::Camera::setX(double __x)
{
    this->_x = __x;
}

void zappy::Camera::setY(double __y)
{
    this->_y = __y;
}

double zappy::Camera::getZoom() const
{
    return (this->_zoom);
}

void zappy::Camera::setZoom(double __zoom)
{
    this->_zoom = __zoom;
    if (this->_zoom < __MIN_ZOOM_VALUE__)
        this->_zoom = __MIN_ZOOM_VALUE__;
}
