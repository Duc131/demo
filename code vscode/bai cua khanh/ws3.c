#include <stdio.h>
#include <stdlib.h> 

#define MAX_N 5
#define MAX_M 5

/*chứa các hàm cơ bản liên quan đến việc
quản lý bộ nhớ và chuyển đổi kiểu dữ liệu
*/ 
int n, m;
float a[MAX_M][MAX_N]; //do lưu trữ số thực nên để float

// m dòng, n cột
void input_size(int *m, int *n) {
    do {
        printf("nhap so hang: ");
        scanf("%d", m);
    } while (*m < 2 || *m > MAX_M);

    do {
        printf("nhap so cot: ");
        scanf("%d", n);
    } while (*n < 2 || *n > MAX_N);
}

void input_matrix(float a[][MAX_N], int m, int n) {
    printf("nhap cac phan tu cua ma tran:\n");
    int i;
    for (i = 0; i < m; i++) {
        int j;
        for (j = 0; j < n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }
}

void print_matrix(float a[][MAX_N], int m, int n) {
    printf("ma tran vua nhap:\n");
    int i;
    for (i = 0; i < m; i++) {
        int j;
        for (j = 0; j < n; j++) {
            printf("%.2f ", a[i][j]);
        }
        printf("\n");
    }
}

void sort_matrix(float a[][MAX_N], int m, int n) {
    int i;
    for (i = 0; i < m; i++) {
        int j;
        for (j = 0; j < n - 1; j++) { // j < n - 1
            int k;
            for (k = j + 1; k < n; k++) {
                if (a[i][j] > a[i][k]) {
                    float temp = a[i][j];
                    a[i][j] = a[i][k];
                    a[i][k] = temp;
                }
            }
        }
    }
    printf("ma tran sau khi sap xep la:\n");
    print_matrix(a, m, n);
}

float average_even(float a[][MAX_N], int m, int n) {
    int count = 0;
    float sum = 0.0f;

    int i;
    for (i = 0; i < m; i++) {
        int j;
        for (j = 0; j < n; j++) {
            if ((int)a[i][j] % 2 == 0) {
                count++;
                sum += a[i][j];
            }
        }
    }
    if (count == 0)
        return 0.0f;

    return sum / count;
}

void find_saddle_point(float a[][MAX_N], int m, int n) {
    int found = 0; // không tìm thấy điểm yên ngựa ban đầu
    int i;
    for(i = 0; i < m; i++) {
        float min_on_row = a[i][0];
        int min_col_idx = 0;

        int j;
        for(j = 0; j < n; j++) { // tìm phần tử nhỏ nhất trên hàng i
            if(a[i][j] < min_on_row) {
                min_on_row = a[i][j];
                min_col_idx = j;
            }
        }

        //kiem tra co lon nhat tren cot khong
        int is_saddle = 1;

        int k;
        for (k = 0; k < m; k++) {
            if (a[k][min_col_idx] > min_on_row) {
                is_saddle = 0;
                break;
            }
        }

        if (is_saddle) { //is_saddle == 1
            printf("diem yen ngua la: a[%d][%d] = %.2f\n", i, min_col_idx, min_on_row);
            found = 1;
        }
    }
    if (!found)
        printf("khong tim thay diem yen ngua trong ma tran\n");
}

// void find_saddle_point(float a[][MAX_N], int m, int n) {
//     int saddle_row, saddle_col, saddle_found;
//     float min_in_row;

//     saddle_found = 0;  // Không tìm thấy điểm yên ngựa ban đầu

//     // Duyệt qua từng hàng của mảng
//     for (int i = 0; i < m; i++) {
//         min_in_row = a[i][0];  // Gán giá trị đầu tiên của hàng cho biến min_in_row

//         // Tìm phần tử nhỏ nhất trên hàng i
//         for (int j = 1; j < n; j++) {
//             if (a[i][j] < min_in_row) {
//                 min_in_row = a[i][j];
//             }
//         }

//         // Kiểm tra xem phần tử nhỏ nhất trên hàng i có phải là phần tử lớn nhất trên cột của nó hay không
//         for (int j = 0; j < n; j++) {
//             if (a[i][j] == min_in_row) {
//                 // Tìm thấy phần tử nhỏ nhất trên hàng i, kiểm tra nó có phải là phần tử lớn nhất trên cột của nó hay không
//                 saddle_col = j;
//                 for (int k = 0; k < m; k++) {
//                     if (a[k][saddle_col] > min_in_row) {
//                         // Phần tử không phải là phần tử lớn nhất trên cột, thoát khỏi vòng lặp
//                         goto outerloop;
//                     }
//                 }
//                 // Tìm thấy điểm yên ngựa
//                 saddle_row = i;
//                 saddle_found = 1;
//                 break;
//             }
//         }
//     }

// outerloop:
//     if (saddle_found) {
//         printf("Diem yen ngua la: a[%d][%d] = %.2f\n", saddle_row, saddle_col, a[saddle_row][saddle_col]);
//     } else {
//         printf("Khong tim thay diem yen ngua trong mang.\n");
//     }
// }

int main() {
    int choice;
    while (1) {
        printf("chon chuc nang\n");
        printf("1. nhap ma tran\n");
        printf("2. xuat ma tran\n");
        printf("3. sap xep ma tran\n");
        printf("4. tinh trung binh cong cac so chan trong ma tran\n");
        printf("5. tim diem yen ngua\n");
        printf("0. thoat chuong trinh\n");

        printf("nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                input_size(&m, &n);
                input_matrix(a, m, n);
                printf("\n");
                break;
            case 2:
                printf("mang vua nhap la:\n");
                print_matrix(a, m, n);
                printf("\n");
                break;
            case 3:
                sort_matrix(a, m, n);
                printf("\n");
                break;
            case 4:
                printf("trung binh cong cac so chan: %.2f\n", average_even(a, m, n));
                printf("\n");
                break;
            case 5:
                find_saddle_point(a, m, n);
                printf("\n");
                break;
            case 0:
                printf("da thoat chuong trinh\n");
                return 0; // cách thoát chương trình an toàn
                // exit(0) sẽ không giải phóng tài nguyên, ghi log, lưu trạng thái,... -> không an toàn
            
            default: 
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    }

    return 0;
}