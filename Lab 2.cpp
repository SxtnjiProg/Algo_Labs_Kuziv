#include <iostream>

int main() {
    const int N = 15;
    int array[N];

    // Заповнюємо масив прикладовими значеннями 

    for (int i = 0; i < N; ++i) {
        array[i] = i % 2 == 0 ? i * 2 : i * 2 + 1;
    }


    std::cout << "Масив:" << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    // Знайдемо кількість непарних чисел
    int oddCount = 0;
    for (int i = 0; i < N; ++i) {
        if (array[i] % 2 != 0) {
            oddCount++;
        }
    }

    // Розмірність для динамічного масиву непарних чисел
    const int oddArraySize = oddCount;


    // Виділимо пам'ять для динамічного масиву непарних чисел
    int* oddNumbers = new int[oddArraySize];

    // Заповнимо динамічний масив непарними числами
    int currentIndex = 0;
    for (int i = 0; i < N; ++i) {
        if (array[i] % 2 != 0) {
            oddNumbers[currentIndex] = array[i];
            currentIndex++;
        }
    }

    // Роздрукуємо динамічний масив непарних чисел
    std::cout << "Непарні числа:" << std::endl;
    for (int i = 0; i < oddArraySize; ++i) {
        std::cout << oddNumbers[i] << " ";
    }
    std::cout << std::endl;

    // Звільнимо виділену пам'ять
    delete[] oddNumbers;

    return 0;
}
