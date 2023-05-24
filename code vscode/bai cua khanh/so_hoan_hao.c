// so hoan hao là một số nguyên dương lớn hơn 0 và có tổng các ước (ngoại trừ số đó) bằng chính nó.
#include<stdio.h>
int main() {
	int n;
    printf("nhap so phan tu: ");
	scanf("%d",&n);

	int i;
	for(i = 1; i <= n; i++) { 

        int j;
		int sumOfDigit=0;
		for(j = 1; j < i; j++)
			if(i % j == 0)
				sumOfDigit += j;

		if (sumOfDigit == i)
			printf("so hoan hao: %d\n", i);
	}	
    return 0;
}