#include <stdio.h>
//#include <fstream>

// x là khoảng cách giữa p và bán kính
int getRelPos (double x, double y, double r) {
    double d2 = x*x + y*y;
    double r2 = r*r;
    if (d2 < r2)
        return 1;
    else if (d2 == r2)
        return 0;
    return -1;
}
int main() {
    freopen("tepdulieu/input.txt", "r", stdin);
    freopen("tepdulieu/output.txt", "a", stdout);
    double x, y;
    printf("Enter the coordinates of the point P: ");
    scanf("%lf%lf", &x, &y);

    double r;
    printf("Enter the radius of the circle: ");
    do {
        scanf("%lf", &r);
    } while (r < 0);

    int result = getRelPos(x, y, r);
    if (result == 1)
        printf("The point is in the circle\n");
    else if (result == 0)
        printf("The point is on the circle\n");
    else   
        printf("The point is out of the circle\n");
    return 0;
}