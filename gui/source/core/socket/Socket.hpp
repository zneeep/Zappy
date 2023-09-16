/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Socket
*/

#ifndef SOCKET_HPP_
#define SOCKET_HPP_

#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <algorithm>
#include <thread>
#include <sys/select.h>
#include <sys/time.h>

namespace zappy
{
    class Socket {
        public:
            Socket(int port, const std::string &serverAddress);
            ~Socket();

            /**
            ** @brief return value: true = succeed, false = failled
            **/
            bool connectToServer();

            /**
            ** @brief return value: true = succeed, false = failled
            ** @param command command send to the server
            **/
            bool sendMessage(const std::string &command, int milisecondsToWait = 0);

            /**
             * @brief return the list of messages send from the server
            */
            std::string receiveMessage();

        protected:
        private:
            int sock;
            int serverPort;
            std::string serverAddress;
    };
}

#endif /* !SOCKET_HPP_ */
