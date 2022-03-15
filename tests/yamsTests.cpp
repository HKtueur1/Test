/*
** EPITECH PROJECT, 2022
** B-MAT-400-PAR-4-1-201yams-zacharie.lawson
** File description:
** yamsTests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "yams.hpp"

#include <string>
#include <iostream>
#include <ostream>

double binomial_law(int a, int b);
int count(int dice[5], int val);
double calc_probs(int type, int dice[5], int nb);
double straight_probs(int dice[5], int nb);
double full_probs(int dice[5], int br, int db);

class OSRedirector {
    private:
        std::ostringstream _oss;
        std::streambuf *_backup;
        std::ostream &_c;

    public:
        OSRedirector(std::ostream &c) : _c(c) {
            _backup = _c.rdbuf();
            _c.rdbuf(_oss.rdbuf());
        }

        ~OSRedirector() {
            _c.rdbuf(_backup);
        }

        const std::string getContent() {
            _oss << std::flush;
            return _oss.str();
        }
};

Test(Yams, yamstests)
{
    int _dices[5] = {2, 3, 2, 3, 2};
    OSRedirector oss(std::cout);


    cr_assert_eq(yams(_dices, "pair_2"), 0);
    cr_assert_eq(yams(_dices, "three_2"), 0);
    cr_assert_eq(yams(_dices, "four_4"), 0);
    cr_assert_eq(yams(_dices, "yams_4"), 0);
    cr_assert_eq(yams(_dices, "straight_6"), 0);
    cr_assert_eq(yams(_dices, "full_2_3"), 0);
    cr_assert_eq(yams(_dices, "nothing"), 0);
    cr_assert_eq(oss.getContent(), "Chances to get a 2 pair: 100.00%\nChances to get a 2 three-of-a-kind: 100.00%\nChances to get a 4 four-of-a-kind: 0.33%\nChances to get a 4 yams: 0.01%\nChances to get a 6 straight: 2.78%\nChances to get a 2 full of 3: 100.00%\n");

}

Test(Yams, calculusTest)
{
    int _noDices[5] = {0, 0, 0, 0, 0};
    int _dices[5] = {2, 3, 2, 3, 2};
    int _dices2[5] = {2, 2, 5, 4, 6};

    cr_assert_eq(binomial_law(0, 0), 1);

    cr_assert_eq(count(_dices, 2), 3);

    // use round(n * 100) / 100 because the value received is not exact
    cr_assert_eq(round((calc_probs(5, _noDices, 4)) * 100) / 100, 0.01);
    cr_assert_eq(round((calc_probs(2, _dices, 2)) * 100) / 100, 100);

    cr_assert_eq(round((straight_probs(_dices2, 6)) * 100) / 100, 16.67);

    cr_assert_eq(round((full_probs(_noDices, 2, 3)) * 100) / 100, 0.13);
    cr_assert_eq(round((full_probs(_dices, 2, 3)) * 100) / 100, 100);
}