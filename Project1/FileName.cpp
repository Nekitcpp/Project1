#include <iostream>
#include <Windows.h>

bool LeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Days(int d, int m, int y)
{
    int days = 0;

    for (int i = 1; i < y; i++)
    {
        if (LeapYear(i))
            days += 366;
        else
            days += 365;
    }

    int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    for (int i = 1; i < m; i++)
        days += months[i - 1];

    if (m > 2 && LeapYear(y))
        days += 1;

    days += d;
    return days;
}

int Difference(int d1, int m1, int y1, int d2, int m2, int y2)
{
    int a = Days(d1, m1, y1);
    int b = Days(d2, m2, y2);

    if (a > b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }

    return b - a;
}

double average(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];

    return (double)sum / size;
}

void Elements(int arr[], int size, int& positive, int& negative, int& zeros)
{
    positive = 0;
    negative = 0;
    zeros = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0)
            positive++;
        else if (arr[i] < 0)
            negative++;
        else
            zeros++;
    }
}

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
    // Задание 1
    int d1, m1, y1, d2, m2, y2;
    std::cout << "Задание 1." << std::endl;
    std::cout << "Введите первую дату (день месяц год): ";
    std::cin >> d1 >> m1 >> y1;
    std::cout << "Введите вторую дату (день месяц год): ";
    std::cin >> d2 >> m2 >> y2;

    std::cout << "Разница между датами: " << Difference(d1, m1, y1, d2, m2, y2)
        << " дн." << std::endl;

    // Задание 2
    const int size = 10;
    int arr[size] = { 5, -3, 0, 12, -8, 7, 0, 4, -1, 9 };

    std::cout << "\nЗадание 2." << std::endl;
    std::cout << "Массив: ";
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    std::cout << "Среднее арифметическое: " << average(arr, size) << std::endl;

    // Задание 3
    std::cout << "\nЗадание 3." << std::endl;
    int positive, negative, zeros;
    Elements(arr, size, positive, negative, zeros);
    std::cout << "Положительных: " << positive << std::endl;
    std::cout << "Отрицательных: " << negative << std::endl;
    std::cout << "Нулевых: " << zeros << std::endl;

    return 0;
}