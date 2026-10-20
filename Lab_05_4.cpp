// Lab_05_4.cpp
// Рева Максим
// Лабораторна робота № 5.4
// Обчислення сум та добутків за допомогою рекурсії
// Варіант 23

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Прототипи 5 функцій згідно з методичними вказівками
double S0(const int K, const int N);
double S1(const int K, const int N, const int i);
double S2(const int K, const int N, const int i);
double S3(const int K, const int N, const int i, double t);
double S4(const int K, const int N, const int i, double t);

#ifndef UNIT_TEST
int main()
{
    const int K = 3;
    int N;

    cout << "Введіть верхню межу суми N (N >= " << K << "): ";
    cin >> N;

    if (N < K)
    {
        cout << "Помилка: N має бути не меншим за " << K << "!" << endl;
        return 1;
    }

    double s0 = S0(K, N);
    double s1 = S1(K, N, K);
    double s2 = S2(K, N, N);
    double s3 = S3(K, N, K, 0.0);
    double s4 = S4(K, N, N, 0.0);

    cout << fixed << setprecision(7);
    cout << "\n+------------------------------------+----------------+" << endl;
    cout << "| Спосіб обчислення                  |   Результат    |" << endl;
    cout << "+------------------------------------+----------------+" << endl;
    cout << "| (iter)        S0                   | " << setw(14) << s0 << " |" << endl;
    cout << "| (rec up ++)   S1                   | " << setw(14) << s1 << " |" << endl;
    cout << "| (rec up --)   S2                   | " << setw(14) << s2 << " |" << endl;
    cout << "| (rec down ++) S3                   | " << setw(14) << s3 << " |" << endl;
    cout << "| (rec down --) S4                   | " << setw(14) << s4 << " |" << endl;
    cout << "+------------------------------------+----------------+" << endl;

    return 0;
}
#endif

// 1) Ітераційний спосіб (для контролю правильності рекурсивних способів)
double S0(const int K, const int N)
{
    double s = 0.0;
    for (int i = K; i <= N; i++)
        s += (cos(i / 2.0) + sin(2.0 * i)) / (1.0 + sin(cos(i)));
    return s;
}

// 2) Рекурсивний підйом, параметр зростає (i++)
double S1(const int K, const int N, const int i)
{
    if (i > N)
        return 0.0;
    else
        return (cos(i / 2.0) + sin(2.0 * i)) / (1.0 + sin(cos(i))) + S1(K, N, i + 1);
}

// 3) Рекурсивний підйом, параметр спадає (i--)
double S2(const int K, const int N, const int i)
{
    if (i < K)
        return 0.0;
    else
        return (cos(i / 2.0) + sin(2.0 * i)) / (1.0 + sin(cos(i))) + S2(K, N, i - 1);
}

// 4) Рекурсивний спуск, параметр зростає (i++)
double S3(const int K, const int N, const int i, double t)
{
    if (i > N)
        return t;
    t = t + (cos(i / 2.0) + sin(2.0 * i)) / (1.0 + sin(cos(i)));
    if (i >= N)
        return t;
    else
        return S3(K, N, i + 1, t);
}

// 5) Рекурсивний спуск, параметр спадає (i--)
double S4(const int K, const int N, const int i, double t)
{
    if (i < K)
        return t;
    t = t + (cos(i / 2.0) + sin(2.0 * i)) / (1.0 + sin(cos(i)));
    if (i <= K)
        return t;
    else
        return S4(K, N, i - 1, t);
}
