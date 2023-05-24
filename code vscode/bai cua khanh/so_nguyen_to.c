#include <stdio.h>
#include <math.h>

int nhap(){
	int x;
	do {
		printf("nhap so phan tu: ");
	    scanf("%d",&x);
	} while(x<=0);					//nhap vao 1 so x thoa man >=0, sai thi nhap lai
	return x;						// tra ve so vua nhap thong qua ten ham nhap()
}
int checkPerfect(int x){			// kien tra co phai la so hh 0? neu hh tra ve return 1		
	int i;
    int dem = 0;
	for(i = 2; i<=sqrt(x); i++)
		if(x%i==0) 
            dem++;
	if(dem==0) 
        return 1;					// la so nt
	else 		
        return 0;					//0 la so nt
	
	if 
}
void PrintKQ(int n){				// in ra cac so hoan hao <n
	int i;
	for(i=2; i<=n; i++)
		if(checkPerfect(i) == 1) 
            printf("%d ",i);
}
int main(){
	int n;
	n = nhap();
	PrintKQ(n);

}