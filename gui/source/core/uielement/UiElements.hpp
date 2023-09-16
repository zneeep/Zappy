/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** UiElements.hpp
*/

#ifndef UIELEMENTS_HPP_
#define UIELEMENTS_HPP_

#include <iostream>
#include <vector>
#include "IUiElement.hpp"
#include "../../game/team/player/Player.hpp"
#include "../../game/map/Tile.hpp"

namespace zappy
{
    // -- Game UI --
    class GameUI : public IUiElement {
    public:
        explicit GameUI(const Game &game) : _gamedata(game) {};
        void render(my::nullable<zappy::SFML> &renderer, int offset = 0) override;
    private:
        Game _gamedata;
    };

    // -- Team UI --
    class TeamUI : public IUiElement {
    public:
        TeamUI(const Team &team, const Game &game) : _team(team), _game(game) {};
        void render(my::nullable<zappy::SFML> &renderer, int offset = 0) override;
    private:
        Team _team;
        Game _game;
    };

    // -- Player UI --
    class PlayerUI : public IUiElement {
    public:
        explicit PlayerUI(const Player &player) : _player(player) {};
        void render(my::nullable<zappy::SFML> &renderer, int offset = 0) override;
    private:
        Player _player;
    };

    // -- Tile UI --
    class TileUI : public IUiElement {
    public:
        explicit TileUI(const Tile &tile) : _tile(tile) {};
        void render(my::nullable<zappy::SFML> &renderer, int offset = 0) override;
    private:
        Tile _tile;
    };
}

#endif /* !UIELEMENTS_HPP_ */