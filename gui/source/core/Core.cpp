/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Core
*/

#include "Core.hpp"

zappy::Core::Core(int argc, char **argv)
{
    zappy::Error errorParser(argc, argv);

    this->tile = nullptr;
    this->camera = zappy::Camera();
    this->map = nullptr;
    this->socket = zappy::Socket(errorParser.getPort(), errorParser.getMachine());
    this->socket->connectToServer();
    this->renderer = zappy::SFML(__WINDOW_WIDTH__, __WINDOW_HEIGHT__, "zappy");
    std::cout << this->socket->receiveMessage() << std::endl;
    this->initGame();
}

void zappy::Core::run()
{
    std::chrono::duration<double> elapsed_time;

    double tile_size_x = __WINDOW_WIDTH_MAP__ / static_cast<double>(this->game->getMap()->getWidth()) - __WINDOW_SEPARATOR_SIZE__;
    double tile_size_y = __WINDOW_HEIGHT_MAP__ / static_cast<double>(this->game->getMap()->getHeight()) - __WINDOW_SEPARATOR_SIZE__;

    int boucle = 0;

    while (this->renderer->isOpen())
    {
        std::chrono::time_point<std::chrono::steady_clock> start_time = std::chrono::steady_clock::now();

        boucle++;
        if (boucle >= 10) {
            boucle = 0;
            this->socket->sendMessage("mct\n");
        }

        std::string buffer = this->socket->receiveMessage();

        std::vector<my::nullable<zappy::Data>> commands = zappy::Parser::commandList(buffer);
        this->game->commandsHandler(commands);

        this->drawGame(tile_size_x, tile_size_y);
        this->drawSidebar();
        this->drawBroadcasts();

        std::chrono::time_point<std::chrono::steady_clock> end_time = std::chrono::steady_clock::now();
        elapsed_time = end_time - start_time;
        std::chrono::duration<double> remaining_time = std::chrono::duration<double>(1.0 / 60.0) - elapsed_time;
        if (remaining_time > std::chrono::duration<double>(0))
            std::this_thread::sleep_for(std::chrono::duration_cast<std::chrono::nanoseconds>(remaining_time));
        this->renderer->display();
    }
}

void zappy::Core::drawGame(int __tile_size_x, int __tile_size_y)
{
    std::vector<zappy::Events> events = this->renderer->events();
    this->moveCamera(events);

    my::nullable<std::pair<int, int>> click = this->renderer->getMouseClick();
    if (click) {
        this->playerId = nullptr;
        this->tile = this->getTileFromClick(*click, __tile_size_x, __tile_size_y);
        if (!this->tile) {
            std::vector<my::nullable<zappy::Player>> playersAlive;
            for (auto &player : this->game->getPlayers())
                playersAlive.push_back(player);
            for (int i = 0; i < playersAlive.size(); i++) {
                int x = __WINDOW_WIDTH__ - __WINDOW_SIDEBAR_WIDTH__;
                int y = 110 + (this->game->getTeams().size() * 40) + 80 + (i * 40);

                if (click->first >= x && click->first <= __WINDOW_WIDTH__ &&
                    click->second >= y && click->second <= y + 40)
                    this->playerId = playersAlive[i]->getId();
            }
        }
    }

    this->renderer->drawBackground(42, 244, 155);

    double scale = this->camera->getZoom();

    double relative_x = this->camera->getX();
    double relative_y = this->camera->getY();

    this->map = this->game->getMap();

    for (int i = 0; i < this->map->getHeight(); i++) {
        for (int j = 0; j < this->map->getWidth(); j++) {
            zappy::Tile tile = this->map->getTile(j, i);
            zappy::Ressources resources = tile.getRessources();
            std::string resourceString;

            // Format the resources as a string separated by '\n'
            resourceString += std::to_string(resources.food) + "\n";
            resourceString += std::to_string(resources.linemate) + "\n";
            resourceString += std::to_string(resources.deraumere) + "\n";
            resourceString += std::to_string(resources.sibur) + "\n";
            resourceString += std::to_string(resources.mendiane) + "\n";
            resourceString += std::to_string(resources.phiras) + "\n";
            resourceString += std::to_string(resources.thystame);

            this->renderer->drawSquare((__tile_size_x + __WINDOW_SEPARATOR_SIZE__) * j * scale + relative_x,
                                       (__tile_size_y + __WINDOW_SEPARATOR_SIZE__) * i * scale + relative_y,
                                       __tile_size_x * scale,
                                       __tile_size_y * scale,
                                       40, 40, 40, 255);
            this->renderer->drawText((__tile_size_x + __WINDOW_SEPARATOR_SIZE__) * j * scale + relative_x + 10,
                                     (__tile_size_y + __WINDOW_SEPARATOR_SIZE__) * i * scale + relative_y + 10,
                                     resourceString, "arial2.ttf", 10 * scale, 255, 255, 255, 255);
        }
    }

    int offsetPlayer = 1;
    /* draw player */
    for (auto &player : this->game->getPlayers()) {
        if (player->isPlayerAlive()) {
            int x = player->getX();
            int y = player->getY();

            this->renderer->drawSquare((__tile_size_x + __WINDOW_SEPARATOR_SIZE__) * x * scale + relative_x + (__tile_size_x * scale * (0.5 + ( int(offsetPlayer / 5.0) / 10.0 ) )),
                                    (__tile_size_y + __WINDOW_SEPARATOR_SIZE__) * y * scale + relative_y + (__tile_size_y * scale * ( offsetPlayer / 10.0 )),
                                    (__tile_size_x / 10) * scale,
                                    (__tile_size_y / 10) * scale,
                                    50, 237, 255, 255);

            offsetPlayer++;
        }
    }
}

void zappy::Core::drawSidebar()
{
    this->renderer->drawSquare(__WINDOW_WIDTH__ - __WINDOW_SIDEBAR_WIDTH__,
                               __WINDOW_HEIGHT__ - __WINDOW_SIDEBAR_HEIGHT__,
                               __WINDOW_SIDEBAR_WIDTH__,
                               __WINDOW_SIDEBAR_HEIGHT__,
                               40, 40, 40, 255);

    if (this->tile) {
        zappy::Tile tile = this->map->getTile(this->tile->first, this->tile->second);

        zappy::TileUI tileui(tile);
        tileui.render(this->renderer);

        std::vector<std::pair<int, int>> previewPositions;

        for (auto &player : this->game->getPlayers()) {
            this->socket->sendMessage("pin " + std::to_string(player->getId()) + "\n");
            int x = player->getX();
            int y = player->getY();

            if (x == this->tile->first && y == this->tile->second) {
                int offset = 0;

                for (auto &previewPosition : previewPositions)
                    if (this->tile->first == previewPosition.first &&
                        this->tile->second == previewPosition.second)
                            offset += 120;

                this->socket->sendMessage("plv " + std::to_string(player->getId()) + "\n");
                zappy::PlayerUI playerUI(*player);
                playerUI.render(this->renderer, offset);
            }

            std::pair<int, int> position;
            position.first = x;
            position.second = y;
            previewPositions.push_back(position);
        }
    } else if (this->playerId) {
        my::nullable<zappy::Player> player = this->game->getPlayer(*this->playerId);
        this->socket->sendMessage("plv " + std::to_string(*this->playerId) + "\n");
        this->socket->sendMessage("pin " + std::to_string(*this->playerId) + "\n");
        zappy::PlayerUI playerUI(*player);
        playerUI.render(this->renderer, -450);
    } else {
        // -- Game UI --
        zappy::GameUI gameui(*this->game);
        gameui.render(this->renderer);
    }

}

void zappy::Core::drawBroadcasts()
{
    // Draw Broadcast UI
    this->renderer->drawSquare(__WINDOW_WIDTH__ - __WINDOW_CHAT_WIDTH__,
                               __WINDOW_HEIGHT__ - __WINDOW_CHAT_HEIGHT__,
                               __WINDOW_CHAT_WIDTH__,
                               __WINDOW_CHAT_HEIGHT__,
                               23, 23, 23, 255);

    // Draw Broadcasts Title
    this->renderer->drawTextCentered(__WINDOW_WIDTH__ - __WINDOW_CHAT_WIDTH__ / 2,
                                     __WINDOW_HEIGHT__ - __WINDOW_CHAT_HEIGHT__ + 10,
                                     "Broadcasts", "arial2.ttf", 20, 255, 255, 255, 255);
    // Draw actual Broadcasts
    std::vector<Broadcast> lastThree = this->game->getLastThreeBroadcasts();
    int y = __WINDOW_HEIGHT__ - __WINDOW_CHAT_HEIGHT__ + 50; // Starting y-coordinate
    for (auto &broadcast : lastThree) {
        this->renderer->drawTextCentered(__WINDOW_WIDTH__ - __WINDOW_CHAT_WIDTH__ / 2,
                                         y,
                                         broadcast.formatString(), "arial2.ttf", 15, 255, 255, 255, 255/2);
        y += 40; // Increment y-coordinate for the next broadcast message
    }
    // Check if timeUnit has changed
    if (this->timeUnit != this->previousTimeUnit) {
        // Update previousTimeUnit with the new value
        this->previousTimeUnit = this->timeUnit;

        // Send "sst" message
        this->socket->sendMessage("sst " + std::to_string(this->timeUnit) + "\n");
    }

    // Draw time unit value
    this->renderer->drawTextCentered(__WINDOW_WIDTH__ - __WINDOW_CHAT_WIDTH__ / 2,
                                     y,
                                     "Time unit: " + std::to_string(this->timeUnit), "arial2.ttf", 15, 255, 255, 255, 255/2);

}

void zappy::Core::initGame()
{
    std::shared_ptr<zappy::Map> map = nullptr;
    std::vector<my::nullable<zappy::Team>> teams;

    this->socket->sendMessage("GRAPHIC\n", 250);

    std::string buffer = this->socket->receiveMessage();

    std::vector<my::nullable<zappy::Data>> datas = zappy::Parser::commandList(buffer);
    std::vector<my::nullable<zappy::Data>> playerConnectionCommands;

    for (const auto &data : datas) {
        if (data) {
            if (data->command == "msz")
                map = std::make_shared<zappy::Map>(zappy::Map(data->intArgs[0], data->intArgs[1]));
            if (data->command == "sgt") {
                this->timeUnit = std::atoi(data->stringArgs[0].c_str());
                this->previousTimeUnit = this->timeUnit;
            }

            if (data->command == "bct")
                map->setTile(data->intArgs[0],
                            data->intArgs[1],
                            zappy::Ressources(
                            data->intArgs[2],
                            data->intArgs[3],
                            data->intArgs[4],
                            data->intArgs[5],
                            data->intArgs[6],
                            data->intArgs[7],
                            data->intArgs[8]));
            if (data->command == "tna")
                teams.push_back(zappy::Team(data->stringArgs[0]));
            if (data->command == "pnw")
                playerConnectionCommands.push_back(data);
        }
    }
    this->game = zappy::Game(map);
    this->game->linkTeams(teams);
    for (auto &command : playerConnectionCommands)
        if (command)
            this->game->pnwCommandHandler(command);
    this->map = this->game->getMap();
}

void zappy::Core::moveCamera(const std::vector<zappy::Events> &__events)
{
    for (auto &event : __events) {
        switch (event)
        {
            case zappy::Events::MOVE_UP:
                this->camera->setY((this->camera->getY() + __CAMERA_SPEED__));
                break;
            case zappy::Events::MOVE_DOWN:
                this->camera->setY((this->camera->getY() - __CAMERA_SPEED__));
                break;
            case zappy::Events::MOVE_LEFT:
                this->camera->setX((this->camera->getX() + __CAMERA_SPEED__));
                break;
            case zappy::Events::MOVE_RIGHT:
                this->camera->setX((this->camera->getX() - __CAMERA_SPEED__));
                break;
            case zappy::Events::ZOOM_IN:
                this->camera->setZoom((this->camera->getZoom() - __CAMERA_ZOOM_SPEED__));
                break;
            case zappy::Events::ZOOM_OUT:
                this->camera->setZoom((this->camera->getZoom() + __CAMERA_ZOOM_SPEED__));
                break;
            case zappy::Events::TIME_UP:
                this->timeUnit += 1;
                if (this->timeUnit > 200)
                    this->timeUnit = 200;
                break;
            case zappy::Events::TIME_DOWN:
                this->timeUnit -= 1;
                if (this->timeUnit < 1)
                    this->timeUnit = 1;
                break;
            default:
                break;
        }
    }
}

my::nullable<std::pair<int, int>> zappy::Core::getTileFromClick(std::pair<int, int> __click, int __tile_size_x, int __tile_size_y)
{
    double scale = this->camera->getZoom();
    double x = this->camera->getX();
    double y = this->camera->getY();

    for (int i = 0; i < this->map->getHeight(); i++) {
        for (int j = 0; j < this->map->getWidth(); j++) {
            double sx = (__tile_size_x + __WINDOW_SEPARATOR_SIZE__) * j * scale + x;
            double sy = (__tile_size_y + __WINDOW_SEPARATOR_SIZE__) * i * scale + y;
            double ex = __tile_size_x * scale;
            double ey = __tile_size_y * scale;

            if (sx < __click.first && __click.first < sx + ex &&
                sy < __click.second && __click.second < sy + ey)
            {
                std::pair<int, int> tileCoordonate;
                tileCoordonate.first = j;
                tileCoordonate.second = i;
                return (tileCoordonate);
            }
        }
    }
    return (nullptr);
}

