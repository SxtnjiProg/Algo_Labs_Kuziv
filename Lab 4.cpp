#include <iostream>
#include <list>
#include <Windows.h>

using namespace std;

// Функція створення третього списку, що містить парні елементи з двох вхідних списків.
list<int> createThirdList(const list<int>& list1, const list<int>& list2) {
    list<int> thirdList;

    // Перебираємо елементи першого списку та додаємо парні числа до третього списку.
    for (int num : list1) {
        if (num % 2 == 0) {
            thirdList.push_back(num);
        }
    }

    // Перебираємо елементи другого списку та додаємо парні числа до третього списку.
    for (int num : list2) {
        if (num % 2 == 0) {
            thirdList.push_back(num);
        }
    }

    return thirdList;
}

// Функція створення четвертого списку, що містить елементи менше вказаного значення з двох вхідних списків.
list<int> createFourthList(const list<int>& list1, const list<int>& list2, int value) {
    list<int> fourthList;

    // Перебираємо елементи першого списку та додаємо ті, які менше вказаного значення, до четвертого списку.
    for (int num : list1) {
        if (num < value) {
            fourthList.push_back(num);
        }
    }

    // Перебираємо елементи другого списку та додаємо ті, які менше вказаного значення, до четвертого списку.
    for (int num : list2) {
        if (num < value) {
            fourthList.push_back(num);
        }
    }

    return fourthList;
}

// Виведення меню опцій для користувача.
void printMenu() {
    cout << "1. Додати на початок списку\n";
    cout << "2. Додати в кінець списку\n";
    cout << "3. Додати в середину списку\n";
    cout << "4. Додати після значення\n";
    cout << "5. Видалити зі списку\n";
    cout << "6. Знайти значення\n";
    cout << "7. Роздрукувати список\n";
    cout << "8. Роздрукувати парні елементи з перших двох списків\n";
    cout << "9. Створити новий список (менше вказаного значення)\n";
    cout << "10. Вийти\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    list<int> list1, list2, list3, list4;
    int num;

    cout << "Введіть 5 чисел для першого списку:\n";
    for (int i = 0; i < 5; i++) {
        cin >> num;
        list1.push_back(num);
    }

    cout << "Введіть 5 чисел для другого списку:\n";
    for (int i = 0; i < 5; i++) {
        cin >> num;
        list2.push_back(num);
    }

    int choice;

    do {
        printMenu();
        cout << "Виберіть опцію: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system("cls");
            cout << "Виберіть список (1 або 2): ";
            int listChoice;
            cin >> listChoice;
            cout << "Введіть число: ";
            cin >> num;
            if (listChoice == 1) {
                list1.push_front(num); // Додавання числа на початок першого списку.
            }
            else if (listChoice == 2) {
                list2.push_front(num); // Додавання числа на початок другого списку.
            }
            break;
        case 2:
            system("cls");
            cout << "Виберіть список (1 або 2): ";
            cin >> listChoice;
            cout << "Введіть число: ";
            cin >> num;
            if (listChoice == 1) {
                list1.push_back(num); // Додавання числа в кінець першого списку.
            }
            else if (listChoice == 2) {
                list2.push_back(num); // Додавання числа в кінець другого списку.
            }
            break;
        case 3:
            system("cls");
            cout << "Виберіть список (1 або 2): ";
            cin >> listChoice;
            cout << "Введіть позицію: ";
            int pos;
            cin >> pos;
            cout << "Введіть число: ";
            cin >> num;
            if (listChoice == 1) {
                auto it = list1.begin();
                advance(it, pos - 1);
                list1.insert(it, num); // Додавання числа в середину першого списку на вказану позицію.
            }
            else if (listChoice == 2) {
                auto it = list2.begin();
                advance(it, pos - 1);
                list2.insert(it, num); // Додавання числа в середину другого списку на вказану позицію.
            }
            break;
        case 4:
            system("cls");
            cout << "Виберіть список (1 або 2): ";
            cin >> listChoice;
            cout << "Введіть значення, після якого додати: ";
            int value;
            cin >> value;
            cout << "Введіть число: ";
            cin >> num;
            if (listChoice == 1) {
                auto it = find(list1.begin(), list1.end(), value);
                if (it != list1.end()) {
                    list1.insert(++it, num); // Додавання числа після вказаного значення в першому списку.
                }
            }
            else if (listChoice == 2) {
                auto it = find(list2.begin(), list2.end(), value);
                if (it != list2.end()) {
                    list2.insert(++it, num); // Додавання числа після вказаного значення в другому списку.
                }
            }
            system("cls");
            break;
        case 5:
            cout << "Виберіть список (1 або 2): ";
            cin >> listChoice;
            cout << "Введіть позицію для видалення: ";
            cin >> pos;
            if (listChoice == 1) {
                auto it = list1.begin();
                advance(it, pos - 1);
                list1.erase(it); // Видалення елемента з першого списку за вказаною позицією.
            }
            else if (listChoice == 2) {
                auto it = list2.begin();
                advance(it, pos - 1);
                list2.erase(it); // Видалення елемента з другого списку за вказаною позицією.
            }
            break;
        case 6:
            system("cls");
            cout << "Виберіть список (1 або 2): ";
            cin >> listChoice;
            cout << "Введіть число для пошуку: ";
            cin >> num;
            if (listChoice == 1) {
                auto it = find(list1.begin(), list1.end(), num);
                if (it != list1.end()) {
                    cout << "Значення знайдено в першому списку.\n";
                }
                else {
                    cout << "Значення не знайдено в першому списку.\n";
                }
            }
            else if (listChoice == 2) {
                auto it = find(list2.begin(), list2.end(), num);
                if (it != list2.end()) {
                    cout << "Значення знайдено в другому списку.\n";
                }
                else {
                    cout << "Значення не знайдено в другому списку.\n";
                }
            }
            break;
        case 7:
            system("cls");
            cout << "Перший список:\n";
            for (auto num : list1) {
                cout << num << " ";
            }
            cout << "\nДругий список:\n";
            for (auto num : list2) {
                cout << num << " ";
            }
            cout << endl;
            break;
        case 8:
            system("cls");
            cout << "Перший список:\n";
            for (auto num : list1) {
                cout << num << " ";
            }
            cout << "\nДругий список:\n";
            for (auto num : list2) {
                cout << num << " ";
            }
            cout << "\nТретій список (парні елементи з перших двох):\n";
            list3 = createThirdList(list1, list2);
            for (auto num : list3) {
                cout << num << " ";
            }
            cout << endl;
            break;
        case 9:
            system("cls");
            cout << "Перший список:\n";
            for (auto num : list1) {
                cout << num << " ";
            }
            cout << "\nДругий список:\n";
            for (auto num : list2) {
                cout << num << " ";
            }
            int specifiedValue;
            cout << "\nВведіть значення: ";
            cin >> specifiedValue;
            list4 = createFourthList(list1, list2, specifiedValue);
            cout << "Четвертий список (елементи менше " << specifiedValue << "):" << endl;
            for (auto num : list4) {
                cout << num << " ";
            }
            cout << endl;
            break;
        case 10:
            system("cls");
            cout << "Дякую за використання програми!\n";
            break;
        default:
            cout << "Неправильний вибір. Спробуйте ще раз.\n";
        }
    } while (choice != 10);

    return 0;
}
