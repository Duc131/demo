#include <bits/stdc++.h>
#include <iostream>
#include <iomanip> // hàm fix
#include <math.h>
#include <string>
#include <algorithm>  // Cần thư viện này để sử dụng hàm sort
#define endl '\n'
using namespace std;

int num_of_digit(long long n) {
    if (0 <= n && n <= 9) return 1;
    return 1 + num_of_digit(n / 10);
}

signed main(void) {  

    long long n;
    cin >> n;
    cout << num_of_digit(n);

    return 0;
}