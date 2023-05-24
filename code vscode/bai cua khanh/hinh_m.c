#include <stdio.h>

int main() {
    int n;
    printf("nhap n: ");
    scanf("%d", &n);

    int i;
    int j;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
    
    printf("\n");

    for (i = n; i >= 1; i--) {
        for (j = 1; j <= n - i; j++)
            printf("  ");
            
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    printf("\n");

    for (i = 1; i <= n; i++) {
        for (j = n; j > i; j--) {
            printf("  ");
        }
        for (j = i; j >= 1; j--) {
            printf("%d ", j);
        }
    printf("\n");
    }

    printf("\n");   

    for (i = n; i >= 1; i--) {
        for (j = i; j >= 1; j--) {
            printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}