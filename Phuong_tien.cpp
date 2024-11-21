#include <bits/stdc++.h>
using namespace std;

class PhuongTien {
private:
    string hangsx, mau;
    int namsx;
    float giaBan;
public:
    PhuongTien() : hangsx(""), mau(""), namsx(0), giaBan(0.0) {}
    string getMau() {
        return this->mau;
    }
    void setMau(string mau) {
        this->mau = mau;
    }
    friend istream& operator >> (istream&, PhuongTien&);
    friend ostream& operator << (ostream&, PhuongTien);
};

istream& operator >> (istream& is, PhuongTien& a) {
    is.ignore();
    cout << "Hang sx: ";
    getline(is, a.hangsx);
    cout << "Mau: ";
    getline(is, a.mau);
    cout << "Nam sx: ";
    is >> a.namsx;
    cout << "Gia ban: ";
    is >> a.giaBan;
    return is;
}

ostream& operator << (ostream& os, PhuongTien a) {
    os << "Hang sx: " << a.hangsx << endl;
    os << "Mau: " << a.mau << endl;
    os << "Nam sx: " << a.namsx << endl;
    os << "Gia ban: " << fixed << setprecision(2) << a.giaBan << endl;
    return os;
}

class Oto : public PhuongTien {
private:
    int soChoNgoi;
    string kieuDongCo;
public:
    Oto() : PhuongTien(), soChoNgoi(0), kieuDongCo("") {}
    friend istream& operator >> (istream&, Oto&);
    friend ostream& operator << (ostream&, Oto);
};

istream& operator >> (istream& is, Oto& a) {
    is >> static_cast<PhuongTien&>(a);
    cout << "So cho ngoi: ";
    is >> a.soChoNgoi;
    is.ignore();
    cout << "Kieu dong co: ";
    getline(is, a.kieuDongCo);
    return is;
}

ostream& operator << (ostream& os, Oto a) {
    os << static_cast<PhuongTien>(a);
    os << "So cho ngoi: " << a.soChoNgoi << endl;
    os << "Kieu dong co: " << a.kieuDongCo << endl;
    return os;
}

class XeMay : public PhuongTien {
private:
    string congSuat;
public:
    XeMay() : PhuongTien(), congSuat("") {}
    friend istream& operator >> (istream&, XeMay&);
    friend ostream& operator << (ostream&, XeMay);
};

istream& operator >> (istream& is, XeMay& a) {
	is.ignore();
    is >> static_cast<PhuongTien&>(a);
    cout << "Cong suat: ";
    getline(is, a.congSuat);
    return is;
}

ostream& operator << (ostream& os, XeMay a) {
    os << static_cast<PhuongTien>(a);
    os << "Cong suat: " << a.congSuat << endl;
    return os;
}

class XeTai : public PhuongTien {
private:
    string trongTai;
public:
    XeTai() : PhuongTien(), trongTai("") {}
    friend istream& operator >> (istream&, XeTai&);
    friend ostream& operator << (ostream&, XeTai);
};

istream& operator >> (istream& is, XeTai& a) {
    is >> static_cast<PhuongTien&>(a);
    cout << "Trong tai: ";
    getline(is, a.trongTai);
    return is;
}

ostream& operator << (ostream& os, XeTai a) {
    os << static_cast<PhuongTien>(a);
    os << "Trong tai: " << a.trongTai << endl;
    return os;
}

class QLPTGT {
private:
    vector<Oto> dsOto;
    vector<XeMay> dsXeMay;
    vector<XeTai> dsXeTai;
public:
    void dangKyPhuongTien();
    void findMau();
};

void QLPTGT::dangKyPhuongTien() {
    int loai;
    cout << "Chon loai phuong tien:\n";
    cout << "1. Oto\n";
    cout << "2. Xe may\n";
    cout << "3. Xe tai\n";
    cout << "Nhap lua chon: ";
    cin >> loai;
    if (loai == 1) {
        Oto oto;
        cin >> oto;
        dsOto.push_back(oto);
    } else if (loai == 2) {
        XeMay xemay;
        cin >> xemay;
        dsXeMay.push_back(xemay);
    } else if (loai == 3) {
        XeTai xetai;
        cin >> xetai;
        dsXeTai.push_back(xetai);
    } else {
        cout << "Lua chon khong hop le!" << endl;
    }
}

void QLPTGT::findMau() {
    string find;
    cout << "Nhap mau phuong tien can tim: ";
    cin.ignore();
    getline(cin, find);
    bool timThay = false;

    cout << "\nDanh sach OTo co mau " << find << ":\n";
   	for(int i=0;i< dsOto.size();i++){
   		if(dsOto[i].getMau() == find){
   				cout << dsOto[i];
   				timThay = true;
		   }
	   }

    cout << "\nDanh sach XeMay co mau " << find << ":\n";
    for(int i=0;i< dsXeMay.size();i++){
   		if(dsXeMay[i].getMau() == find){
   				cout << dsXeMay[i];
   				timThay = true;
		   }
	   }

    cout << "\nDanh sach XeTai co mau " << find << ":\n";
    for(int i=0;i< dsXeTai.size();i++){
   		if(dsXeTai[i].getMau() == find){
   				cout << dsXeTai[i];
   				timThay = true;
		   }
	   }

    if (!timThay) {
        cout << "Khong tim thay phuong tien nao co mau " << find << "." << endl;
    }
}

int main() {
    QLPTGT qlptgt;
    while (true) {
        cout << "\n----- Quan Ly Phuong Tien Giao Thong -----" << endl;
        cout << "1. Dang ky phuong tien" << endl;
        cout << "2. Tim phuong tien theo mau" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon: ";
        int luaChon;
        cin >> luaChon;
        if (luaChon == 1) {
            qlptgt.dangKyPhuongTien();
        } else if (luaChon == 2) {
            qlptgt.findMau();
        } else if (luaChon == 0) {
            cout << "Ket thuc chuong trinh." << endl;
            break;
        } else {
            cout << "Lua chon khong hop le!" << endl;
        }
    }
    return 0;
}

