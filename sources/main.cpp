/*
** EPITECH PROJECT, 2022
** maths
** File description:
** main
*/

#include "yams.hpp"

int main(int ac, char **av)
{
    if (ac >= 2 && std::string(av[1]) == "-h") {
        std::cout << usage << std::endl;
        return 0;
    }
    if (error_handle(ac, av))
        return 84;
    int dice[5] = {atoi(av[1]), atoi(av[2]), atoi(av[3]), atoi(av[4]), atoi(av[5])};
    yams(dice, std::string(av[6]));
}
