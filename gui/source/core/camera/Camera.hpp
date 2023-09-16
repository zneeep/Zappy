/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "../include.hpp"
#include "cameraLimits.hpp"

namespace zappy
{
    class Camera {
        public:
            Camera();
            ~Camera() = default;

            /* position geter and seter */
            double getX() const;
            double getY() const;
            void setX(double __x);
            void setY(double __y);

            /* zoom geter and seter */
            double getZoom() const;
            void setZoom(double __zoom);

        protected:
        private:
            double _x;
            double _y;
            double _zoom;
    };
}

#endif /* !CAMERA_HPP_ */
