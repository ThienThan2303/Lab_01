#include <iostream>
using namespace std;

// Struct Phân Số
struct PhanSo {
    int tuso;
    int mauso;
};

// 1. Hàm Nhập Phân Số
void NhapPhanSo(PhanSo &ps) {
    cout << "Nhập tử số: ";
    while (!(cin >> ps.tuso)) {
        cout << "Nhập lại tử số: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cout << "Nhập mẫu số: ";
    while (true) {
        if (!(cin >> ps.mauso)) {
            cout << "Nhập lại mẫu số: ";
            cin.clear();
            cin.ignore(1000, '\n');
        } else if (ps.mauso == 0) {
            cout << "Nhập lại mẫu số khác 0: ";
        } else {
            break;
        }
    }
}

// 2. Hàm tính Ước Chung Lớn Nhất (UCLN)
int UCLN(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

//3. Hàm Rút Gọn Phân Số
void RutGonPhanSo(PhanSo &ps) {
    int ucln = UCLN(ps.tuso, ps.mauso);
    ps.tuso = ps.tuso / ucln;
    ps.mauso = ps.mauso / ucln;
}

//4. Hàm Xuất Phân Số
void XuatPhanSo(PhanSo ps) {
    RutGonPhanSo(ps);
    if (ps.mauso == 1) {
        cout << ps.tuso << endl;
    } else {
        cout << ps.tuso << "/" << ps.mauso << endl;
    }
}

// 5. Hàm chính
int main() {
    PhanSo ps1;
    cout << "Nhập phân số: " << endl;
    NhapPhanSo(ps1);
    cout << "Phân số được rút gọn là: ";
    XuatPhanSo(ps1);
    return 0;
}
