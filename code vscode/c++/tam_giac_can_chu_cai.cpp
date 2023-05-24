#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int c = 'A';
    int n;
    
    cin >> n;

    for(int i = 1; i <= n; i++){
       
        for(int j = 1; j <= n - i; j++){
            cout << " ";
        }
        for(int k = 1; k <= i; k++){
            cout << static_cast<char>(c)<<" ";
            c ++;
        }
        cout << endl;
        
    }
}
