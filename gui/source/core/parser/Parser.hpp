/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>
#include <vector>
#include <iostream>

#include "../../tools/nullable.hpp"

namespace zappy
{
    struct Data {
        Data() = default;
        Data(const zappy::Data &);

        std::string command;
        std::vector<int> intArgs;
        std::vector<std::string> stringArgs;
    };

    class Parser {
        public:
            static std::vector<std::string> split(const std::string &string, const std::string &separator);

            static my::nullable<zappy::Data> msz(const std::string &);
            static my::nullable<zappy::Data> bct(const std::string &);
            static my::nullable<zappy::Data> tna(const std::string &);
            static my::nullable<zappy::Data> pnw(const std::string &);
            static my::nullable<zappy::Data> ppo(const std::string &);
            static my::nullable<zappy::Data> plv(const std::string &);
            static my::nullable<zappy::Data> pin(const std::string &);
            static my::nullable<zappy::Data> pex(const std::string &);
            static my::nullable<zappy::Data> pbc(const std::string &);
            static my::nullable<zappy::Data> pic(const std::string &);
            static my::nullable<zappy::Data> pie(const std::string &);
            static my::nullable<zappy::Data> pfk(const std::string &);
            static my::nullable<zappy::Data> pdr(const std::string &);
            static my::nullable<zappy::Data> pgt(const std::string &);
            static my::nullable<zappy::Data> pdi(const std::string &);
            static my::nullable<zappy::Data> enw(const std::string &);
            static my::nullable<zappy::Data> ebo(const std::string &);
            static my::nullable<zappy::Data> ebi(const std::string &);
            static my::nullable<zappy::Data> sgt(const std::string &);
            static my::nullable<zappy::Data> sst(const std::string &);
            static my::nullable<zappy::Data> seg(const std::string &);
            static my::nullable<zappy::Data> smg(const std::string &);
            static my::nullable<zappy::Data> suc(const std::string &);
            static my::nullable<zappy::Data> sbp(const std::string &);

            static std::vector<my::nullable<zappy::Data>> commandList(const std::string &);

        protected:
        private:
    };
}

#endif /* !PARSER_HPP_ */
