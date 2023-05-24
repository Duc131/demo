#include <stdio.h>
#include <conio.h>
#include <math.h>

int main() {
    int n;
    printf("nhap n: ");
    scanf("%d", &n);

    int i = 1;
    long long s = 0;

    while (i <= n) {
        s += pow(i, 2);
        i++;
    }
    
    printf("tong cua day 1^2 + 2^2 + ... + %d^2 la: %lld\n", n, s);
    getch();
    return 0;
}