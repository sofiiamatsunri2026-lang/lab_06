// Lab_6_1.cpp
// Мацун Софія
// Лабораторна робота № 6.1
// Пошук елементів одновимірного масиву ітераційним способом
// Варіант 19

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

void Create(int* r, const int size, const int Low, const int High);
void Print(const int* r, const int size);
int Count(const int* r, const int size);
int Sum(const int* r, const int size);
void Zero(int* r, const int size);

int main()
{
    srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел

    const int n = 23;
    int r[n];

    const int Low = 4;
    const int High = 68;

    Create(r, n, Low, High);
    Print(r, n);

    cout << "k = " << Count(r, n) << endl;
    cout << "S = " << Sum(r, n) << endl;

    Zero(r, n);
    Print(r, n);

    return 0;
}

void Create(int* r, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        r[i] = Low + rand() % (High - Low + 1);
}

void Print(const int* r, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << r[i];
    cout << endl;
}

// критерій: усі, крім парних або кратних 13, тобто непарні й не кратні 13
int Count(const int* r, const int size)
{
    int k = 0;
    for (int i = 0; i < size; i++)
        if (!(r[i] % 2 == 0 || r[i] % 13 == 0))
            k++;
    return k;
}

int Sum(const int* r, const int size)
{
    int S = 0;
    for (int i = 0; i < size; i++)
        if (!(r[i] % 2 == 0 || r[i] % 13 == 0))
            S += r[i];
    return S;
}

void Zero(int* r, const int size)
{
    for (int i = 0; i < size; i++)
        if (!(r[i] % 2 == 0 || r[i] % 13 == 0))
            r[i] = 0;
}
