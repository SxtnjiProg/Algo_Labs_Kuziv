#include <iostream>
#include <fstream>
#include <queue>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // ³�������� ���� ��� �������
    ifstream inputFile("input.txt");

    // ����������, �� ������� ������� ����
    if (!inputFile.is_open()) {
        cerr << "�� ������� ������� ���� input.txt" << std::endl;
        return 1;
    }

    // ������� ����� C � ���������
    double C;
    cout << "������ ����� C: ";
    cin >> C;

    // �������, �� ���� ������ ���� �����, ������� ��������
    double number;
    queue<double> lessThanCQueue;
    queue<double> greaterThanOrEqualCQueue;

    // ������� ����� � ����� �� ��������� �� �� �� �����
    while (inputFile >> number) {
        if (number < C) {
            lessThanCQueue.push(number);
        }
        else {
            greaterThanOrEqualCQueue.push(number);
        }
    }

    // ��������� ����
    inputFile.close();

    // �������� ����� � �������
    cout << "����� ����� �� " << C << ": ";
    while (!lessThanCQueue.empty()) {
        cout << lessThanCQueue.front() << " ";
        lessThanCQueue.pop();
    }

    cout << "\n����� ����� ��� ��� " << C << ": ";
    while (!greaterThanOrEqualCQueue.empty()) {
        cout << greaterThanOrEqualCQueue.front() << " ";
        greaterThanOrEqualCQueue.pop();
    }

    cout << "\n";

    return 0;
}
