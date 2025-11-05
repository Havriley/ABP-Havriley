#include <iostream>
#include <cmath>
using namespace std;
static int Lab_2_1() {
    double x, y;

    cout << "Введіть Х коордінату: ";
    cin >> x;

    cout << "Введіть Y коордінату: ";
    cin >> y;
    if (x<0 && x>=-1)
        {
        if (x * x + y * y <= 1)
        {
            cout << "Точка в області визначень" << endl;
        }
        else {
            cout << "Точка не в області визначень" << endl;
                }
           }
    else if (x >= 0 && x <= 1 && y >= -1 && y <= 1) {
        cout << "Точка в області визначень" << endl;
    }
    else {
        cout << "Точка не в області визначень" << endl;
    }


    return 0;


}