#include <stdio.h>
#include <conio.h>

int main() {
    int n;
    printf("nhap n: ");
    scanf("%d", &n);
    int i = 1;
    long long s = 0;

    while (i <= n) {
        s += i;
        i++;

    }

    printf("tong cua day 1 + 2 + ... + %d la: %lld\n", n, s);
    getch();
    return 0;
}