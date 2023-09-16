/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "map/Map.hpp"
#include "team/Team.hpp"
#include "team/player/Player.hpp"
#include "../core/parser/Parser.hpp"
#include "../tools/nullable.hpp"
#include "Broadcast.hpp"

#include <memory>
#include <vector>

namespace zappy
{
    class Game {
        public:
            Game(const std::shared_ptr<zappy::Map> &);
            ~Game() = default;

            void linkTeams(const std::vector<my::nullable<zappy::Team>> &);

            my::nullable<zappy::Map> getMap() const;
            std::vector<my::nullable<zappy::Team>> getTeams() const;
            my::nullable<zappy::Team> getTeam(const std::string &) const;

            std::vector<my::nullable<zappy::Player>> getPlayers() const;
            std::vector<my::nullable<zappy::Player>> getPlayersFromTeam(const std::string &teamName) const;
            my::nullable<zappy::Player> getPlayer(int id) const;

           std::vector<zappy::Broadcast> getLastThreeBroadcasts() const;

            void commandsHandler(std::vector<my::nullable<zappy::Data>> &commands);

            void btcCommandHandler(my::nullable<zappy::Data> &data);
            void pnwCommandHandler(my::nullable<zappy::Data> &data);
            void ppoCommandHandler(my::nullable<zappy::Data> &data);
            void plvCommandHandler(my::nullable<zappy::Data> &data);
            void pinCommandHandler(my::nullable<zappy::Data> &data);
            void pdiCommandHandler(my::nullable<zappy::Data> &data);
            void pbcCommandHandler(my::nullable<zappy::Data> &data);

        protected:
        private:
            my::nullable<zappy::Map> map;
            std::vector<my::nullable<zappy::Team>> teams;
            std::vector<my::nullable<zappy::Player>> players;
            std::vector<zappy::Broadcast> broadcasts;
    };
}

#endif /* !GAME_HPP_ */
