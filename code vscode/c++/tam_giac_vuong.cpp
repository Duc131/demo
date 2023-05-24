#include <iostream>

using namespace std;

int main() {
    int c = 'A';
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << static_cast<char>(c)<<" ";
            c++;
        }
        cout << endl;
    }
    return 0;
}