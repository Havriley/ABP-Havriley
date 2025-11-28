#include <iostream>
#include <string.h>

using namespace std;

class otdel {
    char *fam;
    char *init;
    unsigned int year;
    float salary;

public:
    otdel() {
        fam = new char[1]; fam[0] = '\0';
        init = new char[1]; init[0] = '\0';
        year = 0;
        salary = 0.0;
    }

    ~otdel() {
        delete[] fam;
        delete[] init;
    }

    void set(char *f, char *i, unsigned int y, float s) {
        delete[] fam;
        fam = new char[strlen(f) + 1];
        strcpy(fam, f);

        delete[] init;
        init = new char[strlen(i) + 1];
        strcpy(init, i);

        year = y;
        salary = s;
    }

    void get(char *&f, char *&i, unsigned int &y, float &s) {
        delete[] f;
        f = new char[strlen(fam) + 1];
        strcpy(f, fam);

        delete[] i;
        i = new char[strlen(init) + 1];
        strcpy(i, init);

        y = year;
        s = salary;
    }

    void show() {
        cout << "| " << setw(14) << fam << "|"
        << setw(8)  << init << "|"
        << setw(14) << year << "|"
        << setw(9) << salary << " |" << endl;
        cout << "|--------------------------------------------------|\n";
    }
};

int Lab_10() {
    otdel A, B, C;

    A.set((char*)"Ivanova", (char*)"I.I.", 1975, 517.50);
    B.set((char*)"Petrenko", (char*)"P.P.", 1956, 219.10);
    C.set((char*)"Panicovski", (char*)"M.S.", 1967, 300.00);

    cout << "----------------------------------------------------\n";
    cout << "|                   Відділ кадрів                  |\n";
    cout << "|--------------------------------------------------|\n";
    cout << "|    Прізвище   |Ініціали|Рік народження|   Оклад  |\n";
    cout << "|--------------------------------------------------|\n";
    A.show();
    B.show();
    C.show();

    return 0;
}