#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Diem 
{
    float giuaKy, cuoiKy;

    void nhap() 
    {
        cout << "Nhap diem giua ki: ";
        cin >> giuaKy;

        cout << "Nhap diem cuoi ki: ";
        cin >> cuoiKy;
    }

    float trungBinh() 
    {
        return 0.3*giuaKy + 0.7*cuoiKy;
    }

    string xepLoai()
    {
        float tb = trungBinh();
        if (tb < 4)
            return "D";
        else if (4 <= tb && tb < 6)
            return "C";
        else if (6 <= tb && tb < 8)
            return "B";
        else 
            return "A";
    }

    void xuat() 
    {
        cout << "Diem giua ky: " << giuaKy << endl;
        cout << "Diem cuoi ky: " << cuoiKy << endl;
        cout << "Trung binh: " << trungBinh() << endl;
        cout << "Xep hang: " << xepLoai() << endl;
    }
};

struct sinhVien
{
    string MSSV;
    int namSinh;
    Diem diem;

    void nhap()
    {
        cout << "MSSV: "; 
        cin >> MSSV;
        cout << "Nam Sinh: ";
        cin >> namSinh;
        diem.nhap();
        cout << endl;
    }

    void xuat() 
    {
        cout << "MSSV: " << MSSV << " | " << "Nam Sinh: " << namSinh;
        diem.xuat(); 
    }
};

sinhVien sv[1000];
int n;

int soLuongSVLonHoacBang(int nam)
{
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (sv[i].namSinh >= nam) 
            dem++;
    }
    return dem;
}

int soLuongSVLoai(string loai)
{
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (sv[i].diem.xepLoai() == loai) 
            dem++;
    }
    return dem;
}

signed main(void) {
    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        sv[i].nhap();
    }
    
    cout << "\n=== THONG TIN SINH VIEN ===\n\n";

    for (int i = 0; i < n; i++) {
        cout << "Thong tin sinh vien" << i + 1 << endl;
        sv[i].xuat();
        cout << endl;
    }

    cout << "\n=== NAM SINH >= 1999 ===\n";
    cout << "So luong: " << soLuongSVLonHoacBang(1999) << endl;

    cout << "=== XEP LOAI A && D ===\n";
    cout << "So luong A: " << soLuongSVLoai("A") << endl;
    cout << "So luong D: " << soLuongSVLoai("D") << endl << endl;

    cout << "\n=== DS STT SINH VIEN CO 4.0 < DTB < 8.0 ===\n";
    int dem = 0;
    for (int i = 0; i < n; i++) {
        float dtb = sv[i].diem.trungBinh();
        if (4 < dtb && dtb < 8) {
            dem++;
            cout << i + 1 << endl;
        }
    }
    if (dem == 0) 
        cout << "0" << endl;
    return 0;
}