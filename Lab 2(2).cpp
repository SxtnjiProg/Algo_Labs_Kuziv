#include <iostream>

int main() {
    const int N = 6;
    double A[N][N];


    // Заповнюємо масив прикладовими значеннями  
    double value = 1.0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            A[i][j] = value;
            value += 1.0;
        }
    }

    // Роздрукуємо весь масив
    std::cout << "Масив:" << std::endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Виводимо елементи на побічній діагоналі та нижче неї
    std::cout << "Елементи на побічній діагоналі і нижче:" << std::endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
