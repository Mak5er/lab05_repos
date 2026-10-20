// UnitTest_05_5.cpp
// Рева Максим
// Модульний тест для рекурсивної функції power (Лабораторна робота № 5.5)

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#define main lab_05_5_main
#include "../Lab_05_5.cpp"
#undef main

TEST_SUITE("UnitTest_05_5")
{
    TEST_CASE("Base case: p = 0, power should be 1, depth = 1")
    {
        int depth = 0;
        long long res = power(5, 0, 1, depth, false);
        CHECK(res == 1);
        CHECK(depth == 1);
    }

    TEST_CASE("Single step: b = 2, p = 1")
    {
        int depth = 0;
        long long res = power(2, 1, 1, depth, false);
        CHECK(res == 2);
        CHECK(depth == 2);
    }

    TEST_CASE("Even power: b = 2, p = 10 => 1024, depth = 5")
    {
        int depth = 0;
        long long res = power(2, 10, 1, depth, false);
        CHECK(res == 1024);
        CHECK(depth == 5); // p = 10, 5, 2, 1, 0 => 5 levels

        int m = 7;
        CHECK((res % m) == 2);
    }

    TEST_CASE("Odd power: b = 3, p = 5 => 243, depth = 4")
    {
        int depth = 0;
        long long res = power(3, 5, 1, depth, false);
        CHECK(res == 243);
        CHECK(depth == 4); // p = 5, 2, 1, 0 => 4 levels

        int m = 11;
        CHECK((res % m) == 1);
    }

    TEST_CASE("Power of 2 exponent: b = 5, p = 4 => 625, depth = 4")
    {
        int depth = 0;
        long long res = power(5, 4, 1, depth, false);
        CHECK(res == 625);
        CHECK(depth == 4); // p = 4, 2, 1, 0 => 4 levels

        int m = 13;
        CHECK((res % m) == 1);
    }

    TEST_CASE("Negative base: b = -2, p = 3 => -8, depth = 3")
    {
        int depth = 0;
        long long res = power(-2, 3, 1, depth, false);
        CHECK(res == -8);
        CHECK(depth == 3); // p = 3, 1, 0 => 3 levels
    }
}
