// UnitTest_05_3.cpp
// Рева Максим
// Модульний тест для функції j(x) (Лабораторна робота № 5.3)

#include <iostream>
#include <cassert>
#include <cmath>

double j(const double x);

double j(const double x)
{
    if (std::abs(x) >= 1)
        return (std::cos(x) + std::exp(-std::abs(x))) / (std::cos(x * x) + 1);
    else
    {
        double S = 0;
        int i = 0;
        double a = x;
        S = a;
        do {
            i++;
            double R = (x * x) / ((2 * i) * (2 * i + 1));
            a *= R;
            S += a;
        } while (i < 5);
        return S;
    }
}

void test_j()
{
    const double eps = 1e-5;

    // Тест 1: |x| < 1, x = 0 => S = 0
    double res0 = j(0.0);
    assert(std::abs(res0 - 0.0) < eps);
    std::cout << "Test 1 passed: j(0.0) == " << res0 << " (~= 0.0)" << std::endl;

    // Тест 2: |x| < 1, x = 0.5 => sinh(0.5) ~= 0.521095
    double res05 = j(0.5);
    double expected05 = std::sinh(0.5);
    assert(std::abs(res05 - expected05) < eps);
    std::cout << "Test 2 passed: j(0.5) == " << res05 << " (~= " << expected05 << ")" << std::endl;

    // Тест 3: |x| < 1, x = -0.5 => -sinh(0.5) ~= -0.521095
    double res_neg05 = j(-0.5);
    double expected_neg05 = -std::sinh(0.5);
    assert(std::abs(res_neg05 - expected_neg05) < eps);
    std::cout << "Test 3 passed: j(-0.5) == " << res_neg05 << " (~= " << expected_neg05 << ")" << std::endl;

    // Тест 4: |x| >= 1, x = 1.0 => (cos(1) + exp(-1)) / (cos(1) + 1) ~= 0.589613
    double res1 = j(1.0);
    double expected1 = (std::cos(1.0) + std::exp(-1.0)) / (std::cos(1.0) + 1.0);
    assert(std::abs(res1 - expected1) < eps);
    std::cout << "Test 4 passed: j(1.0) == " << res1 << " (~= " << expected1 << ")" << std::endl;

    // Тест 5: |x| >= 1, x = -1.0 => симетричність відносно знаку
    double res_neg1 = j(-1.0);
    assert(std::abs(res_neg1 - expected1) < eps);
    std::cout << "Test 5 passed: j(-1.0) == " << res_neg1 << " (~= " << expected1 << ")" << std::endl;

    // Тест 6: |x| >= 1, x = 2.0 => (cos(2) + exp(-2)) / (cos(4) + 1) ~= -0.810759
    double res2 = j(2.0);
    double expected2 = (std::cos(2.0) + std::exp(-2.0)) / (std::cos(4.0) + 1.0);
    assert(std::abs(res2 - expected2) < eps);
    std::cout << "Test 6 passed: j(2.0) == " << res2 << " (~= " << expected2 << ")" << std::endl;

    std::cout << "\nAll Unit Tests for Lab_05_3 passed successfully!" << std::endl;
}

int main()
{
    std::cout << "Running Unit Tests for Lab_05_3 (function j)..." << std::endl;
    test_j();
    return 0;
}
