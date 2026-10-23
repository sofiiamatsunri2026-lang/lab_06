// Lab_6_1.cpp
// Мацун Софія
// Лабораторна робота № 6.1
// Пошук елементів одновимірного масиву рекурсивним способом
// Варіант 19

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* r, const int size, const int Low, const int High, int i)
{
    r[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(r, size, Low, High, i + 1);
}

void Print(int* r, const int size, int i)
{
    cout << setw(4) << r[i];
    if (i < size - 1)
        Print(r, size, i + 1);
    else
        cout << endl;
}

// критерій: усі, крім парних або кратних 13, тобто непарні й не кратні 13
int Count(int* r, const int size, int i)
{
    if (i < size)
    {
        if (r[i] % 2 != 0 && r[i] % 13 != 0)
            return 1 + Count(r, size, i + 1);
        else
            return Count(r, size, i + 1);
    }
    else
        return 0;
}

int Sum(int* r, const int size, int i)
{
    if (i < size)
    {
        if (r[i] % 2 != 0 && r[i] % 13 != 0)
            return r[i] + Sum(r, size, i + 1);
        else
            return Sum(r, size, i + 1);
    }
    else
        return 0;
}

void Zero(int* r, const int size, int i)
{
    if (r[i] % 2 != 0 && r[i] % 13 != 0)
        r[i] = 0;
    if (i < size - 1)
        Zero(r, size, i + 1);
}

int main()
{
    srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел

    const int n = 23;
    int r[n];

    const int Low = 4;
    const int High = 68;

    Create(r, n, Low, High, 0);
    Print(r, n, 0);

    cout << "k = " << Count(r, n, 0) << endl;
    cout << "S = " << Sum(r, n, 0) << endl;

    Zero(r, n, 0);
    Print(r, n, 0);

    return 0;
}