#include <stdio.h>

int n;
double x;
char c1;
int main() {
    int m;
    short s;
    long L;
    float y;
    printf("Code of main: %u\n", &main);
    printf("Variable n, add: %u, memory size: %d\n", &n, sizeof(n));
    return 0;
}