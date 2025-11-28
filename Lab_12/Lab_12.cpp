#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

#define N 3   // кількість працівників

class Worker {
private:
    char *surname;       // Прізвище
    char initials[10];   // Ініціали
    unsigned int birth;  // Рік народження
    double salary;       // Оклад

public:
    Worker() {
        surname = nullptr;
        strcpy(initials, "");
        birth = 0;
        salary = 0;
    }

    Worker(char *s, const char *init, unsigned int y, double sal) {
        surname = new char[strlen(s) + 1];
        strcpy(surname, s);
        strcpy(initials, init);
        birth = y;
        salary = sal;
    }

    ~Worker() {
        delete[] surname;
    }

    void set(char *s, const char *init, unsigned int y, double sal) {
        delete[] surname;
        surname = new char[strlen(s) + 1];
        strcpy(surname, s);
        strcpy(initials, init);
        birth = y;
        salary = sal;
    }

    void show() const {
        cout << setw(15) << left << surname
             << setw(10) << left << initials
             << setw(15) << left << birth
             << setw(10) << left << salary << endl;
    }

    Worker& operator=(const Worker &w) {
        if (this != &w) {
            delete[] surname;
            surname = new char[strlen(w.surname) + 1];
            strcpy(surname, w.surname);
            strcpy(initials, w.initials);
            birth = w.birth;
            salary = w.salary;
        }
        return *this;
    }

    bool operator==(const Worker &w) {
        return (strcmp(surname, w.surname) == 0 && birth == w.birth);
    }

    friend ostream& operator<<(ostream &os, const Worker &w) {
        os << setw(15) << left << w.surname
           << setw(10) << left << w.initials
           << setw(15) << left << w.birth
           << setw(10) << left << w.salary;
        return os;
    }

    friend istream& operator>>(istream &is, Worker &w) {
        char tempSurname[100];
        is >> tempSurname >> w.initials >> w.birth >> w.salary;

        w.surname = new char[strlen(tempSurname) + 1];
        strcpy(w.surname, tempSurname);
        return is;
    }
};

static void header() {
    cout << setw(20) << left << "Прізвище"
         << setw(20) << left << "Ініціали"
         << setw(20) << left << "Рік нар."
         << setw(18) << left << "Оклад" << endl;
    cout << "------------------------------------------------------" << endl;
}
int Lab_12() {
    Worker a[N];

    cout << "Введіть дані працівників у форматі:\n";
    cout << "Прізвище Ініціали Рік нар. Оклад\n\n";

    for (int i = 0; i < N; i++) {
        cout << "Працівник " << i + 1 << ": ";
        cin >> a[i];
    }

    cout << endl;
    header();

    for (int i = 0; i < N; i++) {
        cout << a[i] << endl;
    }

    return 0;
}