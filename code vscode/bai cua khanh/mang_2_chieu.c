#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Menu(){
	int chon;
	printf("\n1. Nhap ma tran: ");
	printf("\n2. Hien ma tran: ");
	printf("\n3. Tim so chinh phuong: ");
	printf("\n4. Sap xep giam tren tung cot: ");
	printf("\n5. Thoat: ");
	printf("\nNhap lua chon cua ban: ");
	scanf("%d",&chon);
	return (chon);
}
void Nhap(int a[][10],int *h,int *c){
	int i, j;
	printf("\nNhap vao so hang,cot cua ma tran: ");
	scanf("%d%d",h,c);
    for (i = 0; i < *h; i++) {
        for (j=0;j < *c;j++) {
            printf("\n Nhap a[%d][%d]= ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
}
void Hien(int a[][10], int h, int c){
	int i, j;
	for(i = 0; i < h; i++) {
		for(j = 0; j < c; j++)
		    printf("%d\t",a[i][j]);  //cac cot cach nhau mot tab
	    printf("\n");
	}
		
}
int checkSquare(int x){
	int b = sqrt(x);
	if(x == b * b)
        return 1;
	else 
        return 0;
	
}
void Insochinhphuong(int a[][10], int h,int c){
	int i,j;
	for(i=0;i<h;i++)
	for(j=0;j<c;j++)
		if(checkSquare(a[i][j])==1)printf("%d ",a[i][j]);
}
void Sapxep(int a[][10],int h,int c){
	int i,j,k;
	for(i=0;i<c;i++)
		for(j=0;j<h-1;j++)
		for(k=j+1;k<h;k++)
			if(a[j][i]<a[k][i]){
				int tam=a[j][i];
					a[j][i]=a[k][i];
					a[k][i]=tam;
			}
	printf("\nMa tran sap xep:\n");
	Hien(a,h,c);
}
int main(int argc, char *argv[]) {
	int  chon,sh,sc,a[10][10];
	do {
		chon=Menu();
		switch(chon){
			case 1:Nhap(a,&sh,&sc);
				break;
			case 2:Hien(a,sh,sc);
				break;
			case 3:Insochinhphuong(a,sh,sc);
				break;
			case 4:Sapxep(a,sh,sc);
				break;
		}
	}while(chon!=5);
	return 0;
}