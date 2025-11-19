#include <iostream>
#include "windows.h"
using namespace std;

struct stack {
    string surname;
    string initials;
    int year;
    float salary;
    stack *dali;
};

static void plusStek(stack **st) {
    string s, i;
    int y;
    float sal;

    cout << "Введіть: фамілія, \n";
    cout << "Для завершення введыть '-' ";

    while (true) {
        cout << ">>> ";
        cin >> s;
        if (s == "-") break;
        cin >> i >> y >> sal;

        stack *element = new stack;
        element->surname = s;
        element->initials = i;
        element->year = y;
        element->salary = sal;
        element->dali = *st;
        *st = element;
    }
}

static void minusStek(stack *st) {
    cout << "\n-----------------------------------------\n";
    cout << "| Фамалія    | Ініциали | Год  | Оклад  |\n";
    cout << "-----------------------------------------\n";

    while (st != nullptr) {
        cout << "| "
             << st->surname << "\t"
             << st->initials << "\t"
             << st->year << "\t"
             << st->salary << "\t|\n";

        stack *temp = st;
        st = st->dali;
        delete temp;
    }

    cout << "-----------------------------------------\n";
}

static int Lab_8() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    stack *st = nullptr;
    plusStek(&st);
    minusStek(st);

    system("pause");
    return 0;
}