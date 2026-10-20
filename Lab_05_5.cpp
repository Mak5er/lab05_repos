// Lab_05_5.cpp
// Рева Максим
// Лабораторна робота № 5.5
// Рекурсивні функції. Двійкове піднесення до степеня.
// Варіант 23

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Прототип рекурсивної функції з визначенням рівня та глибини рекурсії
long long power(const int b, const int p, int level, int &depth, bool printTrace = true);

#ifndef UNIT_TEST
int main()
{
    int b, p, m;

    cout << "Введіть основу степеня b: ";
    cin >> b;
    cout << "Введіть показник степеня p (p >= 0): ";
    cin >> p;
    cout << "Введіть модуль m (m > 0): ";
    cin >> m;

    if (p < 0)
    {
        cout << "Помилка: показник степеня p не може бути від'ємним!" << endl;
        return 1;
    }
    if (m <= 0)
    {
        cout << "Помилка: модуль m має бути додатним числом!" << endl;
        return 1;
    }

    int depth = 0;
    cout << "\n--- Протокол рекурсивних викликів (рекурсивний спуск) ---" << endl;
    long long b_pow_p = power(b, p, 1, depth, true);

    // Обчислення значення виразу b^p mod m
    long long res_mod = (b_pow_p % m + m) % m;

    // Контрольна перевірка ітераційним методом
    long long control_pow = 1;
    for (int i = 0; i < p; i++)
        control_pow *= b;
    long long control_mod = (control_pow % m + m) % m;

    cout << "\n+------------------------------------+----------------+" << endl;
    cout << "| Параметр / Результат               |    Значення    |" << endl;
    cout << "+------------------------------------+----------------+" << endl;
    cout << "| Основа степеня b                   | " << setw(14) << b << " |" << endl;
    cout << "| Показник степеня p                 | " << setw(14) << p << " |" << endl;
    cout << "| Модуль m                           | " << setw(14) << m << " |" << endl;
    cout << "+------------------------------------+----------------+" << endl;
    cout << "| Обчислене значення b^p             | " << setw(14) << b_pow_p << " |" << endl;
    cout << "| Глибина рекурсії (depth)           | " << setw(14) << depth << " |" << endl;
    cout << "| Результат (b^p mod m)              | " << setw(14) << res_mod << " |" << endl;
    cout << "| Контрольне значення                | " << setw(14) << control_mod << " |" << endl;
    cout << "+------------------------------------+----------------+" << endl;

    return 0;
}
#endif

// Рекурсивна функція для швидкого бінарного піднесення до степеня
// з відстеженням поточного рівня та максимальної глибини рекурсії
long long power(const int b, const int p, int level, int &depth, bool printTrace)
{
    if (level > depth)
        depth = level;

    if (printTrace)
        cout << " [power] level = " << level << ", p = " << p << endl;

    // Базовий випадок (вихід з рекурсії)
    if (p == 0)
        return 1;

    // Рекурсивний виклик: зменшення задачі вдвічі (двійкове розкладання)
    long long half = power(b, p / 2, level + 1, depth, printTrace);

    // Обчислення результату на рекурсивному підйомі
    if (p % 2 == 0)
        return half * half;
    else
        return b * half * half;
}
