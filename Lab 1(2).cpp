#include <iostream>
#include <cstdlib> 
#include <ctime>   

int main() {
    const int rows = 5;
    const int cols = 7;
    int array[rows][cols];

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int sumOfAbsoluteNegatives = 0; // Змінна для зберігання суми абсолютних значень від'ємних елементів


    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = std::rand() % 201 - 100;

            if (array[i][j] < 0) {
                sumOfAbsoluteNegatives += std::abs(array[i][j]); // Додаємо абсолютне значення від'ємного числа до суми
            }
        }
    }

    // Виводимо масив на екран
    std::cout << "Масив:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;

    }
    // Виводимо суму абсолютних від'ємних чисел
    std::cout << "Сума абсолютних значень від'ємних елементів: " << sumOfAbsoluteNegatives << std::endl;


    return 0;
}
