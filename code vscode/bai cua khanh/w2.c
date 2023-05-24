#include <stdio.h>

#define size_of_array 20
int n;
int a[size_of_array];

// hàm nhập mảng
void input_array(int a[], int *n) {
    printf("nhap so phan tu cua mang (toi da 20): ");
    scanf("%d", n);
    if (*n < 3 || *n > size_of_array) {
        printf("So phan tu vuot qua gioi han.\n");
        return;
    }

    int i;
    for (i = 0; i < *n; i++) {
    printf("nhap phan tu thu %d: ", i + 1);
    scanf("%d", &a[i]);
    }
}

//hàm xuất mảng
void output_array(int a[], int n) {
    printf("mang gom cac phan tu: ");

    int i;
    for (i = 0; i < n; i++) 
        printf("%d ", a[i]);

    printf("\n");
}
// số hoàn hảo là một số nguyên dương lớn hơn 0 và có tổng các ước (ngoại trừ số đó) bằng chính nó.
void findPerfectNumber(int a[], int n) { 
    printf("so hoan hao trong mang: ");
    int i;
    int sumOfDigit;
    int foundPerfectNumber = 0;
    for (i = 0; i < n; i++) {
        int j;
        sumOfDigit = 0;
        for (j = 1; j < a[i]; j++) {
            if(a[i] % j == 0)
                sumOfDigit += j;
        }
        if(sumOfDigit == a[i]) {
            printf("%d ", a[i]);
            foundPerfectNumber = 1;
        }
    }
    

    if(!foundPerfectNumber) // neu foundPerfectNumber khong bang 1
        printf("khong tim thay");
    
    printf("\n");
}

void searchNumber(int a[], int n, int x) {
    int found = 0;
    int closest = 0; // lưu giá trị vị trí của phần tử gần với x nhất
    int closestDiff = abs(a[0] - x); // lưu giá trị khoảng cách giữa x và phần tử gần với x nhất
    int i;
    for (i = 0; i < n; i++) {
        if (a[i] == x) {
            printf("tim thay %d o vi tri %d trong mang\n", x, i);
            found = 1;
        } else if (abs(a[i] - x) < closestDiff) {
            closestDiff = abs(a[i] - x);
            closest = i;
        }
    }
    if (!found)
        printf("khong tim thay %d trong mang tuy nhien phan tu %d o vi tri %d thi gan voi %d nhat\n", x, a[closest], closest, x);
}
int main() {
    int choice;
    int x;

    char choice1 = 'y';
    while (1) { // điều kiện luôn đúng
        printf("1. Nhap mang\n");
        printf("2. Xuat mang\n");
        printf("3. Tim so hoan hao trong mang\n");
        printf("4. Tim kiem phan tu trong mang\n");
        printf("5. Thoat chuong trinh\n");
        printf("Moi ban chon (1-5): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                input_array(a, &n);
                break;
            case 2:
                output_array(a, n);
                break;
            case 3:
                findPerfectNumber(a, n);
                break;
            case 4:
                
                do {
                    printf("nhap so can tim: ");
                    scanf("%d", &x);
                    searchNumber(a, n, x);

                    printf("Do you want to continue? y/n: ");
                    scanf(" %c", &choice1);
                } while (choice1 == 'y');               
                
                break;
            case 0:
                printf("ban da thoat chuong trinh.\n");
                return 0;

            default:
                printf("Chon sai chuc nang. Hay chon lai.\n");
                break;
        }
    }
    return 0;
}