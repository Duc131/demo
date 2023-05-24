#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int sum = 0;
    int temp = n;
    while(temp > 0) {
        int digit;
        digit = temp % 10;
        sum += digit;
        temp /= 10;
        
    }
    if (sum % 10 == 0) 
        printf("%d la so ss dep\n", n);
    else 
		printf("%d khong la so dep\n", n);   
    
    return 0;
}