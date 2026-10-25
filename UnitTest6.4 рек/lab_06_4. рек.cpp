// lab_06_4_rec.cpp
// < Мацун Софія >
// Лабораторна робота № 6.4
// Опрацювання та впорядкування одновимірних динамічних масивів
// Рекурсивний спосіб
// Варіант 19

#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>

using namespace std;

void Create(double* a, const int size, const int Low, const int High, int i);
void Print(double* a, const int size, int i);
int CountNegative(double* a, const int size, int i);
double ProductNegative(double* a, const int size, int i);
int MaxIndex(double* a, const int size, int i, int imax);
double SumPositiveBefore(double* a, const int end, int i);
bool IsEven(double x);
void ReverseEven(double* a, int i, int j);

int main()
{
    srand((unsigned)time(NULL));    // ініціалізація генератора випадкових чисел

    int n;
    cout << "n = ";
    cin >> n;

    double* a = new double[n];      // динамічний масив

    int Low = -10;
    int High = 10;

    Create(a, n, Low, High, 0);
    Print(a, n, 0);

    if (CountNegative(a, n, 0) > 0)
        cout << "product of negative = " << ProductNegative(a, n, 0) << endl;
    else
        cout << "no negative elements" << endl;

    int imax = MaxIndex(a, n, 0, 0);
    cout << "sum of positive before max = " << SumPositiveBefore(a, imax, 0) << endl;

    ReverseEven(a, 0, n - 1);
    Print(a, n, 0);

    delete[] a;                     // знищили динамічний масив

    return 0;
}

// заповнення масиву значеннями з діапазону [Low; High]
void Create(double* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

// виведення елементів масиву в рядок
void Print(double* a, const int size, int i)
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

// кількість від'ємних елементів
int CountNegative(double* a, const int size, int i)
{
    if (i < size)
    {
        if (a[i] < 0)
            return 1 + CountNegative(a, size, i + 1);
        else
            return CountNegative(a, size, i + 1);
    }
    else
        return 0;
}

// добуток від'ємних елементів
double ProductNegative(double* a, const int size, int i)
{
    if (i < size)
    {
        if (a[i] < 0)
            return a[i] * ProductNegative(a, size, i + 1);
        else
            return ProductNegative(a, size, i + 1);
    }
    else
        return 1;
}

// індекс (першого) максимального елемента
int MaxIndex(double* a, const int size, int i, int imax)
{
    if (a[i] > a[imax])
        imax = i;
    if (i < size - 1)
        return MaxIndex(a, size, i + 1, imax);
    else
        return imax;
}

// сума додатних елементів, розташованих до елемента з індексом end
double SumPositiveBefore(double* a, const int end, int i)
{
    if (i < end)
    {
        if (a[i] > 0)
            return a[i] + SumPositiveBefore(a, end, i + 1);
        else
            return SumPositiveBefore(a, end, i + 1);
    }
    else
        return 0;
}

// чи є число парним (парне ціле число)
bool IsEven(double x)
{
    return fmod(x, 2) == 0;
}

// зміна порядку розміщення парних елементів на зворотний;
// i, j - індекси, між якими шукаємо парні елементи
void ReverseEven(double* a, int i, int j)
{
    if (i < j)
    {
        if (!IsEven(a[i]))
            ReverseEven(a, i + 1, j);
        else if (!IsEven(a[j]))
            ReverseEven(a, i, j - 1);
        else
        {
            double tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            ReverseEven(a, i + 1, j - 1);
        }
    }
}