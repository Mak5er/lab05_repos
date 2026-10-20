// UnitTest_05_4.cpp
// Рева Максим
// Модульний тест для функцій S0, S1, S2, S3, S4 (Лабораторна робота № 5.4)

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#define main lab_05_4_main
#include "../Lab_05_4.cpp"
#undef main

TEST_SUITE("UnitTest_05_4")
{
    TEST_CASE("Single term verification: K = 3, N = 3")
    {
        const double eps = 1e-7;
        const int K = 3;
        const int N = 3;
        double expected = (cos(3.0 / 2.0) + sin(2.0 * 3.0)) / (1.0 + sin(cos(3.0)));

        CHECK(S0(K, N) == doctest::Approx(expected).epsilon(eps));
        CHECK(S1(K, N, K) == doctest::Approx(expected).epsilon(eps));
        CHECK(S2(K, N, N) == doctest::Approx(expected).epsilon(eps));
        CHECK(S3(K, N, K, 0.0) == doctest::Approx(expected).epsilon(eps));
        CHECK(S4(K, N, N, 0.0) == doctest::Approx(expected).epsilon(eps));
    }

    TEST_CASE("Two terms: K = 3, N = 4")
    {
        const double eps = 1e-7;
        const int K = 3;
        const int N = 4;
        double t3 = (cos(3.0 / 2.0) + sin(2.0 * 3.0)) / (1.0 + sin(cos(3.0)));
        double t4 = (cos(4.0 / 2.0) + sin(2.0 * 4.0)) / (1.0 + sin(cos(4.0)));
        double expected = t3 + t4;

        CHECK(S0(K, N) == doctest::Approx(expected).epsilon(eps));
        CHECK(S1(K, N, K) == doctest::Approx(expected).epsilon(eps));
        CHECK(S2(K, N, N) == doctest::Approx(expected).epsilon(eps));
        CHECK(S3(K, N, K, 0.0) == doctest::Approx(expected).epsilon(eps));
        CHECK(S4(K, N, N, 0.0) == doctest::Approx(expected).epsilon(eps));
    }

    TEST_CASE("Five terms consistency: K = 3, N = 7 (All 5 methods match)")
    {
        const double eps = 1e-7;
        const int K = 3;
        const int N = 7;

        double s0 = S0(K, N);
        double s1 = S1(K, N, K);
        double s2 = S2(K, N, N);
        double s3 = S3(K, N, K, 0.0);
        double s4 = S4(K, N, N, 0.0);

        CHECK(s1 == doctest::Approx(s0).epsilon(eps));
        CHECK(s2 == doctest::Approx(s0).epsilon(eps));
        CHECK(s3 == doctest::Approx(s0).epsilon(eps));
        CHECK(s4 == doctest::Approx(s0).epsilon(eps));
    }

    TEST_CASE("Edge case: N < K (empty sum returns 0)")
    {
        const int K = 3;
        const int N = 2;

        CHECK(S0(K, N) == 0.0);
        CHECK(S1(K, N, K) == 0.0);
        CHECK(S2(K, N, N) == 0.0);
        CHECK(S3(K, N, K, 0.0) == 0.0);
        CHECK(S4(K, N, N, 0.0) == 0.0);
    }
}
