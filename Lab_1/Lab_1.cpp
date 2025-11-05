#include <iostream>
#include <iomanip>
#include "windows.h"

using namespace std;

static int Lab_1() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleOutputCP(65001); // Увімкнути UTF-8 вивід
    SetConsoleCP(65001);
    char surname1[50], surname2[50], surname3[50];;
    char initials1[50], initials2[50], initials3[50];
    unsigned short year1, year2, year3;
    float salary1, salary2, salary3;
    cout << "1. Введіть: призвище, ініціали, рік народження, оклад > ";
    cin >> surname1>>initials1>>initials1>> salary1;
    cout << "2. Введіть: призвище, ініціали, рік народження, оклад > ";
    cin >>surname2 >>initials2 >>year2 >> salary2 ;

    cout << "3. Введіть: призвище, ініціали, рік народження, оклад > ";
    cin >>surname3 >>initials3 >>year3 >> salary3 ;
    cout << left ;
    cout << "----------------------------------------------------\n";
    cout << "| Відділ кадрів                                    |\n";
    cout << "|--------------------------------------------------|\n";
    cout << "|    Прізвище   |Ініціали|Рік народження|   Оклад  |\n";
    cout << "|---------------|--------|--------------|----------|\n";

    cout << "| " <<setw(21) << surname1;
    cout << "|" << setw(10)  << initials1;
    cout << "|" << setw(14) << year1;
    cout << "|" << setw(10) <<fixed<< setprecision(2) << salary1 << "|" << endl;

    cout << "| " << setw(21)<< surname2;
    cout << "|" << setw(10)  << initials2;
    cout << "|" << setw(14)  << year2;
    cout << "|" << setw(10)  <<fixed<< setprecision(2) << salary2 << "|" << endl;

    cout << "| " << setw(22)<< surname3;
    cout << " |" << setw(10) << initials3;
    cout << "|" << setw(14) << year3;
    cout << "|" << setw(10)<<fixed<< setprecision(2) << salary3 << "|" << endl;

    cout << "|--------------------------------------------------|" << endl;
    cout << "| Примітка: оклад встановлено станом на 1 січня    |" << endl;
    cout << "| 2000 року                                        |" << endl;
    cout << "----------------------------------------------------" << endl;


    return 0;
}