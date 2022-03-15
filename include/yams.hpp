/*
** EPITECH PROJECT, 2022
** maths
** File description:
** yams
*/

#ifndef YAMS_HPP_
#define YAMS_HPP_

#include <string>
#include <string.h>
#include <iostream>
#include <iomanip>
#include <cmath>

static const std::string usage = "USAGE\n\t./201yams d1 d2 d3 d4 d5 c\nDESCRIPTION\n\td1 value of the first die (0 if not thrown)\n\td2 value of the second die (0 if not thrown)\n\td3 value of the third die (0 if not thrown)\n\td4 value of the fourth die (0 if not thrown)\n\td5 value of the fifth die";

int yams(int dice[5], std::string event);
int error_handle(int ac, char **av);

#endif /* !YAMS_HPP_ */
