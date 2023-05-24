#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int checkAllDigitAreOdd(int n) {
    while (n > 0) {
        int dv = n % 10;
        n /= 10;
        if (dv % 2 == 0)
            return false;
    }

    return true;

}
signed main(void) {
    int n;
    cin >> n;
    int a[100];
    int b[100];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << endl;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (checkAllDigitAreOdd(a[i]) == 1) {
            b[count] = a[i];
            count++;
        }
    }

    cout << count << endl;
    for (int i = 0; i < count; i++)
        cout << b[i] << " ";
    return 0;
}