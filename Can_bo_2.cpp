#include <bits/stdc++.h>
using namespace std;

class CanBo {
protected:
    string hoTen, gioiTinh, diaChi;
    int namSinh;

public:
    CanBo() : hoTen(""), gioiTinh(""), diaChi(""), namSinh(0) {}

    virtual void nhap() {
        cin.ignore();
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
        cin.ignore();
        cout << "Nhap gioi tinh: ";
        getline(cin, gioiTinh);
        cout << "Nhap dia chi: ";
        getline(cin, diaChi);
    }

    virtual void hienThi() const {
        cout << "Ho ten: " << hoTen << endl;
        cout << "Nam sinh: " << namSinh << endl;
        cout << "Gioi tinh: " << gioiTinh << endl;
        cout << "Dia chi: " << diaChi << endl;
    }

    string getHoTen() const {
        return hoTen;
    }

    virtual ~CanBo() {}
};

class CongNhan : public CanBo {
private:
    string bac;

public:
    CongNhan() : CanBo(), bac("") {}

    void nhap() override {
        CanBo::nhap();
        cout << "Nhap bac: ";
        cin >> bac;
        cin.ignore();
    }

    void hienThi() const override {
        CanBo::hienThi();
        cout << "Bac: " << bac << endl;
    }
};

class KySu : public CanBo {
private:
    string nganhDaoTao, loaiBang;

public:
    KySu() : CanBo(), nganhDaoTao(""), loaiBang("") {}

    void nhap() override {
        CanBo::nhap();
        cout << "Nhap nganh dao tao: ";
        getline(cin, nganhDaoTao);
        cout << "Nhap loai bang: ";
        getline(cin, loaiBang);
    }

    void hienThi() const override {
        CanBo::hienThi();
        cout << "Nganh dao tao: " << nganhDaoTao << endl;
        cout << "Loai bang: " << loaiBang << endl;
    }
};

class NhanVien : public CanBo {
private:
    string congViec;

public:
    NhanVien() : CanBo(), congViec("") {}

    void nhap() override {
        CanBo::nhap();
        cout << "Nhap cong viec: ";
        getline(cin, congViec);
    }

    void hienThi() const override {
        CanBo::hienThi();
        cout << "Cong viec: " << congViec << endl;
    }
};

class QLCB {
private:
    vector<CanBo*> dsCanBo;

public:
    void NhapCanBo() {
        cout << "Chon don vi can bo:" << endl;
        cout << "1. Cong Nhan" << endl;
        cout << "2. Ky Su" << endl;
        cout << "3. Nhan Vien" << endl;
        int loai;
        cout << "Lua chon: ";
        cin >> loai;

        CanBo* canBo = nullptr;
        if (loai == 1) {
            canBo = new CongNhan();
        } else if (loai == 2) {
            canBo = new KySu();
        } else if (loai == 3) {
            canBo = new NhanVien();
        } else {
            cout << "Lua chon khong hop le!" << endl;
            return;
        }

        canBo->nhap();
        dsCanBo.push_back(canBo);
    }

    void findHoTen() {
        cin.ignore();
        string find;
        cout << "Nhap ho ten can tim kiem: ";
        getline(cin, find);

        bool found = false;
        for (const auto& canBo : dsCanBo) {
            if (canBo->getHoTen() == find) {
                canBo->hienThi();
                found = true;
            }
        }

        if (!found) {
            cout << "Khong tim thay can bo co ten: " << find << endl;
        }
    }

    void InCanBo() {
        cout << "\nDanh sach can bo:" << endl;
        for (const auto& canBo : dsCanBo) {
            canBo->hienThi();
            cout << "---------------------------" << endl;
        }
    }

    ~QLCB() {
        for (auto& canBo : dsCanBo) {
            delete canBo;
        }
    }
};

int main() {
    QLCB qlcb;
    while (true) {
        cout << "\n----- Quan Ly Can Bo -----" << endl;
        cout << "1. Nhap thong tin can bo" << endl;
        cout << "2. In thong tin can bo" << endl;
        cout << "3. Tim can bo theo ho ten" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon: ";
        int luaChon;
        cin >> luaChon;

        if (luaChon == 1) {
            qlcb.NhapCanBo();
        } else if (luaChon == 2) {
            qlcb.InCanBo();
        } else if (luaChon == 3) {
            qlcb.findHoTen();
        } else if (luaChon == 0) {
            cout << "Ket thuc chuong trinh." << endl;
            break;
        } else {
            cout << "Lua chon khong hop le!" << endl;
        }
    }
    return 0;
}

