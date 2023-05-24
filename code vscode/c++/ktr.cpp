#include <iostream>
#include <algorithm>

using namespace std;

// ham nhap day so thuc
void nhapDaySo(float a[], int &n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap so thu " << i + 1 << ": ";
        cin >> a[i];
    }
}

// ham in day so thuc
void inDaySo(float a[], int n) {

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// ham tinh gia tri trung binh cong cua cac so le va chia het cho 3
float tinhTrungBinhCong(float a[], int n) {
    int tong = 0;
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if ((int)a[i] % 2 == 1 && (int)a[i] % 3 == 0) {
            tong += a[i];
            dem++;
        }
    }
    if (dem == 0) {
        return 0;
    }
    return (float)tong / dem;
}

// ham dem so phan tu >= 5.5
int demSoPhanTu(float a[], int n) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= 5.5) {
            dem++;
        }
    }
    return dem;
}

// ham sap xep day so thuc theo chieu tang dan
void sapXepTangDan(float a[], int n) {
    sort(a, a + n);
}

int main() {
    int n;
    float a[1000];

    cout << "Nhap so phan tu cua day so: ";
    cin >> n;

    nhapDaySo(a, n);

    cout << "Day so vua nhap la: ";
    inDaySo(a, n);

    float tbCong = tinhTrungBinhCong(a, n);
    if (tbCong == 0) {
        cout << "Khong co so le chia het cho 3 trong day so." << endl;
    } else {
        cout << "Gia tri trung binh cong cua cac so le va chia het cho 3 la: " << tbCong << endl;
    }

    int dem = demSoPhanTu(a, n);
    cout << "So phan tu >= 5.5 la: " << dem << endl;

    sapXepTangDan(a, n);

    cout << "Day so sau khi sap xep la: ";
    inDaySo(a, n);

    return 0;
}
