#include <iostream>
#include <iomanip>
#include <ctime>


using namespace std;

void initArr(int** Arr, short n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Arr[i][j] = rand() % 101 - 50;
        }
    }
}
void printArr(int** Arr, short n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(4) << Arr[i][j];
        cout << endl;
    }
}
void mirrorArr(int** Arr, short n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int temp = Arr[i][j];
            Arr[i][j] = Arr[n - 1 - j][n - 1 - i];
            Arr[n - 1 - j][n - 1 - i] = temp;
        }
    }
}


static int Lab_6()
{
    short n;
    cout<<"Введіть розмірність масиву: \n";
    cin>>n;
    if (n<=1)
    {
        cout<<"Матриця повина бути більше за 1. Введіть розмірність масиву: \n";
        cin>>n;
    }

    int** Arr = new int*[n];
    for (int i = 0; i < n; i++)
        Arr[i] = new int[n];

    initArr(Arr, n);
    cout<<"Початковий масив: \n";
    printArr(Arr, n);
    mirrorArr(Arr, n);
    cout<<"Після розвороту на 180 градуів: \n";
    printArr(Arr, n);


    for (int i = 0; i<n; i++){
        delete[] Arr[i];
    }
    delete[] Arr;
    return 0;
}