#include <iostream>
#include <cstring>
#include <iomanip>
#include "windows.h"
using namespace std;

const int MAX_PERSONS = 10;

struct persons {
    char name[30];
    char initials[30];
    unsigned short year;
    float salary;
};

static void inputperson (persons person[], int &n) {
    n = 0;
    while (n < MAX_PERSONS) {
        cout << "Введіть призвище, ініціали, рік народження, оклад (введіть '***' для завершення): ";
        cin >> person[n].name;
        if (strcmp(person[n].name, "***" ) == 0) {
            break;
        }
        cin >> person[n].initials >> person[n].year >> person[n].salary;
        n++;
    }
}

static void printTable(const persons books[], int n) {
    cout << "---------------------------------------------------------\n";
    cout << "|                Фірми - виробники СУБД                 |\n";
    cout << "|-------------------------------------------------------|\n";
    cout << "|   Прізвище   | Ініціали | Рік народження |    Оклад   |\n";
    cout << "|--------------|----------|--------------|--------------|\n";

    for (int i = 0; i < n; i++) {
        cout << "| " << setw(12) << books[i].name
             << " | " << setw(8) << books[i].initials
             << " | " << setw(11) << books[i].year
             << " | " << setw(13) << books[i].salary
             << " |\n";
    }
    cout << "|-------------------------------------------------------|\n";
    cout << "| Примітка:оклад встановлено станом на 1 січня 2000 року|\n";
    cout << "---------------------------------------------------------\n";
}

static void sortperson(persons person[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(person[j].name, person[minIndex].name) < 0) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(person[i], person[minIndex]);
        }
    }
}

static int Lab_7() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    persons person[MAX_PERSONS];
    int n;

    inputperson(person, n);
    printTable(person, n);
    sortperson(person, n);
    cout << "\nВідсортований каталог:\n";
    printTable(person, n);

    return 0;
}