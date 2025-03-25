#include<iostream>
#include<iostream>
using namespace std;

//1. Khai báo lớp Phân Số
class PhanSo
{
    private:
        int tuso;
        int mauso;
    public:
        void Nhap();
        void Xuat();
        PhanSo Tong(PhanSo& ps);
        PhanSo Hieu(PhanSo& ps);
        PhanSo Tich(PhanSo& ps);
        PhanSo Thuong(PhanSo& ps);
        int UCLN(int a, int b);
        void Rutgon();
};
 
//2. Khai báo hàm Nhập
void PhanSo::Nhap()
{
    cout << "Nhập tử số: ";
    while(!(cin >> tuso))
    {
        cout << "Nhập lại tử số: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cout << "Nhập mẫu số: ";
    while(true)
    {
        if(!(cin >> mauso))
        {
            cout << "Nhập lại mẫu số: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }else if(mauso == 0)
        {
            cout << "Nhập lại mẫu số khác 0: "; 
        }
        else 
        {
            break;
        }
    }
}

//3. Khai báo hàm Xuất
void PhanSo::Xuat()
{
    cout << tuso << "/" << mauso << endl;
}

//4. Khai báo hàm Tổng
PhanSo PhanSo::Tong(PhanSo &ps2)
{
    PhanSo temp;
    temp.tuso = tuso * ps2.mauso + mauso * ps2.tuso;
    temp.mauso = mauso * ps2.mauso;
    temp.Rutgon();
    return temp;
}

//5. Khai báo hàm Hiệu
PhanSo PhanSo::Hieu(PhanSo&ps2)
{
    PhanSo temp;
    temp.tuso = tuso * ps2.mauso - mauso * ps2.tuso;
    temp.mauso = mauso * ps2.mauso;
    temp.Rutgon();
    return temp;
}

//6. Khai báo hàm Tích
PhanSo PhanSo::Tich(PhanSo&ps2)
{
    PhanSo temp;
    temp.tuso = tuso * ps2.tuso;
    temp.mauso = mauso * ps2.mauso;
    temp.Rutgon();
    return temp;
}

//7. Khai báo hàm Thương
PhanSo PhanSo::Thuong(PhanSo&ps2)
{
    PhanSo temp;
    temp.tuso = tuso * ps2.mauso;
    temp.mauso = mauso * ps2.tuso;
    temp.Rutgon();
    return temp;
}

//8. Khai báo hàm tính ước chung lớn nhất
int PhanSo::UCLN(int a, int b)
{
    while(b!=0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

//9. Khai báo hàm Rút gọn Phân Số
void PhanSo::Rutgon()
{
    int ucln = UCLN(tuso, mauso);
    tuso = tuso / ucln;
    mauso = mauso / ucln;
}

//10. Hàm chính
int main()
{
    PhanSo ps1, ps2, kq;
    cout << "Nhập phân số thứ nhất: " << endl;
    ps1.Nhap();
    cout << "Nhập phân số thứ hai: " << endl;
    ps2.Nhap();

    kq = ps1.Tong(ps2);
    cout << "Tổng của hai phân số: ";
    kq.Xuat();

    kq = ps1.Hieu(ps2);
    cout << "Hiệu của hai phân số: ";
    kq.Xuat();

    kq = ps1.Tich(ps2);
    cout << "Tích của hai phân số: ";
    kq.Xuat();

    kq = ps1.Thuong(ps2);
    cout << "Thương của hai phân số: ";
    kq.Xuat();

    return 0;
}