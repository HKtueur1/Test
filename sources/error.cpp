/*
** EPITECH PROJECT, 2022
** maths
** File description:
** error
*/

#include "yams.hpp"

int error_handle(int ac, char **av)
{
    if (ac != 7)
        return 84;
    for (int i = 1; i < 6; ++i) {
        if (std::string(av[i]).length() != 1 || std::string("0123456").find(std::string(av[i])) ==  std::string::npos)
            return 84;
    }
    if (std::string(av[6]).rfind("pair_", 0) == 0) {
        if (std::string(av[6]).length() != 6 || std::string("123456").find(av[6][5]) == std::string::npos)
            return 84;
        return 0;
    }
    if (std::string(av[6]).rfind("three_", 0) == 0) {
        if (std::string(av[6]).length() != 7 || std::string("123456").find(av[6][6]) == std::string::npos)
            return 84;
        return 0;
    }
    if (std::string(av[6]).rfind("four_", 0) == 0) {
        if (std::string(av[6]).length() != 6 || std::string("123456").find(av[6][5]) == std::string::npos)
            return 84;
        return 0;
    }
    if (std::string(av[6]).rfind("full_", 0) == 0) {
        if (std::string(av[6]).length() != 8 || std::string("123456").find(av[6][5]) == std::string::npos || av[6][6] != '_' || std::string("123456").find(av[6][7]) == std::string::npos || av[6][5] == av[6][7])
            return 84;
        return 0;
    }
    if (std::string(av[6]).rfind("straight_", 0) == 0) {
        if (std::string(av[6]).length() != 10 || std::string("56").find(av[6][9]) == std::string::npos)
            return 84;
        return 0;
    }
    if (std::string(av[6]).rfind("yams_", 0) == 0) {
        if (std::string(av[6]).length() != 6 || std::string("123456").find(av[6][5]) == std::string::npos) {
            return 84;
        }
        return 0;
    }
    return 84;
}