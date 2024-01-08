#include <iostream>
#include <cstdlib> // Для функцій роботи з випадковими числами
#include <ctime>   // Для ініціалізації генератора випадкових чисел зі системного часу

int main() {
    const int size = 14;
    int array[size];

    // Ініціалізуємо генератор випадкових чисел зі системного часу
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Заповнюємо масив 
    for (int i = 0; i < size; ++i) {
        array[i] = std::rand() % 201 - 100; // Генеруємо випадкове число
    }

    int negativeElementIndex = -1;
    int sum = 0;
    int count = 0;

    // Знаходимо індекс першого від'ємного числа
    for (int i = 0; i < size; ++i) {
        if (array[i] < 0) {
            negativeElementIndex = i;
            break;
        }
    }

    // Обчислюємо суму та кількість елементів до першого від'ємного числа
    for (int i = 0; i < negativeElementIndex; ++i) {
        sum += array[i];
        count++;
    }

    // Виводимо масив і результати
    std::cout << "Масив: ";
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Сума елементів до першого від'ємного: " << sum << std::endl;
    std::cout << "Кількість елементів до першого від'ємного: " << count << std::endl;

    return 0;
