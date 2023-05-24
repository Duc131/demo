#include <stdio.h>
#include <math.h>

int factorial(int n) {
    int product = 1;
    int i;
    for (i = 1; i <= n; i++) {
        product *= i; 
    }
    return product;
}

int main() {
    long long n;
    printf("nhap n: ");
    scanf("%lld", &n);

    long long x;
    printf("nhap x: ");
    scanf("%lld", &x);

    int i;
    long long sum1 = 1;
    long long sum2 = 0;
    double t = 0;
    for (i = 0; i <= n; i++) {
        sum1 = factorial(2*i);
        sum2 = pow(x, 2*i);
        t += (float)sum2 / sum1;

    }
    printf("tong la: %.2lf\n", t);
    return 0;
}