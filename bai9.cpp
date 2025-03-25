#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
using namespace std;

//1. Struct chuyến bay
struct ChuyenBay {
    string maChuyenBay;
    string ngayBay;
    string gioBay;
    string noiDi;
    string noiDen;
};

//2. Kiểm tra mã chuyến bay hợp lệ
bool maChuyenBayHopLe(const string &ma) {
    if (ma.length() > 5) return false;
    for (char ch : ma) {
        if (!isalnum(ch)) return false;
    }
    return true;
}

//3. Kiểm tra ngày bay hợp lệ
bool ngayBayHopLe(const string &ngay) {
    if (ngay.length() != 10 || ngay[2] != '/' || ngay[5] != '/') return false;
    int ngayInt = stoi(ngay.substr(0, 2));
    int thangInt = stoi(ngay.substr(3, 2));
    int namInt = stoi(ngay.substr(6, 4));
    int ngayTrongThang[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((namInt % 4 == 0 && namInt % 100 != 0) || namInt % 400 == 0) {
        ngayTrongThang[2] = 29;
    }
    return (thangInt >= 1 && thangInt <= 12 && ngayInt >= 1 && ngayInt <= ngayTrongThang[thangInt]);
}

//4. Kiểm tra giờ hợp lệ
bool kiemTraGio(int gio) {
    return (gio >= 0 && gio < 24);
}

//5. Kiểm tra phút hợp lệ
bool kiemTraPhut(int phut) {
    return (phut >= 0 && phut < 60);
}

//6. Kiểm tra giờ bay hợp lệ
bool gioBayHopLe(const string &gio) {
    if (gio.length() != 5 || gio[2] != ':') return false;

    int gioInt = stoi(gio.substr(0, 2));
    int phutInt = stoi(gio.substr(3, 2));

    return kiemTraGio(gioInt) && kiemTraPhut(phutInt);
}

//7. Kiểm tra nơi đi/nơi đến hợp lệ
bool diaDanhHopLe(const string &diadiem) {
    if (diadiem.length() > 20) return false;
    for (char ch : diadiem) {
        if (!isalpha(ch) && ch != ' ') return false;
    }
    return true;
}

//8. Kiểm tra mã chuyến bay
bool kiemTraMaChuyenBay(const ChuyenBay danhSach[], int soLuong, const string &ma) {
    bool found = false;
    for (int i = 0; i < soLuong; i++) {
        if (danhSach[i].maChuyenBay == ma) {
            cout << "Mã chuyến bay: " << danhSach[i].maChuyenBay << endl;
            cout << "Ngày bay: " << danhSach[i].ngayBay << endl;
            cout << "Giờ bay: " << danhSach[i].gioBay << endl;
            cout << "Nơi đi: " << danhSach[i].noiDi << endl;
            cout << "Nơi đến: " << danhSach[i].noiDen << endl;
            found = true;
            break; 
        }
    }
    if (!found) {
        cout << "Không tồn tại chuyến bay có mã: " << ma << "\n";
    }
    return found;
}

//9. Tìm kiếm chuyến bay theo mã, nơi đi hoặc nơi đến
void timKiemChuyenBay(const ChuyenBay danhSach[], int soLuong, const string &tuKhoa) 
{
    cout << "Kết quả tìm kiếm chuyến bay chứa \"" << tuKhoa << "\":\n";
    bool found = false;
    for (int i = 0; i < soLuong; i++) 
    {
        if (danhSach[i].maChuyenBay == tuKhoa || danhSach[i].noiDi == tuKhoa || danhSach[i].noiDen == tuKhoa || danhSach[i].gioBay == tuKhoa || danhSach[i].ngayBay == tuKhoa) 
        {
            cout << "Mã chuyến bay: " << danhSach[i].maChuyenBay << endl;
            cout << "Ngày bay: " << danhSach[i].ngayBay << endl;
            cout << "Giờ bay: " << danhSach[i].gioBay << endl;
            cout << "Nơi đi: " << danhSach[i].noiDi << endl;
            cout << "Nơi đến: " << danhSach[i].noiDen << endl;
            found = true;
        }
    }
    if(!found)
    {
        cout << "Không tồn tại chuyến bay đang tìm kiếm. ";
    }

}

//10. Sắp xếp danh sách chuyến bay theo ngày và giờ
void sapXepChuyenBay(ChuyenBay danhSach[], int soLuong) 
{
    sort(danhSach, danhSach + soLuong, [](ChuyenBay a, ChuyenBay b) 
    {
        return a.ngayBay < b.ngayBay || (a.ngayBay == b.ngayBay && a.gioBay < b.gioBay);
    });
}

//11. Đếm số lượng chuyến bay theo nơi đi và nơi đến
int demChuyenBay(const ChuyenBay danhSach[], int soLuong, const string &noiDi, const string &noiDen) {
    int count = 0;
    for (int i = 0; i < soLuong; i++) {
        if (danhSach[i].noiDi == noiDi && danhSach[i].noiDen == noiDen) {
            count++;
        }
    }
    return count;
}

//12. Liệt kê chuyến bay theo nơi đi và ngày
void lietKeChuyenBay(const ChuyenBay danhSach[], int soLuong, const string &noiDi, const string &ngayBay) {
    cout << "Danh sách chuyến bay từ " << noiDi << " vào ngày " << ngayBay << ":\n";
    bool found = false;
    for (int i = 0; i < soLuong; i++) 
    {
        if (danhSach[i].noiDi == noiDi && danhSach[i].ngayBay == ngayBay) 
        {
            cout << "Mã chuyến bay: " << danhSach[i].maChuyenBay << ", Ngày bay: " << danhSach[i].ngayBay << ", Giờ bay: " << danhSach[i].gioBay << ", Nơi đi: " << danhSach[i].noiDi << ", Nơi đến: " << danhSach[i].noiDen << "\n";
            found = true;
        }
    }
    if(!found)
    {
        cout << "Không có chuyến bay.";
    }
}

//13. Xuất danh sách chuyến bay
void xuatDanhSachChuyenBay(const ChuyenBay danhSach[], int soLuong) {
    cout << "\nDanh sách chuyến bay:\n";
    for (int i = 0; i < soLuong; i++) 
    {
        cout << "Mã chuyến bay: " << danhSach[i].maChuyenBay <<  ", Ngày bay: " << danhSach[i].ngayBay << ", Giờ bay: " << danhSach[i].gioBay << ", Nơi đi: " << danhSach[i].noiDi << ", Nơi đến: " << danhSach[i].noiDen << "\n";
    }
}

//14. Kiểm tra mã khi nhập trùng
bool maChuyenBayTonTai(const ChuyenBay danhSach[], int soLuong, const string &ma) {
    for (int i = 0; i < soLuong; i++) {
        if (danhSach[i].maChuyenBay == ma) {
            return true; 
        }
    }
    return false; 
}

//15. Hàm chính
int main() {
    int soLuong;
    cout << "Nhập số lượng chuyến bay: ";
    cin >> soLuong;
    if(soLuong == 0)
    {
        cout << "Không có chuyến bay.";
        return 0;
    }
    ChuyenBay danhSach[100];
    cin.ignore();
    for (int i = 0; i < soLuong; i++) {
        cout << "\nNhập thông tin chuyến bay thứ " << i + 1 << ":\n";
    
        // Nhập mã chuyến bay và kiểm tra
        do {
            cout << "Nhập Mã chuyến bay: ";
            getline(cin, danhSach[i].maChuyenBay);
            if (!maChuyenBayHopLe(danhSach[i].maChuyenBay)) {
                cout << "Mã chuyến bay không hợp lệ. Vui lòng nhập lại!\n";
            } else if (maChuyenBayTonTai(danhSach, i, danhSach[i].maChuyenBay)) {
                cout << "Mã chuyến bay đã tồn tại. Vui lòng nhập lại!\n";
            }
        } while (!maChuyenBayHopLe(danhSach[i].maChuyenBay) || 
                 maChuyenBayTonTai(danhSach, i, danhSach[i].maChuyenBay));
    
        // Nhập ngày bay và kiểm tra
        do {
            cout << "Nhập ngày bay (dd/mm/yyyy): ";
            getline(cin, danhSach[i].ngayBay);
            if (!ngayBayHopLe(danhSach[i].ngayBay)) {
                cout << "Ngày bay không hợp lệ. Vui lòng nhập lại!\n";
            }
        } while (!ngayBayHopLe(danhSach[i].ngayBay));
    
        // Nhập giờ bay và kiểm tra
        do {
            cout << "Nhập giờ bay (hh:mm): ";
            getline(cin, danhSach[i].gioBay);
            if (!gioBayHopLe(danhSach[i].gioBay)) {
                cout << "Giờ bay không hợp lệ. Vui lòng nhập lại!\n";
            }
        } while (!gioBayHopLe(danhSach[i].gioBay));
    
        // Nhập nơi đi và kiểm tra
        do {
            cout << "Nhập nơi đi: ";
            getline(cin, danhSach[i].noiDi);
            if (!diaDanhHopLe(danhSach[i].noiDi)) {
                cout << "Nơi đi không hợp lệ. Vui lòng nhập lại!\n";
            }
        } while (!diaDanhHopLe(danhSach[i].noiDi));
    
        // Nhập nơi đến và kiểm tra
        do {
            cout << "Nhập nơi đến: ";
            getline(cin, danhSach[i].noiDen);
            if (!diaDanhHopLe(danhSach[i].noiDen)) {
                cout << "Nơi đến không hợp lệ. Vui lòng nhập lại!\n";
            }
        } while (!diaDanhHopLe(danhSach[i].noiDen));
    }
    

    xuatDanhSachChuyenBay(danhSach, soLuong);

    string maChuyenBay;
    cout << "\nNhập Mã chuyến bay cần kiểm tra: ";
    getline(cin, maChuyenBay);
    kiemTraMaChuyenBay(danhSach, soLuong, maChuyenBay);

    string tuKhoa;
    cout << "\nNhập từ khóa tìm kiếm chuyến bay: ";
    getline(cin, tuKhoa);
    timKiemChuyenBay(danhSach, soLuong, tuKhoa);

    sapXepChuyenBay(danhSach, soLuong);

    string noiDi, noiDen;
    cout << "\nNhập nơi đi và nơi đến để đếm số chuyến bay: ";
    getline(cin, noiDi);
    getline(cin, noiDen);
    cout << "Số chuyến bay từ " << noiDi << " đến " << noiDen << ": " << demChuyenBay(danhSach, soLuong, noiDi, noiDen) << "\n";

    string ngayBay;
    cout << "\nNhập nơi đi và ngày để liệt kê chuyến bay: ";
    getline(cin, noiDi);
    getline(cin, ngayBay);
    lietKeChuyenBay(danhSach, soLuong, noiDi, ngayBay);

    return 0;
}