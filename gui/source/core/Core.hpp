/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include "../renderer/SFML.hpp"
#include "include.hpp"
#include "parser/Parser.hpp"
#include "parser/Error.hpp"
#include "socket/Socket.hpp"
#include "../game/map/Map.hpp"
#include "../game/Game.hpp"
#include "uielement/UiElements.hpp"
#include "../tools/nullable.hpp"
#include "../routes/SpriteRouteConstants.hpp"
#include "camera/Camera.hpp"

#include <memory>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <iomanip>

namespace zappy
{
    class Core {
        public:
            Core(int argc, char **argv);
            ~Core() = default;

            void run();

        protected:
        private:
            my::nullable<zappy::SFML> renderer;
            my::nullable<zappy::Socket> socket;
            my::nullable<zappy::Game> game;
            my::nullable<zappy::Map> map;
            my::nullable<zappy::Camera> camera;
            my::nullable<std::pair<int, int>> tile = nullptr;
            my::nullable<int> playerId = nullptr;
            int timeUnit = 100;
            int previousTimeUnit = 100;

            void initGame();

            /**
            ** @brief Move the camera according to the events
            ** @param __events events to move the camera
            */
            void moveCamera(const std::vector<zappy::Events> &__events);

            /**
             * @brief draw the game
             * @param __tile_size_x width of a tile
             * @param __tile_size_y height of a tile
             */
            void drawGame(int __tile_size_x, int __tile_size_y);

            /**
             ** @brief draw the sidebar
            */
            void drawSidebar();

            void drawBroadcasts();

            my::nullable<std::pair<int, int>> getTileFromClick(std::pair<int, int> __click, int __tile_size_x, int __tile_size_y);

    };
}

#endif /* !CORE_HPP_ */
