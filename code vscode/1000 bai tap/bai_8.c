#include <stdio.h>
#include <conio.h>

int main() {
    int n;
    printf("nhap n: ");
    scanf("%d", &n);

    int i = 0;
    double s = 0;
    while (i <= n) {
        s += (float)(2*i + 1)/ (2*i + 2);
        i++;
    }
    printf("tong la: %.2lf", s);
    getch();
    return 0;
}