#include <iostream>

// Функція для пошуку першого входження масиву P у масив S
int findFirstOccurrence(int S[], int n, int P[], int m) {
    for (int i = 0; i <= n - m; ++i) {
        bool found = true;
        for (int j = 0; j < m; ++j) {
            if (S[i + j] != P[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            return i; // Перший знайдений випадок, повернути індекс
        }
    }
    return -1; // Перший випадок не знайдено
}

int main() {
    const int n = 10;
    const int m = 5;

    int S[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int P[m] = { 4, 5, 6, 7, 8 };

    std::cout << "Array S: ";
    for (int i = 0; i < n; ++i) {
        std::cout << S[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Array P: ";
    for (int i = 0; i < m; ++i) {
        std::cout << P[i] << " ";
    }
    std::cout << std::endl;

    int result = findFirstOccurrence(S, n, P, m);

    if (result != -1) {
        std::cout << "Перше входження масиву P в масив S знаходиться за індексом: " << result << std::endl;
    }
    else {
        std::cout << "Масив P не знайдено в масиві S." << std::endl;
    }

    return 0;
}
