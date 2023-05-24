#include <stdio.h>
#include <conio.h>
#include <math.h>

int main() {
    int x;
    printf("nhap x: ");
    scanf("%d", &x);

    int n;
    printf("nhap n: ");
    scanf("%d", &n);
    double s = pow(x,(float)n);
    
    printf("tong la: %.2lf", s);
    getch();
    return 0;
}