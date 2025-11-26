#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

#define N 3

class Otdel {
private:
    char *sname;
    char *init;
    unsigned int year;
    float salary;

public:

    Otdel() {
        sname = nullptr;
        init = nullptr;
        year = 0;
        salary = 0;
    }

    Otdel(char *a, char *b, unsigned int &c, float &d) {
        sname = new char[strlen(a) + 1];
        init  = new char[strlen(b) + 1];
        strcpy(sname, a);
        strcpy(init, b);
        year = c;
        salary = d;
    }

    ~Otdel() {
        delete[] sname;
        delete[] init;
    }

    void set(char *a, char *b, unsigned int c, float d) {
        delete[] sname;
        delete[] init;

        sname = new char[strlen(a) + 1];
        init  = new char[strlen(b) + 1];

        strcpy(sname, a);
        strcpy(init, b);
        year = c;
        salary = d;
    }


    void get(char *a, char *b, unsigned int &c, float &d) {
        strcpy(a, sname);
        strcpy(b, init);
        c = year;
        d = salary;
    }

    void show() {
        cout << setw(12) << sname << setw(10) << init
             << setw(10) << year << setw(10) << salary << endl;
    }


    Otdel operator = (Otdel &o1) {
        if (this == &o1) return *this;

        delete[] sname;
        delete[] init;

        sname = new char[strlen(o1.sname) + 1];
        init  = new char[strlen(o1.init) + 1];

        strcpy(sname, o1.sname);
        strcpy(init, o1.init);
        year = o1.year;
        salary = o1.salary;

        return *this;
    }


    int operator == (Otdel &o1) {
        return strcmp(sname, o1.sname) == 0 &&
               strcmp(init, o1.init) == 0 &&
               year == o1.year &&
               salary == o1.salary;
    }


    Otdel operator + (Otdel &o1) {
        Otdel tr;

        char tmp1[100], tmp2[100];
        strcpy(tmp1, sname);
        strcat(tmp1, o1.sname);

        strcpy(tmp2, init);
        strcat(tmp2, o1.init);

        tr.set(tmp1, tmp2, year + o1.year, salary + o1.salary);
        return tr;
    }


    friend ostream & operator<<(ostream &stream, Otdel &o1);
    friend istream & operator>>(istream &stream, Otdel &o1);


    friend void shapka(void);
    friend void linebuild(void);
    friend int isvalid(int a, int b);
};

ostream & operator<<(ostream &stream, Otdel &o1) {
    stream << setw(12) << o1.sname
           << setw(10) << o1.init
           << setw(10) << o1.year
           << setw(10) << o1.salary << endl;
    return stream;
}

istream & operator>>(istream &stream, Otdel &o1) {
    char a[50], b[20];
    unsigned int c;
    float d;

    cout << "Введите фамилию: ";
    stream >> a;
    cout << "Введите инициалы: ";
    stream >> b;
    cout << "Введите год рождения: ";
    stream >> c;
    cout << "Введите оклад: ";
    stream >> d;

    o1.set(a, b, c, d);
    return stream;
}

void shapka() {

    cout << "|Прізвище|Ініціали|Рік народження|Оклад|\n";

}

void linebuild() {
    cout << "----------------------------------------" << endl;
}

int isvalid(int a, int b) {
    return (a >= 0 && a < b);
}


int Lab_12() {
    Otdel arr[N];


    char s1[] = "Иванов",   i1[] = "И.И.";
    char s2[] = "Петренко", i2[] = "П.П.";
    char s3[] = "Паниковский", i3[] = "М.С.";

    unsigned int y1 = 1975, y2 = 1956, y3 = 1967;
    float sal1 = 517.50, sal2 = 219.10, sal3 = 300.00;

    arr[0].set(s1, i1, y1, sal1);
    arr[1].set(s2, i2, y2, sal2);
    arr[2].set(s3, i3, y3, sal3);

    shapka(); linebuild();
    for (int i = 0; i < N; i++) cout << arr[i];

    return 0;
}