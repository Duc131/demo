#include <stdio.h>
#include <math.h>

int factorial(int n) {
    int sum = 1;

    int i;
    for(i = 1; i <= n ; i++) {
        sum *= i;
    }
    return sum;
}
int main() {
    long long n;
    printf("nhap n: ");
    scanf("%lld", &n);

    long long x;
    printf("nhap x: ");
    scanf("%lld", &x);

    int i;
    long long sum1 = 0;
    long long product = 1;
    double t = 0;
    for (i = 0; i <= n ; i++) {
        product = factorial(2*i + 1);
        sum1 = pow(x, 2*i + 1);
        t += (float)sum1 / product;
    }
    double s = t + 1;
    printf("tong la: %.2lf\n", s);
    return 0;
}