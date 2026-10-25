// lab_06_3_rec.cpp
// < Мацун Софія >
// Лабораторна робота № 6.3
// Опрацювання одновимірних масивів за допомогою звичайних функцій та шаблонів
// Рекурсивний спосіб
// Варіант 19

#include <iostream>

using namespace std;

int CountPositive(int* a, const int size, int i);

template <typename T>
int CountPositive(T* a, const int size, int i);

int main()
{
    const int n = 10;

    int a[n] = { 1, -2, 3, 0, -5, 6, 7, -8, 9, -10 };
    int k1 = CountPositive(a, n, 0);
    cout << "CountPositive(a, n) = " << k1 << endl;

    int k2 = CountPositive<int>(a, n, 0);
    cout << "CountPositive<int>(a, n) = " << k2 << endl;

    double b[n] = { 1.1, -2.2, 3.3, 0.0, -5.5, 6.6, 7.7, -8.8, 9.9, -10.0 };
    int k3 = CountPositive<double>(b, n, 0);
    cout << "CountPositive<double>(b, n) = " << k3 << endl;

    return 0;
}

// кількість додатних елементів масиву цілих чисел
int CountPositive(int* a, const int size, int i)
{
    if (i < size)
    {
        if (a[i] > 0)
            return 1 + CountPositive(a, size, i + 1);
        else
            return CountPositive(a, size, i + 1);
    }
    else
        return 0;
}

// кількість додатних елементів масиву чисел довільного типу
template <typename T>
int CountPositive(T* a, const int size, int i)
{
    if (i < size)
    {
        if (a[i] > T())     // T() - нульове значення типу T
            return 1 + CountPositive<T>(a, size, i + 1);
        else
            return CountPositive<T>(a, size, i + 1);
    }
    else
        return 0;
}