/*
** EPITECH PROJECT, 2022
** maths
** File description:
** yams
*/

#include "yams.hpp"

double binomial_law(int a, int b)
{
    return (std::tgamma(a + 1) / (std::tgamma(b + 1) * std::tgamma(a - b + 1))) * pow(1.0/6.0, b) * pow(5.0/6.0, a-b);
}

int count(int dice[5], int val)
{
    int r = 0;

    for (int i = 0; i < 5; ++i) {
        if (dice[i] == val)
            r+=1;
    }
    return r;
}

double calc_probs(int type, int dice[5], int nb)
{
    double res = 0.0;
    int appear = count(dice, nb);

    if (appear >= type)
        return 100;
    for (int i = type - appear; i < 6 - appear; ++i) {
        res += binomial_law(5 - appear, i);
    }
    return res * 100;
}

double straight_probs(int dice[5], int nb)
{
    int appear = 0;

    for (int i = nb - 4; i <= nb; ++i)
        appear += count(dice, i) ? 1 : 0;
    return (std::tgamma(5 - appear + 1) / pow(6, 5 - appear)) * 100;
}

double full_probs(int dice[5], int br, int db)
{
    int brcpt = count(dice, br);
    int dbcpt = count(dice, db);

    if (brcpt >= 3)
        brcpt = 3;
    if (dbcpt >= 2)
        dbcpt = 2;
    if (dbcpt + brcpt >= 5)
        return 100;
    int n3 = 3 - brcpt;
    int r = 5 - brcpt - dbcpt;
    float cn3r = std::tgamma(r + 1) / (std::tgamma(n3 + 1) * std::tgamma(r - n3 + 1));
    return (cn3r/ pow(6, 5 - brcpt - dbcpt)) * 100;
}

int yams(int dice[5], std::string event)
{
    int r = count(dice, 0);


    if (r != 0 && r != 5) {
        std::cerr << "must have 0 or 5 uninizialized dices" << std::endl;
        return 84;
    }
    if (event.rfind("pair_", 0) == 0)
        std::cout << "Chances to get a " << event[5] << " pair: " << std::fixed <<  std::setprecision(2) << calc_probs(2, dice, event[5] - '0') << "%" << std::endl;
    else if (event.rfind("three_", 0) == 0)
        std::cout << "Chances to get a " << event[6] << " three-of-a-kind: " << std::fixed <<  std::setprecision(2) << calc_probs(3, dice, event[6] - '0') << "%" << std::endl;
    else if (event.rfind("four_", 0) == 0)
        std::cout << "Chances to get a " << event[5] << " four-of-a-kind: " << std::fixed <<  std::setprecision(2) << calc_probs(4, dice, event[5] - '0') << "%" << std::endl;
    else if (event.rfind("yams_", 0) == 0)
        std::cout << "Chances to get a " << event[5] << " yams: " << std::fixed <<  std::setprecision(2) << calc_probs(5, dice, event[5] - '0') << "%" << std::endl;
    else if (event.rfind("straight_", 0) == 0)
        std::cout << "Chances to get a " << event[9] << " straight: " << std::fixed <<  std::setprecision(2) << straight_probs(dice, event[9] - '0') << "%" << std::endl;
    else if (event.rfind("full_", 0) == 0)
        std::cout << "Chances to get a " << event[5] << " full of " << event[7] << ": " << std::fixed <<  std::setprecision(2) << full_probs(dice, event[5] - '0', event[7] - '0') << "%" << std::endl;
    return 0;
}