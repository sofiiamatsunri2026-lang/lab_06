// lab_06_3_iter.cpp
// < Мацун Софія >
// Лабораторна робота № 6.3
// Опрацювання одновимірних масивів за допомогою звичайних функцій та шаблонів
// Ітераційний спосіб
// Варіант 19

#include <iostream>

using namespace std;

int CountPositive(int* a, const int size);

template <typename T>
int CountPositive(T* a, const int size);

int main()
{
    const int n = 10;

    int a[n] = { 1, -2, 3, 0, -5, 6, 7, -8, 9, -10 };
    int k1 = CountPositive(a, n);
    cout << "CountPositive(a, n) = " << k1 << endl;

    int k2 = CountPositive<int>(a, n);
    cout << "CountPositive<int>(a, n) = " << k2 << endl;

    double b[n] = { 1.1, -2.2, 3.3, 0.0, -5.5, 6.6, 7.7, -8.8, 9.9, -10.0 };
    int k3 = CountPositive<double>(b, n);
    cout << "CountPositive<double>(b, n) = " << k3 << endl;

    return 0;
}

// кількість додатних елементів масиву цілих чисел
int CountPositive(int* a, const int size)
{
    int k = 0;
    for (int i = 0; i < size; i++)
        if (a[i] > 0)
            k++;
    return k;
}

// кількість додатних елементів масиву чисел довільного типу
template <typename T>
int CountPositive(T* a, const int size)
{
    int k = 0;
    for (int i = 0; i < size; i++)
        if (a[i] > T())     // T() - нульове значення типу T
            k++;
    return k;
}
