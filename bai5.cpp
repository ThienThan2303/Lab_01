#include <iostream>
using namespace std;
//1. Kiểm tra năm nhuận
bool laNamNhuan(int nam) {
    return (nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0);
}

//2. Xác định số ngày trong tháng
int soNgayTrongThang(int thang, int nam) {
    int ngayThang[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (thang == 2 && laNamNhuan(nam)) {
        return 29;
    }
    return ngayThang[thang - 1];
}

//3. Kiểm tra tính hợp lệ của ngày nhập
bool ngayHopLe(int ngay, int thang, int nam) {
    if (nam < 1 || thang < 1 || thang > 12 || ngay < 1 || ngay > soNgayTrongThang(thang, nam)) {
        return false;
    }
    return true;
}

//4. Tìm ngày kế tiếp
void ngayKeTiep(int &ngay, int &thang, int &nam) {
    if (ngay < soNgayTrongThang(thang, nam)) {
        ngay++;
    } else { 
        ngay = 1;
        if (thang < 12) {
            thang++;
        } else {
            thang = 1;
            nam++;
        }
    }
}

//5. Tìm ngày trước đó
void ngayTruocDo(int &ngay, int &thang, int &nam) {
    if (ngay > 1) {
        ngay--;
    } else {
        if (thang > 1) {
            thang--;
        } else {
            thang = 12;
            nam--;
        }
        ngay = soNgayTrongThang(thang, nam);
    }
}

//6. Tính số thứ tự của ngày trong năm
int ngayThuBaoNhieu(int ngay, int thang, int nam) {
    int thuTu = 0;
    for (int i = 1; i < thang; i++) {
        thuTu += soNgayTrongThang(i, nam);
    }
    return thuTu + ngay;
}

//7.Hàm nhập ngày, tháng, năm đảm bảo dữ liệu hợp lệ
void nhapNgay(int &ngay, int &thang, int &nam) {
    while (true) {
        cout << "Nhập ngày: ";
        cin >> ngay;
        cout << "Nhập tháng: ";
        cin >> thang;
        cout << "Nhập năm: ";
        cin >> nam;

        if (cin.fail()) { 
            cin.clear(); 
            cin.ignore(); 
            cout << "Loi: Nhap so nguyen hop le!\n";
        } 
        else if (!ngayHopLe(ngay, thang, nam)) { 
            cout << "Loi: Ngay thang nam khong hop le. Vui long nhap lai!\n";
        } 
        else {
            break; 
        }
    }
}


//8. Chương trình chính
int main() {
    int ngay, thang, nam;
    nhapNgay(ngay, thang, nam);
   
    //9. Ngày kế tiếp
    int ngayK, thangK, namK;
    ngayK = ngay;
    thangK = thang;
    namK = nam;
    ngayKeTiep(ngayK, thangK, namK);

    //10. Ngày trước đó
    int ngayT, thangT, namT;
    ngayT = ngay;
    thangT = thang;
    namT = nam;
    ngayTruocDo(ngayT, thangT, namT);

    //11. Tính số thứ tự ngày trong năm
    int thuTu = ngayThuBaoNhieu(ngay, thang, nam);

    cout << "Ngay ke tiep: " << ngayK << "/" << thangK << "/" << namK << endl;
    cout << "Ngay truoc do: " << ngayT << "/" << thangT << "/" << namT << endl;
    cout << "Ngay " << ngay << "/" << thang << "/" << nam << " la ngay thu " << thuTu << " trong nam." << endl;

    return 0;
}
