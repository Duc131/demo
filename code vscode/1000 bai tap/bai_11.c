#include <stdio.h>
#include <conio.h>

int main() {
    int n;
    printf("nhap n: ");
    scanf("%d", &n);

    int i = 1;
    long long s = 0, p = 1;
    while(i <= n) {
        p *= i;
        s += p;
        i++;
    }
    printf("tong la: %lld\n", s);
    getch();
    return 0;
}