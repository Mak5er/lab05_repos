// UnitTest_05_2.cpp
// Рева Максим
// Модульний тест для функцій S та A (Лабораторна робота № 5.2)

#include <iostream>
#include <cassert>
#include <cmath>

void S(const double x, const double eps, int &n, double &s);
void A(const double x, const int n, double &a);

void S(const double x, const double eps, int &n, double &s)
{
    n = 0;
    double a = 1.0;
    s = a;
    do {
        n++;
        A(x, n, a);
        s += a;
    } while (std::abs(a) >= eps);
}

void A(const double x, const int n, double &a)
{
    double R = (x * x) / n;
    a *= R;
}

void test_A()
{
    const double eps = 1e-7;
    double a = 1.0;

    // Тест 1: x = 2, n = 1 => R = 4/1 = 4 => a = 4
    A(2.0, 1, a);
    assert(std::abs(a - 4.0) < eps);
    std::cout << "Test A.1 passed: a = " << a << " == 4.0" << std::endl;

    // Тест 2: x = 2, n = 2 => R = 4/2 = 2 => a = 4 * 2 = 8
    A(2.0, 2, a);
    assert(std::abs(a - 8.0) < eps);
    std::cout << "Test A.2 passed: a = " << a << " == 8.0" << std::endl;

    // Тест 3: x = 1, n = 1, a = 1 => a = 1
    a = 1.0;
    A(1.0, 1, a);
    assert(std::abs(a - 1.0) < eps);
    std::cout << "Test A.3 passed: a = " << a << " == 1.0" << std::endl;

    // Тест 4: x = 0, n = 1, a = 1 => a = 0
    a = 1.0;
    A(0.0, 1, a);
    assert(std::abs(a - 0.0) < eps);
    std::cout << "Test A.4 passed: a = " << a << " == 0.0" << std::endl;
}

void test_S()
{
    const double eps = 1e-6;
    int n = 0;
    double s = 0.0;

    // Тест 1: x = 0, eps = 1e-5 => exp(0) = 1.0, n = 1
    S(0.0, 1e-5, n, s);
    assert(std::abs(s - 1.0) < eps);
    assert(n == 1);
    std::cout << "Test S.1 passed: S(0.0) == 1.0, n = " << n << std::endl;

    // Тест 2: x = 1.0, eps = 1e-6 => exp(1) = 2.7182818
    S(1.0, 1e-6, n, s);
    assert(std::abs(s - std::exp(1.0)) < eps);
    std::cout << "Test S.2 passed: S(1.0) == " << s << " (~= " << std::exp(1.0) << "), n = " << n << std::endl;

    // Тест 3: x = 0.5, eps = 1e-6 => exp(0.25) = 1.2840254
    S(0.5, 1e-6, n, s);
    assert(std::abs(s - std::exp(0.25)) < eps);
    std::cout << "Test S.3 passed: S(0.5) == " << s << " (~= " << std::exp(0.25) << "), n = " << n << std::endl;

    // Тест 4: x = -1.0, eps = 1e-6 => exp((-1)^2) = exp(1) = 2.7182818
    S(-1.0, 1e-6, n, s);
    assert(std::abs(s - std::exp(1.0)) < eps);
    std::cout << "Test S.4 passed: S(-1.0) == " << s << " (~= " << std::exp(1.0) << "), n = " << n << std::endl;
}

int main()
{
    std::cout << "Running Unit Tests for Lab_05_2 (functions A and S)..." << std::endl;
    test_A();
    test_S();
    std::cout << "\nAll Unit Tests for Lab_05_2 passed successfully!" << std::endl;
    return 0;
}
