// Lab_6_2_iter.cpp
// < Мацун Софія >
// Лабораторна робота № 6.2
// Опрацювання одновимірних масивів ітераційними способами
// Варіант 19

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* r, const int size, const int Low, const int High);
void Print(int* r, const int size);
bool MaxOdd(int* r, const int size, int& max);

int main()
{
    srand((unsigned)time(NULL));    // ініціалізація генератора випадкових чисел

    const int n = 23;               
    int r[n];

    int Low = 4;
    int High = 68;

    Create(r, n, Low, High);
    Print(r, n);

    int max;
    if (MaxOdd(r, n, max))
        cout << "max odd = " << max << endl;
    else
        cout << "Непарних елементів немає" << endl;

    return 0;
}

// заповнення масиву випадковими числами з діапазону [Low; High]
void Create(int* r, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        r[i] = Low + rand() % (High - Low + 1);
}

// виведення елементів масиву в рядок
void Print(int* r, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << r[i];
    cout << endl;
}

// пошук найбільшого непарного елемента;
// повертає true, якщо непарний елемент знайдено, значення - у параметрі max
bool MaxOdd(int* r, const int size, int& max)
{
    bool found = false;
    for (int i = 0; i < size; i++)
        if (r[i] % 2 != 0 && (!found || r[i] > max))
        {
            max = r[i];
            found = true;
        }
    return found;
}
