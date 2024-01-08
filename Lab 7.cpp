#include <iostream>
#include <vector>
#include <ctime> 
#include <cstdlib>

using namespace std;

// Функція для виведення вектора на екран
void printVector(const vector<int>& vec) {
    for (int value : vec) {
        cout << value << " ";
    }
    cout << endl;
}

// Метод сортування Шелла
void shellSort(vector<int>& vec) {
    int n = vec.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = vec[i];
            int j;
            for (j = i; j >= gap && vec[j - gap] > temp; j -= gap) {
                vec[j] = vec[j - gap];
            }
            vec[j] = temp;
        }
    }
}

int main() {
    const int size = 6;
    vector<int> vec(size);

    // Заповнення вектора випадковими числами в діапазоні від 10 до 100
    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < size; i++) {
        vec[i] = rand() % 91 + 10; // генерує числа від 10 до 100
    }

    cout << "Початковий вектор: ";
    printVector(vec);

    // Виклик сортування Шелла
    shellSort(vec);

    cout << "Відсортований вектор: ";
    printVector(vec);

    return 0;
}
