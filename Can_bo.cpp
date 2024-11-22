#include <bits/stdc++.h>
using namespace std;

class CanBo{
	private:
		string hoTen,gioiTinh,diaChi;
		int namSinh;
	public:
		CanBo(){
			hoTen = gioiTinh = diaChi = "";
			namSinh = 0;
		}
		friend istream& operator >> (istream&,CanBo&);
		friend ostream& operator << (ostream&,CanBo);
		string getHoTen(){
			return hoTen;
		}
		void setHoTen(string hoTen){
			this->hoTen = hoTen;
		}
};

istream& operator >> (istream& is,CanBo& a){
	is.ignore();
	cout << "Nhap ho ten : "; getline(is,a.hoTen);
	cout << "Nhap nam sinh : "; is >> a.namSinh;
	cout << "Nhap gioi tinh : "; is >> a.gioiTinh;
	is.ignore();
	cout << "Nhap dia chi : "; getline(is,a.diaChi);
	return is;
}

ostream& operator << (ostream& os,CanBo a){
	os << "Ho ten : " << a.hoTen << endl;
	os << "Nam sinh : " << a.namSinh << endl;
	os << "Gioi tinh : " << a.gioiTinh << endl;
	os << "Dia chi : " << a.diaChi << endl;
	return os;
}


class CongNhan : public CanBo{
	private:
		string bac;
	public:
		CongNhan() : CanBo(){
			bac = "";
		}
		friend istream& operator >> (istream&,CongNhan&);
		friend ostream& operator << (ostream&,CongNhan);
};


istream& operator >> (istream& is,CongNhan& a){
	is >> static_cast<CanBo&> (a);
	cout << "Nhap bac : "; is >> a.bac;
	return is;
}

ostream& operator << (ostream& os,CongNhan a){
	os << static_cast<CanBo> (a);
	os << "Bac : " << a.bac << endl;
	return os;
}


class KySu : public CanBo{
	private:
		string nganhDaoTao,loaiBang;
	public:
		KySu() : CanBo(){
			nganhDaoTao = loaiBang = "";
		}
		friend istream& operator >> (istream&,KySu&);
		friend ostream& operator << (ostream&,KySu);
};

istream& operator >> (istream& is,KySu& a){
	is >> static_cast<CanBo&> (a);
	cout << "Nhap nganh dao tao : "; getline(is,a.nganhDaoTao);
	cout << "Nhap loai bang : "; getline(is,a.loaiBang);
	return is;
}

ostream& operator << (ostream& os,KySu a){
	os << static_cast<CanBo> (a);
	os << "Nganh dao tao : " << a.nganhDaoTao << endl;
	os << "Loai bang : " << a.loaiBang << endl;
	return os;
}


class NhanVien : public CanBo{
	private:
		string congViec;
	public:
		NhanVien() : CanBo(){
			congViec = "";
		}
		friend istream& operator >> (istream&,NhanVien&);
		friend ostream& operator << (ostream&,NhanVien);
};

istream& operator >> (istream& is,NhanVien& a){
	is >> static_cast<CanBo&> (a);
	cout << "Nhap cong viec : "; getline(is,a.congViec);
	return is;
}

ostream& operator << (ostream& os,NhanVien a){
	os << static_cast<CanBo> (a);
	os << "Cong viec : " << a.congViec << endl;
	return os;
}


class QLCB{
	private:
		vector<CongNhan> dsCN;
		vector<KySu> dsKS;
		vector<NhanVien> dsNV;
	public:
		void NhapCanBo();
		void findHoTen();
		void InCanBo();
};


void QLCB::NhapCanBo(){
	cout << "Chon don vi can bo !!!" << endl;
	cout << "1. Cong Nhan\n";
	cout << "2. Ky Su\n ";
	cout << "3. Nhan Vien\n";
	int loai; cout << ">>>>>>>>>> Moi nhap lua chon : "; cin >> loai;
	if(loai == 1){
		CongNhan a;
		cin >> a;
		dsCN.push_back(a);
	} 
	else if(loai == 2){
		KySu a;
		cin >> a;
		dsKS.push_back(a);
	}
	else if(loai == 3){
		NhanVien a;
		cin >> a;
		dsNV.push_back(a);
	}
	else{
		cout << "Lua chon khong hop le !!!" << endl;
	}
}

void QLCB::findHoTen(){
	cin.ignore();
	string find;
	cout << "Nhap ho ten can tim kiem : "; getline(cin,find);
	bool timThay = false;
	cout << "Danh sach Cong Nhan co ten " << find << ":\n";
	for(int i=0;i<dsCN.size();i++){
		if(dsCN[i].getHoTen() == find){
			cout << dsCN[i];
			timThay = true;
		}
	}
	cout << "Danh sach Ky Su co ten " << find << ":\n";
	for(int i=0;i<dsKS.size();i++){
			if(dsKS[i].getHoTen() == find){
				cout << dsKS[i];
				timThay = true;
		}
	}
	cout << "Danh sach Nhan Vien co ten " << find << ":\n";
	for(int i=0;i<dsNV.size();i++){
		if(dsNV[i].getHoTen() == find){
			cout << dsNV[i];
			timThay = true;
		}
	}	
	if(!timThay){
		cout << "Khong tim thay can bo nao ten " << find << "." << endl;
	}
}

void QLCB::InCanBo(){
	cout << "Danh sach Cong Nhan  " << endl;
	for(int i=0;i<dsCN.size();i++){
			cout << dsCN[i];
	}
	cout << "Danh sach Ky Su " << "\n";
	for(int i=0;i<dsKS.size();i++){
				cout << dsKS[i];
	}
	cout << "Danh sach Nhan Vien  " << "\n";
	for(int i=0;i<dsNV.size();i++){
			cout << dsNV[i];
	}	
}


int main(){
	QLCB qlcb;
	while (1) {
        cout << "\n----- Quan Ly Can Bo  -----" << endl;
        cout << "1. Nhap thong tin can bo" << endl;
    	cout << "2. In thong tin can bo" << endl;
        cout << "3. Tim can bo theo ho ten" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon: ";
        int luaChon;
        cin >> luaChon;
        if (luaChon == 1) {
            qlcb.NhapCanBo();
        }else if(luaChon == 2){
        	qlcb.InCanBo();
		} 
		else if (luaChon == 3) {
            qlcb.findHoTen();
        } else if (luaChon == 0) {
            cout << "Ket thuc chuong trinh." << endl;
            break;
        } else {
            cout << "Lua chon khong hop le!" << endl;
        }
    }
}













