#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[5][80];
char tmp[80];

int main() {
    system("cls"); /* xoa man hinh -> de giữ cho màn hình console
    sạch sẽ */
    int i;
    for (i = 0; i < 5; i++) 
        scanf("%s", str[i]);
    
    for (i = 0; i < 4; i++) {
        int j;
        for (j = i + 1; j < 5; j++) {
            if (strcmp(str[i], str[j]) > 0) {
                strcpy(tmp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], tmp);
            }
        }
    }

    for (i = 0; i < 5; i++) 
        printf("%s ", str[i]);
    
    printf("\n");
    system("pause");
    return 0;
}