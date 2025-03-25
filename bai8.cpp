#include <bits/stdc++.h> 
using namespace std; 
class STK { 
private: 
    string ma, loai, ten, cmnd, ngay; 
    double tien; 
 
    bool ktMa(string m) { 
        if (m.length() > 5) return false; 
        for (char c : m) { 
            if (!isalnum(c)) return false; 
        } 
        return true; 
    } 
    bool ktCMND(string c) { 
        if (c.length() != 9 && c.length() != 12) return false; 
        for (char ch : c) { 
            if (!isdigit(ch)) return false; 
        } 
        return true; 
    } 
    bool ktTen(string t) { 
        if (t.length() > 30) return false; 
        for (char c : t) { 
            if (!isalpha(c) && c != ' ') return false; 
        } 
        return true; 
    } 
    bool ktNgay(int d, int m, int y) { 
        if (y < 1900 || y > 2100 || m < 1 || m > 12 || d < 1 || d > 31) return false; 
        int ngayTrongThang[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
        if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) ngayTrongThang[2] = 29; 
        return d <= ngayTrongThang[m]; 
    } 
    string nhapNgay() { 
        int d, m, y; 
        while (true) { 
            cout << "Nhap ngay (dd mm yyyy): "; 
            cin >> d >> m >> y; 
            if (ktNgay(d, m, y)) break; 
            cout << "Ngay khong hop le! Nhap lai.\n"; 
        } 
        stringstream ss; 
        ss << (d < 10 ? "0" : "") << d << "/" << (m < 10 ? "0" : "") << m << "/" << y; 
        return ss.str(); 
    } 
public: 
    void nhap() { 
        do { 
            cout << "Nhap ma so: "; 
            cin >> ma; 
            if (!ktMa(ma)) cout << "Ma so khong hop le! Nhap lai.\n"; 
        } while (!ktMa(ma)); 
 
        cout << "Nhap loai: "; 
        cin.ignore(); 
        getline(cin, loai); 
 
        do { 
            cout << "Nhap ten: "; 
            getline(cin, ten); 
            if (!ktTen(ten)) cout << "Ten khong hop le! Nhap lai.\n"; 
        } while (!ktTen(ten));
        do { 
            cout << "Nhap CMND: "; 
            cin >> cmnd; 
            if (!ktCMND(cmnd)) cout << "CMND khong hop le! Nhap lai.\n"; 
        } while (!ktCMND(cmnd)); 
 
        ngay = nhapNgay(); 
 
        do { 
            cout << "Nhap tien: "; 
            cin >> tien; 
            if (tien <= 0) cout << "Tien phai lon hon 0! Nhap lai.\n"; 
        } while (tien <= 0); 
    } 
    void xuat() { 
        cout << "\n--- Thong tin STK ---\n"; 
        cout << "Ma: " << ma << endl; 
        cout << "Loai: " << loai << endl; 
        cout << "Ten: " << ten << endl; 
        cout << "CMND: " << cmnd << endl; 
        cout << "Ngay: " << ngay << endl; 
        cout << "Tien: " << tien << endl; 
    } 
 
    string getCMND() { return cmnd; } 
    string getMa() { return ma; } 
    string getNgay() { return ngay; } 
    double getTien() { return tien; } 
}; 
void timKiem(vector<STK>& ds, string key) { 
    bool found = false; 
    for (auto& stk : ds) { 
        if (stk.getCMND() == key || stk.getMa() == key) { 
            stk.xuat(); 
            found = true; 
        } 
    } 
    if (!found) { 
        cout << "\nKhong tim thay STK voi thong tin da nhap.\n";
    } 
} 
void lietKe(vector<STK>& ds, string tuNgay, string denNgay) { 
    vector<STK> temp; 
    for (auto& stk : ds) { 
        if (stk.getNgay() >= tuNgay && stk.getNgay() <= denNgay) { 
            temp.push_back(stk); 
        } 
    } 
    sort(temp.begin(), temp.end(), [](STK a, STK b) { 
        if (a.getTien() != b.getTien()) 
            return a.getTien() > b.getTien(); 
        return a.getNgay() < b.getNgay(); 
    }); 
    if (temp.empty()) { 
        cout << "\nKhong co STK nao trong khoang ngay da nhap.\n"; 
    } else { 
        for (auto& stk : temp) { 
            stk.xuat(); 
        } 
    } 
} 
void sapXepTien(vector<STK>& ds) { 
    sort(ds.begin(), ds.end(), [](STK a, STK b) { 
        return a.getTien() > b.getTien(); 
    }); 
} 
 
void sapXepNgay(vector<STK>& ds) { 
    sort(ds.begin(), ds.end(), [](STK a, STK b) { 
        return a.getNgay() < b.getNgay(); 
    }); 
} 
int main() { 
    int n; 
    cout << "Nhap so luong STK: "; 
    cin >> n; 
    vector<STK> ds(n);
    for (int i = 0; i < n; i++) { 
        cout << "\nNhap STK thu " << i + 1 << "\n"; 
        ds[i].nhap(); 
    } 
 
    sapXepTien(ds); 
    cout << "\nDanh sach sau khi sap xep theo tien:\n"; 
    for (auto& stk : ds) { 
        stk.xuat(); 
    } 
     
    sapXepNgay(ds); 
    cout << "\nDanh sach sau khi sap xep theo ngay:\n"; 
    for (auto& stk : ds) { 
        stk.xuat(); 
    } 
     
    string key; 
    cout << "\nNhap CMND hoac ma so can tim: "; 
    cin >> key; 
    timKiem(ds, key); 
     
    string tu, den; 
    cout << "\nNhap khoang ngay (tu ngay - den ngay): "; 
    cin >> tu >> den; 
    lietKe(ds, tu, den); 
     
    return 0; 
}