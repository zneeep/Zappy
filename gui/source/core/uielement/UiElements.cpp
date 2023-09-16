/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** UiElements.hpp
*/
#include "UiElements.hpp"

void zappy::GameUI::render(my::nullable<zappy::SFML> &renderer, int offset)
{
    // Title of UI
    renderer->drawTextCentered(__WINDOW_WIDTH__ - __WINDOW_SIDEBAR_WIDTH__ / 2, 35, "GAME", "arial2.ttf", 50, 42, 244, 155, 255);

    // Write UI Data
    // -- Team names --
    for (int i = 0; i < this->_gamedata.getTeams().size(); i++) {
        renderer->drawTextCentered(__WINDOW_WIDTH__ - __WINDOW_SIDEBAR_WIDTH__ / 2, 110 + (i * 40), this->_gamedata.getTeams()[i]->getName(), "arial2.ttf", 25, 255, 255, 255, 255/2);
    }
    // -- Player amount --
    int playerAmount = this->_gamedata.getPlayers().size();
    renderer->drawTextCentered(__WINDOW_WIDTH__ - __WINDOW_SIDEBAR_WIDTH__ / 2, 110 + (this->_gamedata.getTeams().size() * 40), "Players: " + std::to_string(playerAmount), "arial2.ttf", 25, 255, 255, 255, 255/2);
    // -- Map size --
    my::nullable<zappy::Map> map = this->_gamedata.getMap();
    renderer->drawTextCentered(__WINDOW_WIDTH__ - __WINDOW_SIDEBAR_WIDTH__ / 2, 110 + (this->_gamedata.getTeams().size() * 40) + 40, "Map size: " + std::to_string(map->getHeight()) + "x" + std::to_string(map->getWidth()), "arial2.ttf", 25, 255, 255, 255, 255/2);
    // -- Display ID's of alive players list below:
    std::vector<my::nullable<zappy::Player>> alivePlayers;
    for (auto &player : this->_gamedata.getPlayers()) {
        if (player->isPlayerAlive())
            alivePlayers.push_back(player);
    }
    for (int i = 0; i < alivePlayers.size(); i++) {
        renderer->drawTextCentered(__WINDOW_WIDTH__ - __WINDOW_SIDEBAR_WIDTH__ / 2, 110 + (this->_gamedata.getTeams().size() * 40) + 80 + (i * 40), "Player [" + std::to_string(alivePlayers[i]->getId()) + "]", "arial2.ttf", 25, 255, 255, 255, 255/2);
    }
}

void zappy::TeamUI::render(my::nullable<zappy::SFML> &renderer, int offset)
{
    // Title of UI
    renderer->drawTextCentered(__WINDOW_WIDTH__ - __WINDOW_SIDEBAR_WIDTH__ / 2, 35, "TEAM", "arial2.ttf", 50, 42, 244, 155, 255);
    std::vector<my::nullable<zappy::Player>> players = this->_game.getPlayersFromTeam(this->_team.getName());
    std::vector<my::nullable<zappy::Player>> alivePlayers;
    std::vector<my::nullable<zappy::Player>> deadPlayers;
    for (auto &player : players) {
        if (player->isPlayerAlive())
            alivePlayers.push_back(player);
        else
            deadPlayers.push_back(player);
    }
    // Write UI Data
    // -- Player Alive --
    renderer->drawTextCentered(__WINDOW_WIDTH__ - __WINDOW_SIDEBAR_WIDTH__ / 2, 110, "Alive: " + std::to_string(alivePlayers.size()), "arial2.ttf", 25, 255, 255, 255, 255/2);
    // -- Player Dead --
    renderer->drawTextCentered(__WINDOW_WIDTH__ - __WINDOW_SIDEBAR_WIDTH__ / 2, 110 + 40, "Dead: " + std::to_string(deadPlayers.size()), "arial2.ttf", 25, 255, 255, 255, 255/2);
    // -- Max level --
    renderer->drawTextCentered(__WINDOW_WIDTH__ - __WINDOW_SIDEBAR_WIDTH__ / 2, 110 + 80, "Max level: " + std::to_string(this->_team.getMaxLevel()), "arial2.ttf", 25, 255, 255, 255, 255/2);
}

void zappy::PlayerUI::render(my::nullable<zappy::SFML> &renderer, int offset) {
    // Title of UI
    renderer->drawTextCentered(__WINDOW_WIDTH__ - __WINDOW_SIDEBAR_WIDTH__ / 2, 500 + offset, "PLAYER", "arial2.ttf", 25,
                               42, 244, 155, 255);

    // Write UI Data
    int yPosition = 540 + offset; // Starting y-position with an offset of 50

    // -- Player's Team & level --
    renderer->drawTextCentered(__WINDOW_WIDTH__ - __WINDOW_SIDEBAR_WIDTH__ / 2, yPosition,
                               this->_player.getTeam().getName() + " - (LVL. " + std::to_string(this->_player.getLevel()) + ")", "arial2.ttf", 15, 255, 255, 255, 255 / 2);
    yPosition += 30; // Increase y-position for the next element

// -- Player's resources --
    std::string resourcesString = std::to_string(this->_player.getResources().food) + "/" +
                                  std::to_string(this->_player.getResources().linemate) + "/" +
                                  std::to_string(this->_player.getResources().deraumere) + "/" +
                                  std::to_string(this->_player.getResources().sibur) + "/" +
                                  std::to_string(this->_player.getResources().mendiane) + "/" +
                                  std::to_string(this->_player.getResources().phiras) + "/" +
                                  std::to_string(this->_player.getResources().thystame);

    renderer->drawTextCentered(__WINDOW_WIDTH__ - __WINDOW_SIDEBAR_WIDTH__ / 2, yPosition, resourcesString,
                               "arial2.ttf", 15, 255, 255, 255, 255 / 2);

    std::string orientation = this->_player.getStringOrientation();
    renderer->drawTextCentered(__WINDOW_WIDTH__ - __WINDOW_SIDEBAR_WIDTH__ / 2, yPosition + 30, orientation,
                               "arial2.ttf", 15, 255, 255, 255, 255 / 2);

}

void zappy::TileUI::render(my::nullable<zappy::SFML> &renderer, int offset)
{
    // Title of UI
    renderer->drawTextCentered(__WINDOW_WIDTH__ - __WINDOW_SIDEBAR_WIDTH__ / 2, 35, "TILE", "arial2.ttf", 50, 42, 244, 155, 255);

    // Write UI Data
    // -- Tile's Positions --
    renderer->drawTextCentered(__WINDOW_WIDTH__ - __WINDOW_SIDEBAR_WIDTH__ / 2, 110, "Position: " + std::to_string(this->_tile.getX()) + "x" + std::to_string(this->_tile.getY()), "arial2.ttf", 25, 255, 255, 255, 255/2);
    // -- Tile's ressources --
    renderer->drawTextCentered(__WINDOW_WIDTH__ - __WINDOW_SIDEBAR_WIDTH__ / 2, 110 + 40, "Ressources:", "arial2.ttf", 25, 255, 255, 255, 255/2);
    // - Food -
    renderer->drawTextCentered(__WINDOW_WIDTH__ - __WINDOW_SIDEBAR_WIDTH__ / 2, 110 + 80, "Food: " + std::to_string(this->_tile.getRessources().food), "arial2.ttf", 25, 235, 107, 52, 255/2);
    // - Linemate -
    renderer->drawTextCentered(__WINDOW_WIDTH__ - __WINDOW_SIDEBAR_WIDTH__ / 2, 110 + 120, "Linemate: " + std::to_string(this->_tile.getRessources().linemate), "arial2.ttf", 25, 52, 186, 235, 255/2);
    // - Deraumere -
    renderer->drawTextCentered(__WINDOW_WIDTH__ - __WINDOW_SIDEBAR_WIDTH__ / 2, 110 + 160, "Deraumere: " + std::to_string(this->_tile.getRessources().deraumere), "arial2.ttf", 25, 41, 227, 218, 255/2);
    // - Sibur -
    renderer->drawTextCentered(__WINDOW_WIDTH__ - __WINDOW_SIDEBAR_WIDTH__ / 2, 110 + 200, "Sibur: " + std::to_string(this->_tile.getRessources().sibur), "arial2.ttf", 25, 207, 69, 245, 255/2);
    // - Mendiane -
    renderer->drawTextCentered(__WINDOW_WIDTH__ - __WINDOW_SIDEBAR_WIDTH__ / 2, 110 + 240, "Mendiane: " + std::to_string(this->_tile.getRessources().mendiane), "arial2.ttf", 25, 237, 158, 78, 255/2);
    // - Phiras -
    renderer->drawTextCentered(__WINDOW_WIDTH__ - __WINDOW_SIDEBAR_WIDTH__ / 2, 110 + 280, "Phiras: " + std::to_string(this->_tile.getRessources().phiras), "arial2.ttf", 25, 240, 89, 89, 255/2);
    // - Thystame -
    renderer->drawTextCentered(__WINDOW_WIDTH__ - __WINDOW_SIDEBAR_WIDTH__ / 2, 110 + 320, "Thystame: " + std::to_string(this->_tile.getRessources().thystame), "arial2.ttf", 25, 237, 107, 155, 255/2);
}
