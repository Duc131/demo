#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int is_valid_date(int day, int month, int year) {
    if (year < 0) {
        return 0;
    }
    if (month < 1 || month > 12) {
        return 0;
    }
    if (day < 1 || day > 31) {
        return 0;
    }
    if (month == 2) {
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
            if (day > 29) {
                return 0;
            }
        } else {
            if (day > 28) {
                return 0;
            }
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) {
            return 0;
        }
    }

    return 1;
}

int is_prime(int n) {
    if (n < 2)
        return 0;
    int i;
    for (i = 2; i < sqrt(n); i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void min_max_digits(int num, int *min_digit, int *max_digit) {
    // Set min_digit and max_digit to the first digit of the number
    *min_digit = *max_digit = num % 10;
    num /= 10;

    // Find the min and max digit in the remaining digits
    while (num > 0) {
        int digit = num % 10;
        if (digit < *min_digit) {
            *min_digit = digit;
        } else if (digit > *max_digit) {
            *max_digit = digit;
        }
        num /= 10;
    }
}

int main() {
    int n;
    int day, month, year;
    int x;
    int num, min_digit, max_digit;
    int choice;


    while (1) {
        printf("1-Fibonacci sequence\n");
        printf("2-Check a date\n");
        printf("3-Process primes\n");
        printf("4-Print min, max digit in an integer\n");
        printf("5-Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:    
                printf("Enter a positive integer: ");
                scanf("%d", &n);

                printf("The first %d Fibonacci numbers are: ", n);
                int i;
                for (i = 0; i < n; i++) {
                    printf("%d ", fibonacci(i));
                }
                printf("\n");
                printf("\n");
                break;
            case 2:
                printf("Enter a date (DD MM YYYY): ");
                scanf("%d %d %d", &day, &month, &year);

                if (is_valid_date(day, month, year)) {
                    printf("The entered date is valid.\n");
                } else {
                    printf("The entered date is invalid.\n");
                }
                printf("\n");
                break;
            case 3:
                printf("Enter a positive integer: ");
                scanf("%d", &x);

                if (is_prime(x)) {
                    printf("The entered number is prime.\n");
                } else {
                    printf("The entered number is not prime.\n");
                }
                printf("\n");
                break;
            case 4:

                printf("Enter a positive integer: ");
                scanf("%d", &num);

                min_max_digits(num, &min_digit, &max_digit);

                printf("Minimum digit: %d\n", min_digit);
                printf("Maximum digit: %d\n", max_digit);
                printf("\n");
                break;
            case 5:
                printf("Quit program\n");
                return 0;
            default:
                printf("Error, please try again\n");
                printf("\n");
                break;
        }
    }
    return 0;
}