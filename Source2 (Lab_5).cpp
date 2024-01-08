#include <iostream>
#include <climits>
#include <Windows.h>
using namespace std;
// ���������� ����� �������� ������
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// ������� ��� ����������� ������������� �������� �� ������� ���� ��������� � �������� �����
void findMaxElementAndCount(TreeNode* root, int& maxElement, int& count) {
    if (root != nullptr) {
        // ���������� ���������� ��� ����� ��������
        findMaxElementAndCount(root->left, maxElement, count);

        // ������� ��������� �����
        if (root->data > maxElement) {
            maxElement = root->data;
            count = 1;  // ������� ����� ������������ �������, ��������� �������
        }
        else if (root->data == maxElement) {
            count++;  // �������� ������� ��������� ������������� ��������
        }

        // ���������� ���������� ��� ������� ��������
        findMaxElementAndCount(root->right, maxElement, count);
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // ��������� ������ ������ ��� ����������
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(52);
    root->right = new TreeNode(18);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(14);
    root->right->right = new TreeNode(18);

    // ���������� ���� ��� ������������� �������� �� ������� ���� ���������
    int maxElement = INT_MIN;
    int count = 0;

    // ��������� ������������ ������� �� ������� ���� ���������
    findMaxElementAndCount(root, maxElement, count);

    // �������� ����������
    cout << "������������ �������: " << maxElement << std::endl;
    cout << "ʳ������ ���������: " << count << std::endl;

    // ��������� ���'���, ��� �������� ������ ���'��
    // ������� �����, �� �� ������� �������, � � ��������� ��� ������ ����������������� ��� ������㳿 ��������� ���'����
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
