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
        int UCLN(int a, int b);
        void Rutgon();
        bool sosanh(PhanSo ps2);
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
    Rutgon();
    if(mauso == 1)
        cout << tuso << endl;
    else 
        cout << tuso << "/" << mauso << endl;
}
//4. Khai báo hàm tính ước chung lớn nhất
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
//5. Khai báo hàm Rút gọn Phân Số
void PhanSo::Rutgon()
{
    int ucln = UCLN(tuso, mauso);
    tuso = tuso / ucln;
    mauso = mauso / ucln;
}
//6. Khai báo hàm So sánh
bool PhanSo::sosanh(PhanSo ps2)
{
    return (tuso*ps2.mauso > ps2.tuso * mauso);
}
//7. Hàm chính
int main()
{
    PhanSo ps1, ps2;
    cout << "Nhập phân số đầu tiên: " << endl;
    ps1.Nhap();
    cout << "Nhập phân số thứ hai: " << endl;
    ps2.Nhap();
    cout << "Phân số lớn nhất là: ";
    if(ps1.sosanh(ps2))
        ps1.Xuat();
    else if (ps2.sosanh(ps1))
        ps2.Xuat();
    else 
        ps1.Xuat();
    return 0;
}