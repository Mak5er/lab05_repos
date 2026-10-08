// UnitTest_05_1.cpp
// Рева Максим
// Модульний тест для функції g(a, b)

#include <iostream>
#include <cassert>
#include <cmath>

// Прототип тестованої функції
double g(const double a, const double b);

double g(const double a, const double b)
{
    return (a * b) / (a * a + b * b);
}

void test_g()
{
    const double eps = 1e-5;
    
    // Тест 1: a = 2, b = 1 => 2 / (4 + 1) = 0.4
    assert(std::abs(g(2, 1) - 0.4) < eps);
    std::cout << "Test 1 passed: g(2, 1) == 0.4" << std::endl;

    // Тест 2: a = 1, b = 1 => 1 / (1 + 1) = 0.5
    assert(std::abs(g(1, 1) - 0.5) < eps);
    std::cout << "Test 2 passed: g(1, 1) == 0.5" << std::endl;

    // Тест 3: a = 0, b = 5 => 0 / 25 = 0.0
    assert(std::abs(g(0, 5) - 0.0) < eps);
    std::cout << "Test 3 passed: g(0, 5) == 0.0" << std::endl;

    // Тест 4: a = 3, b = 4 => 12 / (9 + 16) = 0.48
    assert(std::abs(g(3, 4) - 0.48) < eps);
    std::cout << "Test 4 passed: g(3, 4) == 0.48" << std::endl;

    // Тест 5: a = -1, b = 1 => -1 / 2 = -0.5
    assert(std::abs(g(-1, 1) - (-0.5)) < eps);
    std::cout << "Test 5 passed: g(-1, 1) == -0.5" << std::endl;

    std::cout << "\nAll Unit Tests passed successfully!" << std::endl;
}

int main()
{
    std::cout << "Running Unit Tests for Lab_05_1 (function g)..." << std::endl;
    test_g();
    return 0;
}
