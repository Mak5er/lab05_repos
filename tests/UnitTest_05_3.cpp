// UnitTest_05_3.cpp
// Рева Максим
// Модульний тест для функції j(x) (Лабораторна робота № 5.3)

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#define main lab_05_3_main
#include "../Lab_05_3.cpp"
#undef main

TEST_SUITE("UnitTest_05_3") {
    TEST_CASE("Function j - Test 1: |x| < 1, x = 0.0 => 0.0") {
        const double eps = 1e-5;
        double res = j(0.0);
        CHECK(res == doctest::Approx(0.0).epsilon(eps));
    }

    TEST_CASE("Function j - Test 2: |x| < 1, x = 0.5 => sinh(0.5)") {
        const double eps = 1e-5;
        double res = j(0.5);
        double expected = std::sinh(0.5);
        CHECK(res == doctest::Approx(expected).epsilon(eps));
    }

    TEST_CASE("Function j - Test 3: |x| < 1, x = -0.5 => -sinh(0.5)") {
        const double eps = 1e-5;
        double res = j(-0.5);
        double expected = -std::sinh(0.5);
        CHECK(res == doctest::Approx(expected).epsilon(eps));
    }

    TEST_CASE("Function j - Test 4: |x| >= 1, x = 1.0") {
        const double eps = 1e-5;
        double res = j(1.0);
        double expected = (std::cos(1.0) + std::exp(-1.0)) / (std::cos(1.0) + 1.0);
        CHECK(res == doctest::Approx(expected).epsilon(eps));
    }

    TEST_CASE("Function j - Test 5: |x| >= 1, x = -1.0 (symmetry)") {
        const double eps = 1e-5;
        double res = j(-1.0);
        double expected = (std::cos(1.0) + std::exp(-1.0)) / (std::cos(1.0) + 1.0);
        CHECK(res == doctest::Approx(expected).epsilon(eps));
    }

    TEST_CASE("Function j - Test 6: |x| >= 1, x = 2.0") {
        const double eps = 1e-5;
        double res = j(2.0);
        double expected = (std::cos(2.0) + std::exp(-2.0)) / (std::cos(4.0) + 1.0);
        CHECK(res == doctest::Approx(expected).epsilon(eps));
    }
}
