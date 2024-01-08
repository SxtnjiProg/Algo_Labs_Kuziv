#include <iostream>
#include <cstdlib>
#include <vector>

// Функція для виведення масиву на екран
void вивестиМасив(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Метод Швидкого сортування (алгоритм Хоара)
void швидке_сортування(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int опорний = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < опорний) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }

        std::swap(arr[i + 1], arr[high]);

        швидке_сортування(arr, low, i);
        швидке_сортування(arr, i + 2, high);
    }
}

// Об'єднати два впорядковані підмасиви для методу злиття
void злиття(std::vector<int>& arr, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    std::vector<int> лівий(n1), правий(n2);

    for (int i = 0; i < n1; i++)
        лівий[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        правий[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2) {
        if (лівий[i] <= правий[j]) {
            arr[k] = лівий[i];
            i++;
        }
        else {
            arr[k] = правий[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = лівий[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = правий[j];
        j++;
        k++;
    }
}

// Метод злиття
void злиття_сортування(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        злиття_сортування(arr, low, mid);
        злиття_сортування(arr, mid + 1, high);

        злиття(arr, low, mid, high);
    }
}

int main() {
    const int size = 6;
    std::vector<int> arr(size);

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 91 + 10; // Генерує числа від 10 до 100
    }

    std::cout << "Початковий масив: ";
    вивестиМасив(arr);

    // Копіюємо масив для обох методів сортування
    std::vector<int> arr1 = arr;

    // Сортування Хоара
    швидке_сортування(arr, 0, size - 1);
    std::cout << "Відсортований масив (Хоара): ";
    вивестиМасив(arr);

    // Сортування злиттям
    злиття_сортування(arr1, 0, size - 1);
    std::cout << "Відсортований масив (Злиття): ";
    вивестиМасив(arr1);
    return 0;
}

