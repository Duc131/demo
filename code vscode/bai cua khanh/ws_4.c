#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000



// nhap mang
void input_array(float a[], int *n) {
    printf("nhap so phan tu cua mang: ");
    scanf("%d", n);

    int i;
    for (i = 0; i < *n; i++) {
        printf("nhap phan tu thu %d: ", i + 1);
        scanf("%f", &a[i]);
    }

}

// tinh gia tri trung binh va vi tri lon nhat
void array_stats(float a[], int n) {
    int i;
    float sum = 0;
    int max_position = 0;
    float avg = 0;
    for (i = 0; i < n; i++) {
        sum += a[i];
        if (a[i] > a[max_position])
            max_position = i;
    }
    avg = sum / n;
    printf("gia tri trung binh cua tat ca cac so trong mang la: %.2f\n", avg);
    printf("vi tri cua so lon nhat la %.2f trong mang la: %d\n", a[max_position], max_position + 1);
}

//ham nhap chuoi 
void input_string(char str[]) {
    // do ham fgets doc ky tu Enter lam chuoi va ket thuc viec doc chuoi. Nen bat buoc phai xoa '\n' thi chuong trinh moi chay duoc
    getchar(); // doc bo qua kí tu Enter trong bo dem dau vao

    printf("nhap chuoi: ");
    fgets(str, MAX_SIZE, stdin); // ham nay doc duoc ca khoang trang va gioi han do dai chuoi dau vao
    str[strcspn(str, "\n")] = '\0'; // xoa '\n'

    
}

// ham dao nguoc chuoi
void reverseString(char str[]) {
    printf("chuoi dao nguoc: ");
    int i;
    for (i = strlen(str) - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

// ham kiem tra chuoi doi xung
int isPalindrome(char str[]) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        int j = strlen(str) - 1 - i;
        if (str[i] != str[j])
            return 0;
    }
    return 1;
}

// dem ky tu so
int countDigit(char str[]) {
    int count = 0;
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (isdigit(str[i])) {
            count++;
        }
    }
    return count;
}

int main() {
	int n;
	float a[MAX_SIZE];
	char str[MAX_SIZE];
    int choice;
//    char *filename1 = "a.txt";
	char filename1[MAX_SIZE];
	char *filename2 = "b.txt";
	

	FILE *file2 = fopen(filename2, "w");
	
	int foundNonNumeric = 0; //khoi tao bien de kiem tra ki tu khong phai so
    while (1) {
        printf("1. nhap mot mang va viet ra gia tri trung binh cua tat ca cac so, tim ra vi tri cua so lon nhat trong mang\n");
        printf("2. nhap mot chuoi va dao nguoc chuoi nay, in ra chuoi co doi xung hay khong, in ra co bao nhieu ky tu so trong chuoi\n");
        printf("3. nhap ten tep ex a.txt mo va doc noi dung, neu tep hoan toan la so, hay tim so lon nhat va viet tep ex b.txt ra\n");
        printf("4. exit\n");

        printf("nhap lua chon cua ban (1 - 4): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                input_array(a, &n);
                array_stats(a, n);
                printf("\n");
                break;
            case 2:
                input_string(str);
                reverseString(str);

                if (isPalindrome(str))
                    printf("chuoi nay doi xung\n");
                else 
                    printf("chuoi nay khong doi xung\n");
                
                int count = countDigit(str);
                printf("chuoi co %d ky tu so\n", count);
                printf("\n");
                break;
            case 3:
			    printf("nhap ten tep: ");
			    scanf("%s", filename1);
			    FILE *file1 = fopen(filename1, "r"); //mo ten tep vua moi doc
			    
			    if (file1 == NULL) {
			        printf("Error: Unable to open file %s\n\n", filename1);
			        foundNonNumeric = 1;
			        break;
			    }
			    
			    int largest_number = 0;
			    char c;
			    while ((c = fgetc(file1)) != EOF) { //fgetc: doc tung ky tu
					printf("%c", c);
				}
				printf("\n");
				/* sau khi doc het file, con tro dang o cuoi file va khong doc
				bat ki ky tu nao trong lan doc tiep theo */
			    
				fseek(file1, 0, SEEK_SET); //dua con tro file den vi tri duoc chi dinh boi tham so offset
				// rewind(file1); // dua con tro file den vi tri dau file
				
			    while ((c = fgetc(file1)) != EOF) {
			        if (isdigit(c)) {
			            int number = c - '0';
			            while (isdigit(c = fgetc(file1))) {
			                number = number * 10 + (c - '0');
			            }
			            if (number > largest_number) {
			                largest_number = number;
			            }
			        }
			        else if (!isspace(c)) {
			            printf("Error: File %s contains non-numeric characters.\n\n", filename1);
			            foundNonNumeric = 1; 
						break;
			        }
			    }
			    
			    if (largest_number == 0) {
			        printf("Error: File %s does not contain any numbers.\n\n", filename1);
			        foundNonNumeric = 1;
					break;
			    }
			    
			    if (foundNonNumeric) { // khong can thuc hien cac cau lenh sau
					fclose(file1);
					fclose(file2);
					continue; // quay tro lai vong lap while
				}
				
				printf("The largest number is: %d\n", largest_number);
				
			    fprintf(file2, "%d", largest_number);
			    
			    fclose(file1);
			    fclose(file2);
			    
			    printf("The largest number has been written to file %s\n", filename2);
			    printf("\n");
			    break;
            case 4:
                printf("da thoat chuong trinh\n");
                return 0;
        }
    }
    return 0;
}