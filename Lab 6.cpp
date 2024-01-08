﻿#include <iostream>
#include <cstdlib> 

const int arraySize = 5; // Розмір масиву

// Функція для заповнення масиву випадковими числами в діапазоні від 10 до 100
void fillArray(int A[]) {
    for (int i = 0; i < arraySize; ++i) {
        A[i] = rand() % 91 + 10; // Випадкове число від 10 до 100
    }
}

// Функція для виведення масиву на екран
void printArray(int A[]) {
    for (int i = 0; i < arraySize; ++i) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

// Функція для сортування масиву методом бульбашки 
void bubbleSort(int A[]) {
    for (int i = 0; i < arraySize - 1; ++i) {
        for (int j = 0; j < arraySize - i - 1; ++j) {
            if (A[j] > A[j + 1]) {
                // Міняємо місцями елементи, якщо вони стоять у неправильному порядку
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

// Функція для сортування масиву методом вставки
void insertionSort(int A[]) {
    for (int i = 1; i < arraySize; ++i) {
        int key = A[i];
        int j = i - 1;

        // Зміщуємо всі більші елементи вправо
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            --j;
        }
        A[j + 1] = key;
    }
}

int main() {
    int A[arraySize];

    // Заповнюємо та виводимо початковий масив
    std::cout << "Початковий масив: ";
    fillArray(A);
    printArray(A);

    // Сортуємо масив бульбашкою та виводимо результат
    std::cout << "Масив після сортування бульбашкою: ";
    bubbleSort(A);
    printArray(A);

    // Заповнюємо та виводимо початковий масив
    fillArray(A);
    std::cout << "Початковий масив: ";
    printArray(A);

    // Сортуємо масив методом вставки та виводимо результат
    std::cout << "Масив після сортування методом вставки: ";
    insertionSort(A);
    printArray(A);

    return 0;
}
