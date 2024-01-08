#include <iostream>
#include <fstream>
#include <queue>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Відкриваємо файл для читання
    ifstream inputFile("input.txt");

    // Перевіряємо, чи вдалося відкрити файл
    if (!inputFile.is_open()) {
        cerr << "Не вдалося відкрити файл input.txt" << std::endl;
        return 1;
    }

    // Зчитуємо число C з клавіатури
    double C;
    cout << "Введіть число C: ";
    cin >> C;

    // Очікуємо, що файл містить дійсні числа, розділені пробілами
    double number;
    queue<double> lessThanCQueue;
    queue<double> greaterThanOrEqualCQueue;

    // Зчитуємо числа з файлу та розділяємо їх на дві черги
    while (inputFile >> number) {
        if (number < C) {
            lessThanCQueue.push(number);
        }
        else {
            greaterThanOrEqualCQueue.push(number);
        }
    }

    // Закриваємо файл
    inputFile.close();

    // Виводимо числа в консоль
    cout << "Числа менше за " << C << ": ";
    while (!lessThanCQueue.empty()) {
        cout << lessThanCQueue.front() << " ";
        lessThanCQueue.pop();
    }

    cout << "\nЧисла більше або рівні " << C << ": ";
    while (!greaterThanOrEqualCQueue.empty()) {
        cout << greaterThanOrEqualCQueue.front() << " ";
        greaterThanOrEqualCQueue.pop();
    }

    cout << "\n";

    return 0;
}
