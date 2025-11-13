#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

static int Lab_5()
{
    unsigned int n = 0;
    cout << "Введіть кількість значень елементів масиву: ";
    cin >> n;
    double result[n];
    int arr[n];
    srand(time(0));

    if (n <=1) {
        cout << "Масив повинен бути більше за 1. Введіть кількість значень елементів масиву: ";
        cin >> n;
}
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 201 - 100;
    }


    for (int i = 0; i < n; i++) {
        if (i == 0) {

            result[i] = (arr[i] + arr[i + 1]) / 2.0;
        }
        else if (i == n - 1) {

            result[i] = (arr[i - 1] + arr[i]) / 2.0;
        }
        else {

            result[i] = (arr[i - 1] + arr[i] + arr[i + 1]) / 3.0;
        }
    }

    cout << "Початковий масив:\n";
    for (int i = 0; i < n; i++)
        cout << setw(6) << arr[i];
    cout << "\n\nПісля заміни:\n";
    for (int i = 0; i < n; i++)
        cout << setw(6) << fixed << setprecision(1) << result[i];
    cout << endl;
    return 0;
}