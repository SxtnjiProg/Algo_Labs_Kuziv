#include <iostream>
#include <climits>
#include <Windows.h>
using namespace std;
// Визначення вузла бінарного дерева
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Функція для знаходження максимального елемента та кількості його повторень у бінарному дереві
void findMaxElementAndCount(TreeNode* root, int& maxElement, int& count) {
    if (root != nullptr) {
        // Рекурсивно обчислюємо для лівого піддерева
        findMaxElementAndCount(root->left, maxElement, count);

        // Обробка поточного вузла
        if (root->data > maxElement) {
            maxElement = root->data;
            count = 1;  // Знайшли новий максимальний елемент, оновлюємо кількість
        }
        else if (root->data == maxElement) {
            count++;  // Збільшуємо кількість повторень максимального елемента
        }

        // Рекурсивно обчислюємо для правого піддерева
        findMaxElementAndCount(root->right, maxElement, count);
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Створюємо бінарне дерево для тестування
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(52);
    root->right = new TreeNode(18);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(14);
    root->right->right = new TreeNode(18);

    // Ініціалізуємо змінні для максимального елемента та кількості його повторень
    int maxElement = INT_MIN;
    int count = 0;

    // Знаходимо максимальний елемент та кількість його повторень
    findMaxElementAndCount(root, maxElement, count);

    // Виводимо результати
    cout << "Максимальний елемент: " << maxElement << std::endl;
    cout << "Кількість повторень: " << count << std::endl;

    // Звільняємо пам'ять, щоб уникнути витоку пам'яті
    // Зверніть увагу, що це простий приклад, і в реальному коді можуть використовуватися різні стратегії управління пам'яттю
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
