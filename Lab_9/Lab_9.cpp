#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdio>
#include "windows.h"
using namespace std;


const string FILE_NAME = "C:\\Users\\admin\\Desktop\\input.txt";
const string TEMP_FILE = "temp.txt";


struct Component {
    string surname;
    string surname1;
    int  year;
    double money;
};



void f_add() {

    ofstream f(FILE_NAME, ios::app);

    if (!f.is_open()) {
        cout << "Помилка відкриття файлу!\n";
        return;
    }

    Component newComponent;
    cout << "\n Додавання нового компоненту \n";
    cout << "Прізвище (без пробілів, наприклад Белоус): ";
    cin >> newComponent.surname;
    cout << "Ініціали (наприклад І.І.): ";
    cin >> newComponent.surname1;
    cout << "Рік народження (наприклад від 1950 до 2025): ";
    cin >> newComponent.year;
    cout << "Оклад";
    cin >> newComponent.money;



    f << newComponent.surname << " "
      << newComponent.surname1 << " "
      << newComponent.year << " "
      << newComponent.money << endl;

    f.close();
    cout << "Робітника успішно додано\n";
}


void fshow_all() {
    ifstream f(FILE_NAME);

    if (!f.is_open()) {
        cout << "Файл порожній або не існує. Для початку додайте запис \n";
        return;
    }

    cout << "\n-----------------------------------------------------------\n";
    cout << "| № | Прізвище        |ініціали  | Рік народення  | Оклад |\n";
    cout << "|---|-----------------|----------|----------------|-------|\n";

    Component c;
    int index = 1;


    while (f >> c.surname >> c.surname1 >> c.year >> c.money) {
        cout << "| " << setw(2) << left << index++
             << "| " << setw(19) << c.surname
             << "| " << setw(8) << c.surname1
             << "| " << setw(12) << fixed << setprecision(3) << c.year
             << "| " << setw(12) << c.money << "|\n";
    }

    cout << "-----------------------------------------------------------\n";
    f.close();
}



void fshow_1(int searchId) {
    ifstream f(FILE_NAME);
    if (!f.is_open()) {
        cout << "Файл не знайдено\n";
        return;
    }

    Component c;
    int currentId = 1;
    bool found = false;

    while (f >> c.surname >> c.surname1 >> c.year >> c.money) {
        if (currentId == searchId) {
            cout << "\n Робітник №" << searchId << " \n";
            cout << "Прівище    " << c.surname << "\n";
            cout << "Ініціали   " << c.surname1 << "\n";
            cout << "Рік нар.   " << c.year << "\n";
            cout << "Оклад      " << c.money << "\n";
            found = true;
            break;
        }
        currentId++;
    }

    if (!found) {
        cout << "Робітника із номером " << searchId << " не знайдено.\n";
    }
    f.close();
}


void fdel_item(int deleteId) {
    ifstream in(FILE_NAME);
    if (!in.is_open()) {
        cout << "Файл не знайдено\n";
        return;
    }

    ofstream out(TEMP_FILE);

    Component c;
    int currentId = 1;
    bool deleted = false;


    while (in >> c.surname >> c.surname1 >> c.year >> c.money) {
        if (currentId != deleteId) {

            out << c.surname << " "
                << c.surname1 << " "
                << c.year << " "
                << c.money << endl;
        } else {
            deleted = true;
        }
        currentId++;
    }

    in.close();
    out.close();


    if (remove(FILE_NAME.c_str()) != 0) {
        perror("Помилка видалення старого файлу");
        return;
    }


    if (rename(TEMP_FILE.c_str(), FILE_NAME.c_str()) != 0) {
        perror("Помилка перейменування тимчасового файлу");
        return;
    }
    if (deleted) {
        cout << "Робітника №" << deleteId << " успішно видалено\n";
    } else {
        cout << "Робітник №" << deleteId << " не знайдено\n";
    }
}

int Lab_9() {


    SetConsoleOutputCP(CP_UTF8);
    int choice;
    while (true) {
        cout << "\n  ГОЛОВНЕ МЕНЮ \n";
        cout << "1 – Показати всіх робітників\n";
        cout << "2 – Показати одного робітника\n";
        cout << "3 – Додати робітника\n";
        cout << "4 – Видалити робітника\n";
        cout << "0 – Вихід\n";
        cout << "Ваш вибір  ";
        cin >> choice;
        if (choice == 0) break;

        switch (choice) {
        case 1:
            fshow_all();
            break;
        case 2: {
                int id;
                cout << "Введіть номер робітника: ";
                cin >> id;
                fshow_1(id);
                break;
        }
        case 3:
            f_add();
            break;
        case 4: {
                int id;
                cout << "Введіть номер робітника для видалення: ";
                cin >> id;
                fdel_item(id);
                break;
        }
        default:
            cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    }

    return 0;
}