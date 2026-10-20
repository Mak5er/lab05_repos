// UnitTest_05_1.cpp
// Рева Максим
// Модульний тест для функції g(a, b)

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#define main lab_05_1_main
#include "../Lab_05_1.cpp"
#undef main

TEST_SUITE("UnitTest_05_1") {
    TEST_CASE("Test 1: a = 2, b = 1 => 2 / (4 + 1) = 0.4") {
        const double eps = 1e-5;
        CHECK(g(2, 1) == doctest::Approx(0.4).epsilon(eps));
    }

    TEST_CASE("Test 2: a = 1, b = 1 => 1 / (1 + 1) = 0.5") {
        const double eps = 1e-5;
        CHECK(g(1, 1) == doctest::Approx(0.5).epsilon(eps));
    }

    TEST_CASE("Test 3: a = 0, b = 5 => 0 / 25 = 0.0") {
        const double eps = 1e-5;
        CHECK(g(0, 5) == doctest::Approx(0.0).epsilon(eps));
    }

    TEST_CASE("Test 4: a = 3, b = 4 => 12 / (9 + 16) = 0.48") {
        const double eps = 1e-5;
        CHECK(g(3, 4) == doctest::Approx(0.48).epsilon(eps));
    }

    TEST_CASE("Test 5: a = -1, b = 1 => -1 / 2 = -0.5") {
        const double eps = 1e-5;
        CHECK(g(-1, 1) == doctest::Approx(-0.5).epsilon(eps));
    }
}
