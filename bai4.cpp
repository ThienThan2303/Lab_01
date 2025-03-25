#include <iostream>
#include <cmath>  
using namespace std;

//1. Khai báo hàm Nhập
double nhapSoThuc() {
    double x;
    while (true) {
        cout << "Nhập x: ";
        cin >> x;

        if (cin.fail()) {  // Nếu nhập sai (ví dụ nhập ký tự)
            cout << "Lỗi: Vui lòng nhập số hợp lệ!\n";
            cin.clear();
            cin.ignore(10000, '\n');
        } else {
            return x;
        }
    }
}

//2. Hàm tính sinx 
double tinhSin(double x) {
    double sinX = 0.0;
    double term = x;  
    int n = 1; 
    double tuSo = x; 
    double mauSo = 1.0; 

    while (fabs(term) >= 0.00001) {  
        sinX += term;  
        tuSo *= (-1) * x * x; 
        mauSo *= (2 * n) * (2 * n + 1); 
        term = tuSo / mauSo; 
        n++; 
    }

    return sinX;
}

int main() {
    double x = nhapSoThuc(); 
    double sinX = tinhSin(x); 

    cout << "sin(" << x << ") = " << sinX << endl; 
    return 0;
}
