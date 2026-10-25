// lab_06_4_iter.cpp
// < Мацун Софія >
// Лабораторна робота № 6.4
// Опрацювання та впорядкування одновимірних динамічних масивів
// Ітераційний спосіб
// Варіант 19

#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>

using namespace std;

void Create(double* a, const int size, const int Low, const int High);
void Print(double* a, const int size);
int CountNegative(double* a, const int size);
double ProductNegative(double* a, const int size);
int MaxIndex(double* a, const int size);
double SumPositiveBefore(double* a, const int end);
bool IsEven(double x);
void ReverseEven(double* a, const int size);

int main()
{
    srand((unsigned)time(NULL));    

    int n;
    cout << "n = ";
    cin >> n;

    double* a = new double[n];      // динамічний масив

    int Low = -10;
    int High = 10;

    Create(a, n, Low, High);
    Print(a, n);

    if (CountNegative(a, n) > 0)
        cout << "product of negative = " << ProductNegative(a, n) << endl;
    else
        cout << "no negative elements" << endl;

    int imax = MaxIndex(a, n);
    cout << "sum of positive before max = " << SumPositiveBefore(a, imax) << endl;

    ReverseEven(a, n);
    Print(a, n);

    delete[] a;                     // знищили динамічний масив

    return 0;
}

// заповнення масиву значеннями з діапазону [Low; High]
void Create(double* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

// виведення елементів масиву в рядок
void Print(double* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

// кількість від'ємних елементів
int CountNegative(double* a, const int size)
{
    int k = 0;
    for (int i = 0; i < size; i++)
        if (a[i] < 0)
            k++;
    return k;
}

// добуток від'ємних елементів
double ProductNegative(double* a, const int size)
{
    double p = 1;
    for (int i = 0; i < size; i++)
        if (a[i] < 0)
            p *= a[i];
    return p;
}

// індекс (першого) максимального елемента
int MaxIndex(double* a, const int size)
{
    int imax = 0;
    for (int i = 1; i < size; i++)
        if (a[i] > a[imax])
            imax = i;
    return imax;
}

// сума додатних елементів, розташованих до елемента з індексом end
double SumPositiveBefore(double* a, const int end)
{
    double s = 0;
    for (int i = 0; i < end; i++)
        if (a[i] > 0)
            s += a[i];
    return s;
}

// чи є число парним (парне ціле число)
bool IsEven(double x)
{
    return fmod(x, 2) == 0;
}

// зміна порядку розміщення парних елементів на зворотний;
// решта елементів залишаються на своїх місцях
void ReverseEven(double* a, const int size)
{
    int i = 0;
    int j = size - 1;
    while (i < j)
    {
        if (!IsEven(a[i]))
            i++;
        else if (!IsEven(a[j]))
            j--;
        else
        {
            double tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    }
}