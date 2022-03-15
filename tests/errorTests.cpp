/*
** EPITECH PROJECT, 2022
** B-MAT-400-PAR-4-1-201yams-zacharie.lawson
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "yams.hpp"

#include <string>
#include <iostream>
#include <ostream>

Test(Yams, argvTests)
{
    char *badAv[2] = {(char *)"./201yams", (char *)"jaj"};
    char *notNumAv1[7] = {(char *)"./201yams", (char *)"11", (char *)"0", (char *)"11", (char *)"0", (char *)"0", (char *)"pair_2"};
    char *notNumAv2[7] = {(char *)"./201yams", (char *)"a", (char *)"0", (char *)"A", (char *)"0", (char *)"0", (char *)"pair_2"};
    char *notNumAv3[7] = {(char *)"./201yams", (char *)"aa", (char *)"0", (char *)"aa", (char *)"0", (char *)"0", (char *)"pair_2"};
    char *wrongCommand[7] = {(char *)"./201yams", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"error"};
    int _diceswrong[5] = {0, 0, 2, 3, 2};

    cr_assert_eq(yams(_diceswrong, "pair_2"), 84);
    cr_assert_eq(error_handle(2, badAv), 84);
    cr_assert_eq(error_handle(7, notNumAv1), 84);
    cr_assert_eq(error_handle(7, notNumAv2), 84);
    cr_assert_eq(error_handle(7, notNumAv3), 84);
    cr_assert_eq(error_handle(7, wrongCommand), 84);

}

Test(Yams, pairTests)
{
    char *wrongPair_1[7] = {(char *)"./201yams", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"pair_21"};
    char *wrongPair_2[7] = {(char *)"./201yams", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"pair_a"};
    char *goodPair[7] = {(char *)"./201yams", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"pair_2"};

    cr_assert_eq(error_handle(7, wrongPair_1), 84);
    cr_assert_eq(error_handle(7, wrongPair_2), 84);
    cr_assert_eq(error_handle(7, goodPair), 0);
}

Test(Yams, threeTests)
{
    char *wrongThree_1[7] = {(char *)"./201yams", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"three_21"};
    char *wrongThree_2[7] = {(char *)"./201yams", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"three_a"};
    char *goodThree_3[7] = {(char *)"./201yams", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"three_2"};

    cr_assert_eq(error_handle(7, wrongThree_1), 84);
    cr_assert_eq(error_handle(7, wrongThree_2), 84);
    cr_assert_eq(error_handle(7, goodThree_3), 0);
}

Test(Yams, fourTests)
{
    char *wrongFour_1[7] = {(char *)"./201yams", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"four_21"};
    char *wrongFour_2[7] = {(char *)"./201yams", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"four_a"};
    char *goodFour[7] = {(char *)"./201yams", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"four_2"};

    cr_assert_eq(error_handle(7, wrongFour_1), 84);
    cr_assert_eq(error_handle(7, wrongFour_2), 84);
    cr_assert_eq(error_handle(7, goodFour), 0);
}

Test(Yams, fullTests)
{
    char *wrongFull_1[7] = {(char *)"./201yams", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"full_2_31"};
    char *wrongFull_2[7] = {(char *)"./201yams", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"full_a_3"};
    char *wrongFull_3[7] = {(char *)"./201yams", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"full_2-3"};
    char *wrongFull_4[7] = {(char *)"./201yams", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"full_2_a"};
    char *wrongFull_5[7] = {(char *)"./201yams", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"full_2_2"};
    char *goodFull[7] = {(char *)"./201yams", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"full_2_3"};

    cr_assert_eq(error_handle(7, wrongFull_1), 84);
    cr_assert_eq(error_handle(7, wrongFull_2), 84);
    cr_assert_eq(error_handle(7, wrongFull_3), 84);
    cr_assert_eq(error_handle(7, wrongFull_4), 84);
    cr_assert_eq(error_handle(7, wrongFull_5), 84);
    cr_assert_eq(error_handle(7, goodFull), 0);
}

Test(Yams, straightTests)
{
    char *wrongStraight_1[7] = {(char *)"./201yams", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"straight_21"};
    char *wrongStraight_2[7] = {(char *)"./201yams", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"straight_a"};
    char *goodStraight[7] = {(char *)"./201yams", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"straight_6"};

    cr_assert_eq(error_handle(7, wrongStraight_1), 84);
    cr_assert_eq(error_handle(7, wrongStraight_2), 84);
    cr_assert_eq(error_handle(7, goodStraight), 0);
}

Test(Yams, yamsTest)
{
    char *wrongYams_1[7] = {(char *)"./201yams", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"yams_21"};
    char *wrongYams_2[7] = {(char *)"./201yams", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"yams_a"};
    char *goodYams[7] = {(char *)"./201yams", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"0", (char *)"yams_2"};

    cr_assert_eq(error_handle(7, wrongYams_1), 84);
    cr_assert_eq(error_handle(7, wrongYams_2), 84);
    cr_assert_eq(error_handle(7, goodYams), 0);
}