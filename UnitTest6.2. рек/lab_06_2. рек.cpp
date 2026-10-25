// lab_06_2_rec.cpp
// < Мацун Софія >
// Лабораторна робота № 6.2
// Опрацювання одновимірних масивів рекурсивними способами
// Варіант 19

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* r, const int size, const int Low, const int High, int i);
void Print(int* r, const int size, int i);
bool MaxOdd(int* r, const int size, int i, int& max);

int main()
{
    srand((unsigned)time(NULL));    

    const int n = 23;               
    int r[n];

    int Low = 4;
    int High = 68;

    Create(r, n, Low, High, 0);
    Print(r, n, 0);

    int max;
    if (MaxOdd(r, n, 0, max))
        cout << "max odd = " << max << endl;
    else
        cout << "Непарних елементів немає" << endl;

    return 0;
}

// заповнення масиву випадковими числами з діапазону [Low; High]
void Create(int* r, const int size, const int Low, const int High, int i)
{
    r[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(r, size, Low, High, i + 1);
}

// виведення елементів масиву в рядок
void Print(int* r, const int size, int i)
{
    cout << setw(4) << r[i];
    if (i < size - 1)
        Print(r, size, i + 1);
    else
        cout << endl;
}

// пошук найбільшого непарного елемента;
// повертає true, якщо непарний елемент знайдено, значення - у параметрі max
bool MaxOdd(int* r, const int size, int i, int& max)
{
    bool found = false;
    if (i < size - 1)
        found = MaxOdd(r, size, i + 1, max);   

    if (r[i] % 2 != 0 && (!found || r[i] > max))
    {
        max = r[i];
        found = true;
    }
    return found;
}