// Lab_05_3.cpp
// Рева Максим
// Лабораторна робота № 5.3
// Функції, що містять розгалуження та цикли з рекурентними співвідношеннями
// Варіант 23

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double j(const double x);

int main()
{
    double kp, kk, z;
    int n;

    cout << "kp = "; cin >> kp;
    cout << "kk = "; cin >> kk;
    cout << "n  = "; cin >> n;

    double dk = (kk - kp) / n;
    double k = kp;

    cout << fixed;
    cout << "--------------------------------" << endl;
    cout << "|" << setw(7)  << "k" << "     |"
         << setw(12) << "z" << "       |" << endl;
    cout << "--------------------------------" << endl;

    while (k <= kk + dk / 2)
    {
        z = j(1 + k + j(k)) + pow(j(1 + k * k), 2);

        cout << "|" << setw(9) << setprecision(2) << k << "   |"
             << setw(16) << setprecision(5) << z << "   |" << endl;

        k += dk;
    }
    cout << "--------------------------------" << endl;

    return 0;
}

double j(const double x)
{
    if (abs(x) >= 1)
        return (cos(x) + exp(-abs(x))) / (cos(x * x) + 1);
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
