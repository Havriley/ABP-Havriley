#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Employee {
    char lastname[50];
    char initials[10];
    int birth_year;
    float salary;
};

static fstream file;

static void initf(const char *filename) {
    file.open(filename, ios::in | ios::out | ios::binary | ios::app);
    if (!file) {
        cout << "Неможливо відкрити файл." << endl;
        exit(1);
    }
}

static void commit() {
    if (file.is_open()) {
        file.close();
    }
}

static void f_add(Employee *emp) {
    file.seekp(0, ios::end);
    file.write(reinterpret_cast<char*>(emp), sizeof(Employee));
}

static int fcheck_number(int record_num) {
    file.seekg(0, ios::end);
    int total_records = file.tellg() / sizeof(Employee);
    if (record_num < 0 || record_num >= total_records) {
        return -1;
    }
    return 0;
}

static void fshow_1(int record_num) {
    if (fcheck_number(record_num) == 0) {
        Employee emp;
        file.seekg(record_num * sizeof(Employee), ios::beg);
        file.read(reinterpret_cast<char*>(&emp), sizeof(Employee));

        cout << "Фамилия: " << emp.lastname
             << ", Инициалы: " << emp.initials
             << ", Год рождения: " << emp.birth_year
             << ", Оклад: " << emp.salary << endl;

    } else {
        cout << "Невірний номер запису." << endl;
    }
}

static void fshow_all() {
    Employee emp;
    file.seekg(0, ios::beg);
    while (file.read(reinterpret_cast<char*>(&emp), sizeof(Employee))) {
        cout << "Фамилия: " << emp.lastname
             << ", Инициалы: " << emp.initials
             << ", Год рождения: " << emp.birth_year
             << ", Оклад: " << emp.salary << endl;
    }
}

static void fdel_item(int record_num) {
    if (fcheck_number(record_num) == 0) {

        fstream temp_file("temp.dat", ios::out | ios::binary);
        Employee emp;

        file.seekg(0, ios::beg);
        int current_record = 0;

        while (file.read(reinterpret_cast<char*>(&emp), sizeof(Employee))) {
            if (current_record != record_num) {
                temp_file.write(reinterpret_cast<char*>(&emp), sizeof(Employee));
            }
            current_record++;
        }

        file.close();
        temp_file.close();

        remove("data.dat");
        rename("temp.dat", "data.dat");

        initf("data.dat");

    } else {
        cout << "Невірний номер запису." << endl;
    }
}

int Lab_9() {
    initf("data.dat");

    Employee e1 = {"Иванов", "И.И.", 1975, 517.50};
    Employee e2 = {"Петренко", "П.П.", 1956, 219.10};
    Employee e3 = {"Паниковский", "М.С.", 1967, 300.00};

    f_add(&e1);
    f_add(&e2);
    f_add(&e3);

    cout << "Усі записи:" << endl;
    fshow_all();

    cout << "\nВиведення запису 1:" << endl;
    fshow_1(1);

    cout << "\nВидалення запису 1..." << endl;
    fdel_item(1);

    cout << "\nПісля видалення:" << endl;
    fshow_all();

    commit();
    return 0;
}

