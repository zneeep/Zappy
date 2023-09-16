/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Socket
*/

#include "Socket.hpp"

zappy::Socket::Socket(int port, const std::string &serverAddress)
{
    this->serverPort = port;
    this->serverAddress = serverAddress;
    this->sock = -1;
}

zappy::Socket::~Socket()
{
    close(this->sock);
}

bool zappy::Socket::connectToServer()
{
    this->sock = socket(AF_INET, SOCK_STREAM, 0);
    if (this->sock < 0) {
        std::cerr << "Erreur lors de la création du socket." << std::endl;
        return (false);
    }

    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(this->serverPort);

    if (inet_pton(AF_INET, this->serverAddress.c_str(), &(server.sin_addr)) <= 0) {
        std::cerr << "Adresse invalide ou non supportée." << std::endl;
        return (false);
    }

    if (connect(this->sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        std::cerr << "Connexion échouée." << std::endl;
        return (false);
    }

    if (this->sock < 0) {
        std::cerr << "Socket invalide." << std::endl;
        return (false);
    }

    std::cout << "Connecté au serveur." << std::endl;
    return (true);
}

bool zappy::Socket::sendMessage(const std::string &command, int milisecondsToWait)
{
    if (this->sock == 0) {
        std::cerr << "Socket invalide." << std::endl;
        return (false);
    }

    if (send(this->sock, command.c_str(), command.length(), 0) == -1) {
        std::cerr << "Erreur lors de l'envoi des données." << std::endl;
        return (false);
    }

    std::chrono::milliseconds wait(milisecondsToWait);
    std::this_thread::sleep_for(wait);

    return (true);
}

std::string zappy::Socket::receiveMessage()
{
    if (this->sock == 0) {
        std::cerr << "Invalid socket." << std::endl;
        return "";
    }

    const int bufferSize = 4096;
    char buffer[bufferSize] = {0};
    std::string receivedData;

    fd_set readSet;
    FD_ZERO(&readSet);
    FD_SET(this->sock, &readSet);

    struct timeval timeout;
    timeout.tv_sec = 0;
    timeout.tv_usec = 0;

    // Check if there is data available to read
    int readySockets = select(this->sock + 1, &readSet, nullptr, nullptr, &timeout);

    if (readySockets < 0) {
        std::cerr << "Failed to select socket." << std::endl;
        return "";
    }

    if (readySockets == 0) {
        // No data available to read
        return "";
    }

    // Data is available, read from the socket

    if (FD_ISSET(this->sock, &readSet)) {
        int bytesRead = recv(this->sock, buffer, bufferSize - 1, 0);

        if (bytesRead < 0) {
            std::cerr << "Failed to receive data from socket." << std::endl;
            return "";
        }

        receivedData = buffer;

        //std::cout << receivedData << std::endl;

        return receivedData;
    }
    return "";
}
