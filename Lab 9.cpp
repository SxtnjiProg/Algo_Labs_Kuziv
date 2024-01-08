#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Функція генерування випадкових чисел у заданому діапазоні
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Функція для бульбашкового сортування в масиві
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements if they are in the wrong order
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Функція для виконання інтерполяційного пошуку в масиві
int interpolationSearch(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high && key >= arr[low] && key <= arr[high]) {
        // Використовуйте формулу інтерполяційного пошуку
        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (key - arr[low]);

        if (arr[pos] == key) {
            return pos; // Ключ знайдено
        }

        if (arr[pos] < key) {
            low = pos + 1;
        }
        else {
            high = pos - 1;
        }
    }

    return -1; // Ключ не знайдено
}

int main() {
    srand(time(0));

    int K = 15;
    int N = static_cast<int>(20 + 0.6 * K);

    int arr[N];


    for (int i = 0; i < N; i++) {
        arr[i] = generateRandomNumber(10, 100);
    }

    cout << "Original array: ";
    printArray(arr, N);

    // Виконайте спливаюче сортування в масиві
    bubbleSort(arr, N);

    cout << "Sorted array: ";
    printArray(arr, N);

    // Знайти ключ в середині лівої частини масиву
    int middleLeftKey = arr[N / 4];

    cout << "Key in the middle of the left part of the array: " << middleLeftKey << endl;

    // Виконайте інтерполяційний пошук, щоб знайти індекс ключа
    int result = interpolationSearch(arr, N, middleLeftKey);

    if (result != -1) {
        cout << "Key found at index: " << result << endl;
    }
    else {
        cout << "Key not found." << endl;
    }

    return 0;
}
