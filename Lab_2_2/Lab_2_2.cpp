#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

static int Lab_2_2() {
    double sum = 0.0;
    double term;
    int  n;
    const double eps = 0.000001;

    for (n = 0; ; n++) {
        term = pow(-1, n) * (1 - (2 * (double)n - 1) / (2*(n + 1)));

        if (fabs(term) >= eps) {
            sum += term;
            cout << n <<": "<< term << endl;
        }
        else {
            cout <<  n <<": "<< term << endl;
            break;
        }

        if (n == 9) {
            cout << "Sum of first 10 variables: " << fixed << setprecision(6) << sum << endl;
            break;
        }
    }

    cout << "Full sum: " << fixed << setprecision(6) << sum << endl;
    return 0;
}