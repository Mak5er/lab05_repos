// UnitTest_05_2.cpp
// Рева Максим
// Модульний тест для функцій S та A (Лабораторна робота № 5.2)

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#define main lab_05_2_main
#include "../Lab_05_2.cpp"
#undef main

TEST_SUITE("UnitTest_05_2")
{
    TEST_CASE("Function A - Test 1: x = 2, n = 1 => a = 4")
    {
        const double eps = 1e-7;
        double a = 1.0;
        A(2.0, 1, a);
        CHECK(a == doctest::Approx(4.0).epsilon(eps));
    }

    TEST_CASE("Function A - Test 2: x = 2, n = 2 => a = 8")
    {
        const double eps = 1e-7;
        double a = 4.0;
        A(2.0, 2, a);
        CHECK(a == doctest::Approx(8.0).epsilon(eps));
    }

    TEST_CASE("Function A - Test 3: x = 1, n = 1 => a = 1")
    {
        const double eps = 1e-7;
        double a = 1.0;
        A(1.0, 1, a);
        CHECK(a == doctest::Approx(1.0).epsilon(eps));
    }

    TEST_CASE("Function A - Test 4: x = 0, n = 1 => a = 0")
    {
        const double eps = 1e-7;
        double a = 1.0;
        A(0.0, 1, a);
        CHECK(a == doctest::Approx(0.0).epsilon(eps));
    }

    TEST_CASE("Function S - Test 1: x = 0.0 => exp(0) = 1.0, n = 1")
    {
        const double eps = 1e-6;
        int n = 0;
        double s = 0.0;
        S(0.0, 1e-5, n, s);
        CHECK(s == doctest::Approx(1.0).epsilon(eps));
        CHECK(n == 1);
    }

    TEST_CASE("Function S - Test 2: x = 1.0 => exp(1) ~= 2.71828")
    {
        const double eps = 1e-6;
        int n = 0;
        double s = 0.0;
        S(1.0, 1e-6, n, s);
        CHECK(s == doctest::Approx(std::exp(1.0)).epsilon(eps));
    }

    TEST_CASE("Function S - Test 3: x = 0.5 => exp(0.25) ~= 1.28403")
    {
        const double eps = 1e-6;
        int n = 0;
        double s = 0.0;
        S(0.5, 1e-6, n, s);
        CHECK(s == doctest::Approx(std::exp(0.25)).epsilon(eps));
    }

    TEST_CASE("Function S - Test 4: x = -1.0 => exp(1) ~= 2.71828")
    {
        const double eps = 1e-6;
        int n = 0;
        double s = 0.0;
        S(-1.0, 1e-6, n, s);
        CHECK(s == doctest::Approx(std::exp(1.0)).epsilon(eps));
    }
}
