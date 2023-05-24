#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Diem
{
    float giuaky, cuoiky;

    void nhap() {
        cout << "Nhap diem giua ki: "; 
        cin >> giuaky;
        cout << "Nhap diem cuoi ki: ";
        cin >> cuoiky;
    }

    float trungbinh() {
        return 0.3 * giuaky + 0.7 * cuoiky;
    }

    string xeploai() {
        float tb = trungbinh();
        if (tb < 6) return "D";
        if (4 <= tb && tb < 6) return "C";
        if (6 <= tb && tb < 8) return "B";
        return "A";
    }

    void xuat() {
        cout << "Diem giua ki: " << giuaky << endl;
        cout << "Diem cuoi ki: " << cuoiky << endl;
        cout << "Diem trung binh: " << trungbinh() << endl;
        cout << "Xep loai: " << xeploai() << endl;
    }

};

struct SinhVien
{
    string MSSV;
    int namsinh;
    Diem diem;

    void nhap() {
        cout << "MSSV: "; cin >> MSSV;
        cout << "Nam sinh: "; cin >> namsinh;
        diem.nhap();
    }
    void xuat() {
        cout << "MSSV " << MSSV << " | " << "Nam sinh " << namsinh << endl;
        diem.xuat();
    }
};

SinhVien sv[1000];
int n;

int soluongSVlonHoacbang(int nam) {
    int dem = 0;
    for (int i = 1; i <= n; i++) {
        if (sv[i].namsinh >= nam)
            dem++;
    }
    return dem;
}

int soluongSVLoai(string loai) {
    int dem = 0;
    for (int i = 1; i <= n; i++) {
        if (sv[i].diem.xeploai() == loai) 
            dem++;
    }
    return dem;
}

signed main(void) {

    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        sv[i].nhap();
    }

    cout << "\n=== THONG TIN SINH VIEN ===\n\n";

    for (int i = 1; i <= n; i++) {
        cout << "Thong tin sinh vien " << i << endl;
        sv[i].xuat();
        cout << endl;
    }

    cout << "\n=== NAM SINH >= 1999 ===\n";
    cout << "So luong: " << soluongSVlonHoacbang(1999) <<  "\n\n";

    cout << "\n=== XEP LOAI A & XEP LOAI D ===\n";
    cout << "So luong A: " << soluongSVLoai("A") << "\n";
    cout << "So luong D: " << soluongSVLoai("D") << "\n\n";

    cout << "\n=== DS STT SINH VIEN CO 4.0 < DTB < 8.0 ===\n";
    int dem = 0;
    for (int i = 1; i <= n; i++) {
        float dtb = sv[i].diem.trungbinh();
        if (4 < dtb && dtb < 8) {
            dem++;
            cout << i << endl;
        }
    }
    if (dem == 0) cout << "0";
    cout << endl;

    return 0;
}