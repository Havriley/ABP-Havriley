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
    cout << "---------------------------------------------------------\n";
    cout << "|                Відділ кадрів                          |\n";
    cout << "|-------------------------------------------------------|\n";
    cout << "|   Прізвище   | Ініціали | Рік народження |    Оклад   |\n";
    cout << "|--------------|----------|----------------|------------|\n";

    while (st != nullptr) {
        cout << "| " << setw(12) << st->surname
             << " | " << setw(8) << st->initials
             << " | " << setw(14) <<st->year
             << " | " << setw(11) << st->salary << "|\n";

        stack *temp = st;
        st = st->dali;
        delete temp;
    }

    cout << "|-------------------------------------------------------|\n";
    cout << "| Примітка:оклад встановлено станом на 1 січня 2000 року|\n";
    cout << "---------------------------------------------------------\n";
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