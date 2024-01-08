#include <iostream>

// Функція для обчислення функції префікса для масиву P
void computeLPSArray(char P[], int m, int lps[]) {
    int len = 0;
    lps[0] = 0;  // Перший елемент завжди дорівнює 0

    for (int i = 1; i < m; ) {
        if (P[i] == P[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Функція для пошуку першого входження масиву P в масив S за допомогою алгоритму KMP
int KMPSearch(char S[], int n, char P[], int m) {
    int lps[m];
    computeLPSArray(P, m, lps);

    int i = 0;  // Index for array S
    int j = 0;  // Index for array P

    while (i < n) {
        if (P[j] == S[i]) {
            i++;
            j++;
        }

        if (j == m) {
            return i - j;  // Знайдено збіг, повернути початковий індекс
        }
        else if (i < n && P[j] != S[i]) {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }

    return -1;
}

int main() {
    const int n = 10;
    const int m = 5;

    char S[n + 1] = "zxcvbnmlkj";
    char P[m + 1] = "vbnml";

    std::cout << "Array S: " << S << std::endl;
    std::cout << "Array P: " << P << std::endl;

    int result = KMPSearch(S, n, P, m);

    if (result != -1) {
        std::cout << "Перше входження слова P у тексті S знаходиться за індексом: " << result << std::endl;
    }
    else {
        std::cout << "Слово P не знайдено в тексті S." << std::endl;
    }

    return 0;
}
