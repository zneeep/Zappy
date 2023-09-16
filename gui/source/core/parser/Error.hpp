/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <iostream>

namespace zappy
{
    class Error {
        public:
            Error(int , char **);
            ~Error() = default;

            void displayHelp() const;

            int getPort() const;
            std::string getMachine() const;

        protected:
        private:
            int port;
            std::string machine;
            bool help;
    };
}

#endif /* !ERROR_HPP_ */
