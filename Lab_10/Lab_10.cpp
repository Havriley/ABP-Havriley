#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Carr {
    char *name;
    char korper;
    unsigned int engine;
    float speed;

public:
    Carr() : name(nullptr), korper('\0'), engine(0), speed(0.0f) {}

    void set(char *a, char b, unsigned int c, float d) {
        name = new char[strlen(a) + 1];
        strcpy(name, a);
        korper = b;
        engine = c;
        speed = d;
    }

    void get(char *a, char &b, unsigned int &c, float &d) {
        delete[] a;
        a = new char[strlen(name) + 1];
        strcpy(a, name);
        b = korper;
        c = engine;
        d = speed;
    }

    void show() {
        cout << "Назва автомобіля: " << name << endl;
        cout << "Коробка передач: " << korper << endl;
        cout << "Об'єм двигуна: " << engine << " см³" << endl;
        cout << "Максимальна швидкість: " << speed << " км/год" << endl;
    }

    ~Carr() {
        delete[] name;
    }
};

static int Lab_10() {
    Carr car1;

    char name[50];
    char korper;
    unsigned int engine;
    float speed;

    cout << "Введіть назву автомобіля: ";
    cin.getline(name, 50);

    cout << "Введіть тип коробки передач (1 - механіка, 2 - автомат): ";
    cin >> korper;

    cout << "Введіть об'єм двигуна (у см³): ";
    cin >> engine;

    cout << "Введіть максимальну швидкість (км/год): ";
    cin >> speed;

    car1.set(name, korper, engine, speed);

    cout << "\nДані про автомобіль:" << endl;
    car1.show();

    char *retrieved_name = new char[50];
    char retrieved_korper;
    unsigned int retrieved_engine;
    float retrieved_speed;

    car1.get(retrieved_name, retrieved_korper, retrieved_engine, retrieved_speed);

    cout << "\nОтримані дані про автомобіль:" << endl;
    cout << "Назва: " << retrieved_name << endl;
    cout << "Коробка передач: " << retrieved_korper << endl;
    cout << "Об'єм двигуна: " << retrieved_engine << " см³" << endl;
    cout << "Максимальна швидкість: " << retrieved_speed << " км/год" << endl;

    delete[] retrieved_name;

    return 0;
}