// Lab_05_2.cpp
// Рева Максим
// Лабораторна робота № 5.2
// Обчислення суми ряду Тейлора за допомогою функцій
// Варіант 23

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void S(const double x, const double eps, int &n, double &s);
void A(const double x, const int n, double &a);

int main()
{
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;

    cout << "xp = ";
    cin >> xp;
    cout << "xk = ";
    cin >> xk;
    cout << "dx = ";
    cin >> dx;
    cout << "eps = ";
    cin >> eps;

    cout << fixed;
    cout << "\n+----------+--------------+--------------+--------+" << endl;
    cout << "|    x     |   exp(x^2)   |      S       |   n    |" << endl;
    cout << "+----------+--------------+--------------+--------+" << endl;

    x = xp;
    while (x <= xk + dx / 2)
    {
        S(x, eps, n, s);

        cout << "| " << setw(8) << setprecision(2) << x << " | "
             << setw(12) << setprecision(5) << exp(x * x) << " | "
             << setw(12) << setprecision(5) << s << " | "
             << setw(6) << n << " |"
             << endl;
        x += dx;
    }
    cout << "+----------+--------------+--------------+--------+" << endl;

    return 0;
}

void S(const double x, const double eps, int &n, double &s)
{
    n = 0;
    double a = 1.0;
    s = a;

    do
    {
        n++;
        A(x, n, a);
        s += a;
    } while (abs(a) >= eps && n < 100000);
}

void A(const double x, const int n, double &a)
{
    double R = (x * x) / n;
    a *= R;
}
