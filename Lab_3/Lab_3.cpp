#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;


static int Lab_3()
{
    static int N;

    cout << "Введіть кількість чисел для генерації" << endl;
    cin >> N;

    const int SIZE = N;
    const int RANGE = 101;


    int numbers[SIZE];
    int count[RANGE] = {0};

    srand(static_cast<unsigned int>(std::time(0)));

    for (int i = 0; i < SIZE; ++i) {
        numbers[i] = rand() % 101;
    }

    cout << N << " рандомних чисел (Від 0 до 100): ";
    for (int i = 0; i < SIZE; ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    int maxCount = 0;
    int beforeItem = 0;
    int flag = 1;

    for (int i = 1; i < SIZE; ++i)
        {
      beforeItem = numbers[i - 1];
        if (numbers[i] > beforeItem)
            {
            flag++;
            }
        else {
             if (flag > 1) {
                maxCount++;
            }
            flag = 1;
        }
    if (i == SIZE - 1)
        {
        if (flag > 1) {
            maxCount++;
        }
    }
   }


    cout << "Кількість ділянок, які утворюють безперервні послідовності чисел зі значеннями, що не зменшуються: "<< maxCount << endl;



    return 0;
}