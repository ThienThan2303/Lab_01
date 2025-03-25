#include <iostream>
using namespace std;

// Hàm đếm số lần mảng A xuất hiện liên tiếp trong mảng B
int demLanXuatHien(int A[], int n, int B[], int m, int viTriBatDau[]) {
    if(n == 0 || m == 0 || n > m) return 0;
    int soLan = 0;
    int index = 0; // Sử dụng để lưu các vị trí bắt đầu

    // Duyệt qua mảng B
    for (int i = 0; i <= m - n; i++) {
        bool khop = true;

        // Kiểm tra nếu đoạn con B[i...i+n-1] trùng với A
        for (int j = 0; j < n; j++) {
            if (B[i + j] != A[j]) {
                khop = false;
                break;
            }
        }

        if (khop) {
            viTriBatDau[index++] = i; // Lưu vị trí bắt đầu vào mảng
            soLan++;
        }
    }
    return soLan;
}

int main() {
    int kichThuocA, kichThuocB;

    // Nhập số phần tử của mảng A và B
    cout << "Nhập số phần tử của mảng A: ";
    cin >> kichThuocA;
    cout << "Nhập số phần tử của mảng B: ";
    cin >> kichThuocB;

    int A[kichThuocA], B[kichThuocB];
    int viTriBatDau[1000]; // Mảng tĩnh để lưu các vị trí xuất hiện

    // Nhập các phần tử của mảng A
    cout << "Nhập các phần tử của mảng A:\n";
    for (int i = 0; i < kichThuocA; i++) {
        cin >> A[i];
    }

    // Nhập các phần tử của mảng B
    cout << "Nhập các phần tử của mảng B:\n";
    for (int i = 0; i < kichThuocB; i++) {
        cin >> B[i];
    }

    // Đếm số lần xuất hiện và lưu các vị trí bắt đầu
    int soLanXuatHien = demLanXuatHien(A, kichThuocA, B, kichThuocB, viTriBatDau);

    // Xuất kết quả
    cout << "Số lần mảng A xuất hiện trong mảng B: " << soLanXuatHien << endl;
    if (soLanXuatHien > 0) {
        cout << "Các vị trí bắt đầu: ";
        for (int i = 0; i < soLanXuatHien; i++) {
            cout << viTriBatDau[i] << " ";
        }
        cout << endl;
    }

    return 0;
}