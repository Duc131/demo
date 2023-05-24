#include <iostream>

using namespace std;


int main() {
    int n;
    cin >> n;

    int i, j;
    int a[i][j];

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n - i; j++)
            cout << " ";

        for (j = 1; i <= i; j++) {
            if (j == 1 || j == i )
                cout << "1 ";
            else { 
                a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
                cout << a[i][j] << " ";
            }
        }
        cout << endl;

    }
    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap so dong: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << binomialCoeff(i, j) << " ";
        }
        cout << endl;
    }

    return 0;
}

int binomialCoeff(int n, int k) {
    int res = 1;
    if (k > n - k) {
        k = n - k;
    }

    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}