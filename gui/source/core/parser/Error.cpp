/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Error
*/

#include "Error.hpp"

zappy::Error::Error(int argc, char **argv)
{
    this->port = 0;
    this->machine = "127.0.0.1";
    this->help = false;
    try {
        for (std::size_t i = 1; i < argc; i++) {
            std::string string(argv[i]);
            if (string == "-p") {
                i++;
                this->port = std::atoi(argv[i]);
            } else if (string == "-h") {
                i++;
                this->machine = std::string(argv[i]);
            } else if (string == "-help") {
                this->help = true;
                break;
            } else {
                throw (std::runtime_error("Unknown parameter"));
            }
        }
    } catch (...) {
        this->displayHelp();
        exit(84);
    }
    if (this->help) {
        this->displayHelp();
        exit(0);
    }
    if (!this->port) {
        this->displayHelp();
        exit(84);
    }
}

void zappy::Error::displayHelp() const
{
    std::cout << "USAGE: ./zappy_ai -p port -h machine" << std::endl
              << "\tport\tis the port number" << std::endl
              << "\tmachine\tis the name of the machine; localhost by default" << std::endl;
}

int zappy::Error::getPort() const
{
    return (this->port);
}

std::string zappy::Error::getMachine() const
{
    return (this->machine);
}
