#include <stdio.h>
#include <math.h>
#include <conio.h>

int main() {
    long long n;
    printf("nhap n: ");
    scanf("%d", &n);

    int i;
    long long sum = 0;
    double t = 0;

    for (i = 1; i <= n ; i++) {
        sum += i;
        t += (float)1 / sum;
    }
    printf("tong la: %.2lf\n", t);

    getch();
    return 0;
}