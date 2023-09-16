/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Game
*/

#include "Game.hpp"

zappy::Game::Game(const std::shared_ptr<zappy::Map> &map)
{
    this->map = map;
}

void zappy::Game::linkTeams(const std::vector<my::nullable<zappy::Team>> &teams)
{
    this->teams = teams;
}

my::nullable<zappy::Map> zappy::Game::getMap() const
{
    return (this->map);
}

std::vector<my::nullable<zappy::Team>> zappy::Game::getTeams() const
{
    return (this->teams);
}

my::nullable<zappy::Team> zappy::Game::getTeam(const std::string &name) const
{
    for (auto &team : this->teams)
        if (team->getName() == name)
            return (team);
    return (nullptr);
}

std::vector<my::nullable<zappy::Player>> zappy::Game::getPlayers() const
{
    return (this->players);
}

std::vector<my::nullable<zappy::Player>> zappy::Game::getPlayersFromTeam(const std::string &teamName) const
{
    std::vector<my::nullable<zappy::Player>> list;
    for (auto &player : this->players) {
        if (player->getTeam().getName() == teamName)
            list.push_back(player);
    }
    return (list);
}

my::nullable<zappy::Player> zappy::Game::getPlayer(int id) const
{
    for (auto &player : this->players)
        if (player->getId() == id)
            return (player);
    return (nullptr);
}

std::vector<zappy::Broadcast> zappy::Game::getLastThreeBroadcasts() const
{
    std::vector<zappy::Broadcast> list;
    int size = broadcasts.size();

    for (int i = size - 3; i < size; i++) {
        if (i >= 0)
            list.push_back(broadcasts[i]);
    }
    return list;
}

void zappy::Game::commandsHandler(std::vector<my::nullable<zappy::Data>> &commands)
{
    for (auto &command : commands) {
        if (command) {
            if (command->command == "bct")
                this->btcCommandHandler(command);
            if (command->command == "pnw")
                this->pnwCommandHandler(command);
            if (command->command == "ppo")
                this->ppoCommandHandler(command);
            if (command->command == "plv")
                this->plvCommandHandler(command);
            if (command->command == "pin")
                this->pinCommandHandler(command);
            if (command->command == "pdi")
                this->pdiCommandHandler(command);
            if (command->command == "pbc")
                this->pbcCommandHandler(command);
        }
    }
}

void zappy::Game::btcCommandHandler(my::nullable<zappy::Data> &data)
{
    int x = data->intArgs[0];
    int y = data->intArgs[1];

    int food = data->intArgs[2];
    int linemate = data->intArgs[3];
    int deraumere = data->intArgs[4];
    int sibur = data->intArgs[5];
    int mendiane = data->intArgs[6];
    int phiras = data->intArgs[7];
    int thystame = data->intArgs[8];

    zappy::Ressources ressources(food, linemate, deraumere, sibur, mendiane, phiras, thystame);

    //std::cout << "ressources: " << ressources << std::endl;

    this->map->setTile(x, y, ressources);
}

void zappy::Game::pnwCommandHandler(my::nullable<zappy::Data> &data)
{
    my::nullable<zappy::Team> team = this->getTeam(data->stringArgs[5]);
    if (!team)
        return;
    zappy::Player newPlayer(*team, std::atoi(data->stringArgs[0].c_str()), std::atoi(data->stringArgs[4].c_str()));
    newPlayer.setX(std::atoi(data->stringArgs[1].c_str()));
    newPlayer.setY(std::atoi(data->stringArgs[2].c_str()));
    newPlayer.setOrientation(std::atoi(data->stringArgs[3].c_str()));

    for (auto &player : this->players)
        if (player)
            if (player->getId() == newPlayer.getId()) {
                player = newPlayer;
                return;
            }
    this->players.push_back(newPlayer);
}

void zappy::Game::ppoCommandHandler(my::nullable<zappy::Data> &data)
{
    int id = std::atoi(data->stringArgs[0].c_str());
    for (auto &player : this->players) {
        if (player) {
            if (player->getId() == id) {
                player->setOrientation(std::atoi(data->stringArgs[3].c_str()));
                player->setX(std::atoi(data->stringArgs[1].c_str()));
                player->setY(std::atoi(data->stringArgs[2].c_str()));
            }
        }
    }
}

void zappy::Game::plvCommandHandler(my::nullable<zappy::Data> &data)
{
    std::cout << "plvCommandHandler" << std::endl;
    int id = std::atoi(data->stringArgs[0].c_str());
    int lvl = std::atoi(data->stringArgs[1].c_str());

    for (auto &player : this->players)
        if (player->getId() == id)
            player->setLevel(lvl);
}

void zappy::Game::pinCommandHandler(my::nullable<zappy::Data> &data)
{
    int id = std::atoi(data->stringArgs[0].c_str());
    int x = std::atoi(data->stringArgs[1].c_str());
    int y = std::atoi(data->stringArgs[2].c_str());

    int food = std::atoi(data->stringArgs[3].c_str());
    int linemate = std::atoi(data->stringArgs[4].c_str());
    int deraumere = std::atoi(data->stringArgs[5].c_str());
    int sibur = std::atoi(data->stringArgs[6].c_str());
    int mendiane = std::atoi(data->stringArgs[7].c_str());
    int phiras = std::atoi(data->stringArgs[8].c_str());
    int thystame = std::atoi(data->stringArgs[9].c_str());

    zappy::Ressources ressources(food, linemate, deraumere, sibur, mendiane, phiras, thystame);
    for (auto &player : this->players)
        if (player->getId() == id)
            player->setResources(ressources);
}

void zappy::Game::pdiCommandHandler(my::nullable<zappy::Data> &data)
{
    int id = std::atoi(data->stringArgs[0].c_str());
    for (auto &player : this->players)
        if (player)
            if (player->getId() == id)
                player->kill();
}

void zappy::Game::pbcCommandHandler(my::nullable<zappy::Data> &data)
{
    int x = 0; int y = 0;
    int id = std::atoi(data->stringArgs[0].c_str());
    std::string message = data->stringArgs[1];

    for (auto &player : this->players)
        if (player->getId() == id) {
            x = player->getX();
            y = player->getY();
        }
    zappy::Broadcast broadcast(x, y, id, message);

    this->broadcasts.push_back(broadcast);
}
