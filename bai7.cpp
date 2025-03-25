#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 1. Struct học sinh
struct hocSinh {
    string hoten;
    int toan;
    int van;
    int anh;
};

// 2. Kiểm tra dữ liệu nhập hợp lệ
bool tenHopLe(const string &hoten) {
    if (hoten.length() < 1 || hoten.length() > 100)
        return false;
    for (char ch : hoten) {
        if (!isalpha(ch) && ch != ' ') // Chỉ chấp nhận chữ cái và khoảng trắng
            return false;
    }
    return true;
}

bool diemHopLe(int toan, int van, int anh) {
    return (toan >= 0 && toan <= 10) && (van >= 0 && van <= 10) && (anh >= 0 && anh <= 10);
}

// 3. Nhập thông tin học sinh
void nhap(hocSinh &hs) {
    while (true) {
        cin.ignore(); // Loại bỏ ký tự xuống dòng còn sót
        cout << "Họ và tên: ";
        getline(cin, hs.hoten);

        if (!tenHopLe(hs.hoten)) {
            cout << "Tên không hợp lệ. Vui lòng nhập lại.\n";
            continue;
        }

        cout << "Nhập điểm Toán: ";
        cin >> hs.toan;
        cout << "Nhập điểm Văn: ";
        cin >> hs.van;
        cout << "Nhập điểm Anh: ";
        cin >> hs.anh;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n'); // Xóa bộ đệm nhập lỗi
            cout << "Lỗi! Vui lòng nhập số nguyên hợp lệ.\n";
        } else if (!diemHopLe(hs.toan, hs.van, hs.anh)) {
            cout << "Điểm nhập không hợp lệ (từ 0 đến 10). Vui lòng nhập lại.\n";
        } else {
            break;
        }
    }
}

// 4. Tính điểm trung bình
double diemTrungBinh(int toan, int van, int anh) {
    return (2.0 * toan + van + anh) / 4.0;
}

// 5. Phân loại học sinh
void phanLoaiHocSinh(int toan, int van, int anh) {
    double dtb = diemTrungBinh(toan, van, anh);
    cout << "Điểm trung bình: " << dtb << endl;
    if (dtb >= 9.0)
        cout << "Xếp loại: Xuất sắc\n";
    else if (dtb >= 8.0)
        cout << "Xếp loại: Giỏi\n";
    else if (dtb >= 6.5)
        cout << "Xếp loại: Khá\n";
    else if (dtb >= 5.0)
        cout << "Xếp loại: Trung bình\n";
    else
        cout << "Xếp loại: Yếu\n";
}

// 6. Tìm học sinh có điểm trung bình cao nhất
void timHocSinhDiemCaoNhat(hocSinh hocSinhArray[], int soLuongHocSinh) {
    if (soLuongHocSinh == 0) {
        cout << "Không có học sinh nào trong danh sách.\n";
        return;
    }

    int chiSoHocSinhGioiNhat = 0;
    double diemCaoNhat = diemTrungBinh(hocSinhArray[0].toan, hocSinhArray[0].van, hocSinhArray[0].anh);

    for (int i = 1; i < soLuongHocSinh; i++) {
        double diemTB = diemTrungBinh(hocSinhArray[i].toan, hocSinhArray[i].van, hocSinhArray[i].anh);
        if (diemTB > diemCaoNhat) {
            diemCaoNhat = diemTB;
            chiSoHocSinhGioiNhat = i; // Lưu chỉ số học sinh có điểm cao nhất
        }
    }
    cout << "Học sinh có điểm trung bình cao nhất: " << hocSinhArray[chiSoHocSinhGioiNhat].hoten << endl;
    cout << "Điểm trung bình: " << diemCaoNhat << endl;
}

// 7. Tìm kiếm học sinh theo tên
void timKiemHocSinh(hocSinh hocSinhArray[], int soLuongHocSinh, string keyword) {
    transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);
    bool found = false;
    for (int i = 0; i < soLuongHocSinh; i++) {
        string hoten = hocSinhArray[i].hoten;
        transform(hoten.begin(), hoten.end(), hoten.begin(), ::tolower);
        if (hoten.find(keyword) != string::npos) {
            found = true;
            cout << "Họ tên: " << hocSinhArray[i].hoten << endl;
            cout << "Điểm Toán: " << hocSinhArray[i].toan << endl;
            cout << "Điểm Văn: " << hocSinhArray[i].van << endl;
            cout << "Điểm Anh: " << hocSinhArray[i].anh << endl;
            cout << "Điểm trung bình: " << diemTrungBinh(hocSinhArray[i].toan, hocSinhArray[i].van, hocSinhArray[i].anh) << endl;
        }
    }
    if (!found) {
        cout << "Không tìm thấy học sinh nào phù hợp với từ khóa \"" << keyword << "\".\n";
    }
}

// 8. Tìm học sinh có điểm Toán thấp nhất
void timHocSinhDiemToanThapNhat(hocSinh hocSinhArray[], int soLuongHocSinh) {
    if (soLuongHocSinh == 0) {
        cout << "Không có học sinh nào trong danh sách.\n";
        return;
    }
    int chiSoHocSinhToanThapNhat = 0;
    int diemToanThapNhat = hocSinhArray[0].toan;
    for (int i = 1; i < soLuongHocSinh; i++) {
        if (hocSinhArray[i].toan < diemToanThapNhat) {
            diemToanThapNhat = hocSinhArray[i].toan;
            chiSoHocSinhToanThapNhat = i;
        }
    }
    cout << "Học sinh có điểm Toán thấp nhất: " << hocSinhArray[chiSoHocSinhToanThapNhat].hoten << endl;
    cout << "Điểm Toán: " << hocSinhArray[chiSoHocSinhToanThapNhat].toan << endl;
    cout << "Điểm Văn: " << hocSinhArray[chiSoHocSinhToanThapNhat].van << endl;
    cout << "Điểm Anh: " << hocSinhArray[chiSoHocSinhToanThapNhat].anh << endl;
    cout << "Điểm trung bình: " << diemTrungBinh(hocSinhArray[chiSoHocSinhToanThapNhat].toan, hocSinhArray[chiSoHocSinhToanThapNhat].van, hocSinhArray[chiSoHocSinhToanThapNhat].anh) << endl;
}

// 9. Xuất danh sách học sinh
void xuatDanhSachHocSinh(hocSinh hocSinhArray[], int soLuongHocSinh) {
    cout << "--------Danh sách học sinh---------" << endl;
    for (int i = 0; i < soLuongHocSinh; i++) {
        cout << "Học sinh thứ " << i + 1 << ":" << endl;
        cout << "Họ tên: " << hocSinhArray[i].hoten << endl;
        cout << "Điểm Toán: " << hocSinhArray[i].toan << endl;
        cout << "Điểm Văn: " << hocSinhArray[i].van << endl;
        cout << "Điểm Anh: " << hocSinhArray[i].anh << endl;
        cout << "Điểm trung bình: " << diemTrungBinh(hocSinhArray[i].toan, hocSinhArray[i].van, hocSinhArray[i].anh) << endl;
        phanLoaiHocSinh(hocSinhArray[i].toan, hocSinhArray[i].van, hocSinhArray[i].anh);
        cout << "-----------------------------------" << endl;
    }
}

// 10. Hàm chính
int main() {
    hocSinh hocSinhArray[100];
    int soLuongHocSinh;

    // Nhập thông tin học sinh
    cout << "Nhập số lượng học sinh: ";
    cin >> soLuongHocSinh;

    for (int i = 0; i < soLuongHocSinh; i++) {
        cout << "Nhập thông tin học sinh thứ " << i + 1 << ":\n";
        nhap(hocSinhArray[i]);
    }

    // Xuất danh sách học sinh
    cout << endl;
    xuatDanhSachHocSinh(hocSinhArray, soLuongHocSinh);
    //Tìm học sinh Điểm cao nhất
    timHocSinhDiemCaoNhat(hocSinhArray, soLuongHocSinh);
    //Tìm học sinh theo tên
    string keyword;
    cin.ignore();
    cout << "Nhập tên học sinh cần tìm: ";
    getline(cin, keyword);
    timKiemHocSinh(hocSinhArray, soLuongHocSinh, keyword);
    //Tìm học sinh có điểm Toán thấp nhất
    timHocSinhDiemToanThapNhat(hocSinhArray, soLuongHocSinh);
}
