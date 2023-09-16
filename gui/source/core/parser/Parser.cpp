/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Parser
*/

#include "Parser.hpp"

zappy::Data::Data(const zappy::Data &data)
{
    this->command = data.command;
    this->intArgs = data.intArgs;
    this->stringArgs = data.stringArgs;
}

std::vector<std::string> zappy::Parser::split(const std::string &string, const std::string &separator)
{
    std::vector<std::string> result;
    std::string::size_type start = 0;
    std::string::size_type end = string.find(separator);

    while (end != std::string::npos) {
        result.push_back(string.substr(start, end - start));
        start = end + separator.length();
        end = string.find(separator, start);
    }

    result.push_back(string.substr(start));

    return (result);
}

my::nullable<zappy::Data> zappy::Parser::msz(const std::string &string)
{
    zappy::Data data;

    std::vector<std::string> split = zappy::Parser::split(string, " ");

    if (split.size() != 3)
        return (nullptr);
    if (split[0] != "msz")
        return (nullptr);

    data.command = split[0];
    data.intArgs.push_back(std::atoi(split[1].c_str()));
    data.intArgs.push_back(std::atoi(split[2].c_str()));
    return (data);
}

my::nullable<zappy::Data> zappy::Parser::bct(const std::string &string)
{
    zappy::Data data;

    std::vector<std::string> split = zappy::Parser::split(string, " ");

    if (split.size() != 10)
        return (nullptr);
    if (split[0] != "bct")
        return (nullptr);

    data.command = split[0];
    for (int i = 1; i < 10; i++)
        data.intArgs.push_back(std::atoi(split[i].c_str()));
    return (data);
}

my::nullable<zappy::Data> zappy::Parser::tna(const std::string &string)
{
    zappy::Data data;

    std::vector<std::string> split = zappy::Parser::split(string, " ");

    if (split.size() != 2)
        return (nullptr);
    if (split[0] != "tna")
        return (nullptr);

    data.command = split[0];
    data.stringArgs.push_back(split[1]);
    return (data);
}

my::nullable<zappy::Data> zappy::Parser::pnw(const std::string &string)
{
    zappy::Data data;

    std::vector<std::string> split = zappy::Parser::split(string, " ");

    if (split.size() != 7)
        return (nullptr);
    if (split[0] != "pnw")
        return (nullptr);

    data.command = split[0];
    data.stringArgs.push_back(split[1]);
    data.stringArgs.push_back(split[2]);
    data.stringArgs.push_back(split[3]);
    data.stringArgs.push_back(split[4]);
    data.stringArgs.push_back(split[5]);
    data.stringArgs.push_back(split[6]);
    return (data);
}

my::nullable<zappy::Data> zappy::Parser::ppo(const std::string &string)
{
    zappy::Data data;

    std::vector<std::string> split = zappy::Parser::split(string, " ");

    if (split.size() != 5)
        return (nullptr);
    if (split[0] != "ppo")
        return (nullptr);

    data.command = split[0];
    data.stringArgs.push_back(split[1]);
    data.stringArgs.push_back(split[2]);
    data.stringArgs.push_back(split[3]);
    data.stringArgs.push_back(split[4]);
    return (data);
}

my::nullable<zappy::Data> zappy::Parser::plv(const std::string &string)
{
    std::cout << "plv" << std::endl;
    zappy::Data data;

    std::vector<std::string> split = zappy::Parser::split(string, " ");

    if (split.size() != 3)
        return (nullptr);
    if (split[0] != "plv")
        return (nullptr);

    data.command = split[0];
    data.stringArgs.push_back(split[1]);
    data.stringArgs.push_back(split[2]);
    return (data);
}

my::nullable<zappy::Data> zappy::Parser::pin(const std::string &string)
{
    zappy::Data data;

    std::vector<std::string> split = zappy::Parser::split(string, " ");

    if (split.size() != 11)
        return (nullptr);
    if (split[0] != "pin")
        return (nullptr);

    data.command = split[0];
    data.stringArgs.push_back(split[1]);
    data.stringArgs.push_back(split[2]);
    data.stringArgs.push_back(split[3]);
    data.stringArgs.push_back(split[4]);
    data.stringArgs.push_back(split[5]);
    data.stringArgs.push_back(split[6]);
    data.stringArgs.push_back(split[7]);
    data.stringArgs.push_back(split[8]);
    data.stringArgs.push_back(split[9]);
    data.stringArgs.push_back(split[10]);
    return (data);
}

my::nullable<zappy::Data> zappy::Parser::pex(const std::string &string)
{
    zappy::Data data;

    std::vector<std::string> split = zappy::Parser::split(string, " ");

    if (split.size() != 2)
        return (nullptr);
    if (split[0] != "pex")
        return (nullptr);

    data.command = split[0];
    data.stringArgs.push_back(split[1]);
    return (data);
}

my::nullable<zappy::Data> zappy::Parser::pbc(const std::string &string)
{
    zappy::Data data;

    std::vector<std::string> split = zappy::Parser::split(string, " ");

    if (split[0] != "pbc")
        return (nullptr);

    data.command = split[0];
    data.stringArgs.push_back(split[1]);
    std::string removed = std::string(string);
    removed.erase(0, 4 + split[1].length());
    data.stringArgs.push_back(removed);
    return (data);
}

my::nullable<zappy::Data> zappy::Parser::pic(const std::string &string)
{
    zappy::Data data;

    std::vector<std::string> split = zappy::Parser::split(string, " ");

    if (split[0] != "pic")
        return (nullptr);

    data.command = split[0];
    for (int i = 1; i < split.size(); i++)
        data.stringArgs.push_back(split[i]);
    return (data);
}

my::nullable<zappy::Data> zappy::Parser::pie(const std::string &string)
{
    zappy::Data data;

    std::vector<std::string> split = zappy::Parser::split(string, " ");

    if (split[0] != "pie")
        return (nullptr);

    data.command = split[0];
    data.stringArgs.push_back(split[1]);
    data.stringArgs.push_back(split[2]);
    data.stringArgs.push_back(split[3]);
    return (data);
}

my::nullable<zappy::Data> zappy::Parser::pfk(const std::string &string)
{
    zappy::Data data;

    std::vector<std::string> split = zappy::Parser::split(string, " ");

    if (split[0] != "pfk")
        return (nullptr);

    data.command = split[0];
    data.stringArgs.push_back(split[1]);
    return (data);
}

my::nullable<zappy::Data> zappy::Parser::pdr(const std::string &string)
{
    zappy::Data data;

    std::vector<std::string> split = zappy::Parser::split(string, " ");

    if (split[0] != "pdr")
        return (nullptr);

    data.command = split[0];
    data.stringArgs.push_back(split[1]);
    data.stringArgs.push_back(split[2]);
    return (data);
}

my::nullable<zappy::Data> zappy::Parser::pgt(const std::string &string)
{
    zappy::Data data;

    std::vector<std::string> split = zappy::Parser::split(string, " ");

    if (split[0] != "pgt")
        return (nullptr);

    data.command = split[0];
    data.stringArgs.push_back(split[1]);
    data.stringArgs.push_back(split[2]);
    return (data);
}

my::nullable<zappy::Data> zappy::Parser::pdi(const std::string &string)
{
    zappy::Data data;

    std::vector<std::string> split = zappy::Parser::split(string, " ");

    if (split[0] != "pdi")
        return (nullptr);

    data.command = split[0];
    data.stringArgs.push_back(split[1]);
    return (data);
}

my::nullable<zappy::Data> zappy::Parser::enw(const std::string &string)
{
    zappy::Data data;

    std::vector<std::string> split = zappy::Parser::split(string, " ");

    if (split[0] != "enw")
        return (nullptr);

    data.command = split[0];
    data.stringArgs.push_back(split[1]);
    data.stringArgs.push_back(split[2]);
    data.stringArgs.push_back(split[3]);
    data.stringArgs.push_back(split[4]);
    return (data);
}

my::nullable<zappy::Data> zappy::Parser::ebo(const std::string &string)
{
    zappy::Data data;

    std::vector<std::string> split = zappy::Parser::split(string, " ");

    if (split[0] != "ebo")
        return (nullptr);

    data.command = split[0];
    data.stringArgs.push_back(split[1]);
    return (data);
}

my::nullable<zappy::Data> zappy::Parser::ebi(const std::string &string)
{
    zappy::Data data;

    std::vector<std::string> split = zappy::Parser::split(string, " ");

    if (split[0] != "ebi")
        return (nullptr);

    data.command = split[0];
    data.stringArgs.push_back(split[1]);
    return (data);
}

my::nullable<zappy::Data> zappy::Parser::sgt(const std::string &string)
{
    zappy::Data data;

    std::vector<std::string> split = zappy::Parser::split(string, " ");

    if (split[0] != "sgt")
        return (nullptr);

    data.command = split[0];
    data.stringArgs.push_back(split[1]);
    return (data);
}

my::nullable<zappy::Data> zappy::Parser::sst(const std::string &string)
{
    zappy::Data data;

    std::vector<std::string> split = zappy::Parser::split(string, " ");

    if (split[0] != "sst")
        return (nullptr);

    data.command = split[0];
    data.stringArgs.push_back(split[1]);
    return (data);
}

my::nullable<zappy::Data> zappy::Parser::seg(const std::string &string)
{
    zappy::Data data;

    std::vector<std::string> split = zappy::Parser::split(string, " ");

    if (split[0] != "seg")
        return (nullptr);

    data.command = split[0];
    data.stringArgs.push_back(split[1]);
    return (data);
}

my::nullable<zappy::Data> zappy::Parser::smg(const std::string &string)
{
    zappy::Data data;

    std::vector<std::string> split = zappy::Parser::split(string, " ");

    if (split[0] != "smg")
        return (nullptr);

    data.command = split[0];
    data.stringArgs.push_back(split[1]);
    return (data);
}

my::nullable<zappy::Data> zappy::Parser::suc(const std::string &string)
{
    zappy::Data data;

    std::vector<std::string> split = zappy::Parser::split(string, " ");

    if (split[0] != "suc")
        return (nullptr);

    data.command = split[0];
    return (data);
}

my::nullable<zappy::Data> zappy::Parser::sbp(const std::string &string)
{
    zappy::Data data;

    std::vector<std::string> split = zappy::Parser::split(string, " ");

    if (split[0] != "sbp")
        return (nullptr);

    data.command = split[0];
    return (data);
}

std::vector<my::nullable<zappy::Data>> zappy::Parser::commandList(const std::string &string)
{
    std::vector<my::nullable<zappy::Data>> datas;

    std::vector<std::string> commands = zappy::Parser::split(string, "\n");
    for (std::size_t i = 0; i < commands.size(); i++) {
        std::vector<std::string> split = zappy::Parser::split(commands[i], " ");

        if (split[0] == "msz")
            datas.push_back(zappy::Parser::msz(commands[i]));
        if (split[0] == "bct")
            datas.push_back(zappy::Parser::bct(commands[i]));
        if (split[0] == "tna")
            datas.push_back(zappy::Parser::tna(commands[i]));
        if (split[0] == "pnw")
            datas.push_back(zappy::Parser::pnw(commands[i]));
        if (split[0] == "ppo")
            datas.push_back(zappy::Parser::ppo(commands[i]));
        if (split[0] == "plv")
            datas.push_back(zappy::Parser::plv(commands[i]));
        if (split[0] == "pin")
            datas.push_back(zappy::Parser::pin(commands[i]));
        if (split[0] == "pex")
            datas.push_back(zappy::Parser::pex(commands[i]));
        if (split[0] == "pbc")
            datas.push_back(zappy::Parser::pbc(commands[i]));
        if (split[0] == "pic")
            datas.push_back(zappy::Parser::pic(commands[i]));
        if (split[0] == "pie")
            datas.push_back(zappy::Parser::pie(commands[i]));
        if (split[0] == "pfk")
            datas.push_back(zappy::Parser::pfk(commands[i]));
        if (split[0] == "pdr")
            datas.push_back(zappy::Parser::pdr(commands[i]));
        if (split[0] == "pgt")
            datas.push_back(zappy::Parser::pgt(commands[i]));
        if (split[0] == "pdi")
            datas.push_back(zappy::Parser::pdi(commands[i]));
        if (split[0] == "enw")
            datas.push_back(zappy::Parser::enw(commands[i]));
        if (split[0] == "ebo")
            datas.push_back(zappy::Parser::ebo(commands[i]));
        if (split[0] == "ebi")
            datas.push_back(zappy::Parser::ebi(commands[i]));
        if (split[0] == "sgt")
            datas.push_back(zappy::Parser::sgt(commands[i]));
        if (split[0] == "sst")
            datas.push_back(zappy::Parser::sst(commands[i]));
        if (split[0] == "seg")
            datas.push_back(zappy::Parser::seg(commands[i]));
        if (split[0] == "smg")
            datas.push_back(zappy::Parser::smg(commands[i]));
        if (split[0] == "suc")
            datas.push_back(zappy::Parser::smg(commands[i]));
        if (split[0] == "sbp")
            datas.push_back(zappy::Parser::smg(commands[i]));
    }
    return (datas);
}
