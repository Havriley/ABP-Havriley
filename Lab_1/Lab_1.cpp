#include <iostream>
#include <iomanip>
#include "windows.h"

using namespace std;

static int Lab_1() {
    SetConsoleOutputCP(CP_UTF8);
    char name1[9], name2[9], name3[9];
    char sc1, sc2, sc3;
    unsigned short cnt1, cnt2, cnt3;
    float sq1, sq2, sq3;
    cout << "1. Введіть: назву, школу, кількість, площу > ";
    cin >> name1 >> sc1 >> cnt1 >> sq1;
    cout << "2. Введіть: назву, школу, кількість, площу > ";
    cin >> name2 >> sc2 >> cnt2 >> sq2;
    cout << "3. Введіть: назву, школу, кількість, площу > ";
    cin >> name3 >> sc3 >> cnt3 >> sq3;
    cout << "-----------------------------------------------\n";
    cout << "| Буддійські монастирі Японії періоду Нара     |\n";
    cout << "|---------------------------------------------|\n";
    cout << "|  Назва   | Школа | Кількість | Площа землі  |\n";
    cout << "|          |       |  монахів  |    (га)      |\n";
    cout << "|----------|-------|-----------|--------------|\n";

    cout << setw(11) << name1 << " | " << sc1 << " | " << setw(3) << cnt1
    << " | " << setw(5) << fixed << setprecision(1) << sq1 << " | " << endl;
    cout << setw(11) << name2 << " | " << sc2 << " | " << setw(3) << cnt2
    << " | " << setw(5) << fixed << setprecision(1) << sq2 << " | " << endl;
    cout << setw(11) << name3 << " | " << sc3 << " | " << setw(3) << cnt3
    << " | " << setw(5) << fixed << setprecision(3) << sq3 << " | " << endl;
    cout << "|---------------------------------------------|" << endl;
    cout << "| Примітка: Т – Тендай; С – Сінгон;           |" << endl;
    cout << "|           Д – Дзедзіцу                      |" << endl;
    cout << "-----------------------------------------------" << endl;


    return 0;
}