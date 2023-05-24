#include <stdio.h>


int main() {
    int pa = 9000000; // tiền nuỗi bản thân mỗi tháng
    int pd = 3600000; // tiền cấp dưỡng

    long long m; // thu nhap hang nam
    printf("Your income of this year: ");
    scanf("%lld", &m);

    int n;
    printf("Number of dependent: ");
    scanf("%d", &n);

    long long tf = 12*(pa + n * pd); // thu nhập miễn thuế hàng năm
    printf("Tax-free income: %d\n", tf);

    long ti = m - tf;
    

    if(ti <= 0) {
        printf("Taxable income: 0\n");
        printf("Income tax: 0\n");
    } else if( ti > 0 && ti <= 5000000) {
        printf("Taxable income: %d\n", ti);
        printf("Income tax: %d\n", ti * 5 / 100);

    } else if(ti > 5000000 && ti <= 10000000) {
        printf("Taxable income: %d\n", ti);
        printf("Income tax: %d\n", ti * 10 / 100);

    } else if(ti > 10000000 && ti <= 18000000) {
        printf("Taxable income: %d\n", ti);
        printf("Income tax: %d\n", ti * 15 / 100);

    } else {
        printf("Taxable income: %ld\n", ti);
        printf("Income tax: %ld\n", ti * 20 / 100);

    }
    
    return 0;
}