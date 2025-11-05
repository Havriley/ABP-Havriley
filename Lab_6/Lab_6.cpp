#include <iostream>
#include <iomanip>
#include <ctime>


using namespace std;

static int Lab_6()
{
    const int n = 9;
    int matrix[n][n] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 101 - 50;
        }
    }

    cout << "Початкова матриця:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(4) << matrix[i][j];
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[n - 1 - j][n - 1 - i];
            matrix[n - 1 - j][n - 1 - i] = temp;
        }
    }

    cout << "\nСиметрія відносно побічної діагоналі:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}