#include <stdio.h>
#include <math.h>
#include <conio.h>
int main() {
    long long n;
    printf("nhap n: ");
    scanf("%d", &n);
    long long x;
    printf("nhap x: ");
    scanf("%d", &x);

    int i;
    long long sum = 0;
    for (i = 1; i <= n ; i++) {
        sum += pow(x,i);
    }
    printf("tong la: %lld\n", sum);

    getch();
    return 0;
}