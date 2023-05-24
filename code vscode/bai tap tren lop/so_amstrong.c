#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int countDigit (int num) {
    int count = 0;
    while (num > 0)
    {
        num /= 10;
        count++;
    }
    return count;
}    

int isAmstrong (int num) {
    int numDigit = countDigit(num);
    int sum = 0;
    int digit = 0;
    int tmp = num;
    while (tmp > 0)
    {
        digit = tmp % 10;
        tmp /= 10;
        sum += pow(digit, numDigit);
    }
    
    if (sum == num)
        return 1;
    return 0;
}
int main() {
    int n;
    printf("nhap n: ");
    scanf("%d", &n);

    if (isAmstrong(n) == 1)
        printf("yes");
    else
        printf("no");
    return 0;
}