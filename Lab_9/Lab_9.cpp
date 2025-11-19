#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Car {
    char name[50];
    char gearbox[2];
    int engine_volume;
    float max_speed;
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

static void f_add(Car *car) {
    file.seekp(0, ios::end);
    file.write(reinterpret_cast<char*>(car), sizeof(Car));
}

static int fcheck_number(int record_num) {
    file.seekg(0, ios::end);
    int total_records = file.tellg() / sizeof(Car);
    if (record_num < 0 || record_num >= total_records) {
        return -1;
    }
    return 0;
}

static void fshow_1(int record_num) {
    if (fcheck_number(record_num) == 0) {
        Car car;
        file.seekg(record_num * sizeof(Car), ios::beg);
        file.read(reinterpret_cast<char*>(&car), sizeof(Car));
        cout << "Назва: " << car.name << ", Коробка передач: " << car.gearbox
             << ", Об'єм двигуна: " << car.engine_volume
             << ", Максимальна швидкість: " << car.max_speed << endl;
    } else {
        cout << "Невірний номер запису." << endl;
    }
}

static void fshow_all() {
    Car car;
    file.seekg(0, ios::beg);
    while (file.read(reinterpret_cast<char*>(&car), sizeof(Car))) {
        cout << "Назва: " << car.name << ", Коробка передач: " << car.gearbox
             << ", Об'єм двигуна: " << car.engine_volume
             << ", Максимальна швидкість: " << car.max_speed << endl;
    }
}

static void fdel_item(int record_num) {
    if (fcheck_number(record_num) == 0) {
        fstream temp_file("temp.dat", ios::out | ios::binary);
        Car car;
        file.seekg(0, ios::beg);
        int current_record = 0;
        while (file.read(reinterpret_cast<char*>(&car), sizeof(Car))) {
            if (current_record != record_num) {
                temp_file.write(reinterpret_cast<char*>(&car), sizeof(Car));
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

static int Lab_9() {
    initf("data.dat");

    Car car1 = {"ВАЗ 2110", "M", 1599, 180.5};
    Car car2 = {"Toyota", "A", 1999, 200};
    Car car3 = {"Opel", "M", 2000, 223.4};

    f_add(&car1);
    f_add(&car2);
    f_add(&car3);

    fshow_all();

    cout << "Виведення запису 1:" << endl;
    fshow_1(1);

    cout << "Видалення запису 1" << endl;
    fdel_item(1);

    cout << "Після видалення:" << endl;
    fshow_all();

    commit();
    return 0;
}