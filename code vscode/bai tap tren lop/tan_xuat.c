#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char sentence[100];
int freq[5] = {0}; // mang luu tan xuat xuat hien cua cac nguyen am a, e, i, o, u
/* de tranh viec su dung gia tri rac va dam bao rang cac phan tu
cua mang deu co gia tri ban dau la 0. Nen ta su dung {0} de khoi
tao gia tri ban dau cua mang
*/

// NULL là '\0'
// ham kiem tra xem mot ky tu co phai nguyen am khong
int is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

// ham dem tan xuat xuat hien cua cac nguyen am trong mot cau
void count_vowels(char sentence[], int freq[]) { // sentence là một mảng ký tự, không phải một mảng các con trỏ. nên không dùng char*
    int len = strlen(sentence); // len la length
    int i;
    for (i = 0; i < len; i++) {
        if (is_vowel(sentence[i])) {
            switch (sentence[i]) {
                case 'a':
                    freq[0]++;
                    break;
                case 'e':
                    freq[1]++;
                    break;
                case 'i':
                    freq[2]++;
                    break;
                case 'o':
                    freq[3]++;
                    break;
                case 'u':
                    freq[4]++;
                    break;
                case 'A':
                    freq[0]++;
                    break;
                case 'E':
                    freq[1]++;
                    break;
                case 'I':
                    freq[2]++;
                    break;
                case 'O':
                    freq[3]++;
                    break;
                case 'U':
                    freq[4]++;
                    break; 
            }
        }
    }
}
int main() {
    char choice;
    int a = 0, e = 0, i = 0, o = 0, u = 0;
    printf("Chuong trinh thong ke cac nguyen am a,e,i,o,u\n");

    do {
        printf("Moi ban nhap mot cau: ");
        fgets(sentence, 100, stdin);// nhập câu
        count_vowels(sentence, freq);
        
        printf("Thong ke: a(%d), e(%d), i(%d), o(%d), u(%d)\n",freq[0],freq[1],freq[2],freq[3],freq[4]);
        //luu du lieu 
		a += freq[0];
		e += freq[1];
		i += freq[2];
		o += freq[3];
		u += freq[4];
       
        memset(freq, 0, sizeof(freq));// giải phóng fred
        printf("Ban co muon tiep tuc nua khong (Y/N)? ");
        scanf(" %c", &choice);
        getchar(); 
        if(choice == 'N' || choice == 'n') {
            printf("Thong ke tong hop: a(%d), e(%d), i(%d), o(%d), u(%d)\n", a, e, i, o, u);
            break;
        }
    } while (choice == 'y' || choice == 'Y');
    
    return 0;
}