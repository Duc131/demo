#include <stdio.h>
#include <conio.h>

int main() {
    int n;
    printf("nhap n: ");
    scanf("%d", &n);

    int i = 1;
    double s = 0;
    while (i <= n) {
        s += (float)1/i;
        i++;
    }

    printf("tong cua day 1 + 1/2 + ... + 1/%d la %.2lf", n ,s);
    getch();
    return 0;
}