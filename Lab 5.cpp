#include <iostream>
#include <stack>
#include <cstdlib> 
#include <ctime>   
#include <Windows.h>
using namespace std;

void fillArrayRandomly(int arr[], int N) {
    srand(time(0)); // Ініціалізація генератора випадкових чисел за поточним часом

    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 100; // Заповнюємо елементи випадковими числами від 0 до 99
    }
}

void reverseArray(int arr[], int N) {
    stack<int> s;

    // Додаємо елементи масиву у стек
    for (int i = 0; i < N; i++) {
        s.push(arr[i]);
    }

    // Виділяємо елементи зі стеку та поміщаємо назад у масив
    for (int i = 0; i < N; i++) {
        arr[i] = s.top();
        s.pop();
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int N = 5; // Розмір масиву (заміни на власний розмір)

    int arr[N];

    // Заповнюємо масив випадковими числами
    fillArrayRandomly(arr, N);

    // Виводимо початковий масив
    cout << "Початковий масив: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }

    // Розташовуємо елементи у зворотньому порядку
    reverseArray(arr, N);

    // Виводимо зворотній масив
    cout << "\nМасив у зворотньому порядку: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
