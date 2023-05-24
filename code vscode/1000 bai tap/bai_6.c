#include <stdio.h>
#include <conio.h>

int main() {
    int n;
    printf("nhap n: ");
    scanf("%d", &n);

    int i = 1;
    double s = 0;
    while(i <= n) {
        s += 1.0/(i * (i + 1));
        i++;
    }
    printf("tong cua day la %.2lf", s);
    getch();
    return 0;
}