#include "NoNamRuoi.h"

NoNamRuoi::NoNamRuoi()
{
	this->laiSuat.resize(18);
	for (int i = 0; i < this->laiSuat.size(); i++) {
		this->laiSuat[i] = 0;
	}
}

void NoNamRuoi::ganLaiSuat()
{
	for (int i = 0; i < this->laiSuat.size(); i++) {
		cout << "Nhap lai suat thang thu " << i + 1 << "(%): ";
		cin >> this->laiSuat[i];
		this->laiSuat[i] /= 100;
	}
}

void NoNamRuoi::nhapKhoanNo()
{
	cout << "Nhap khoan no 1.5 nam" << endl;
	cout << "Nhap ngay muon: ";
	getline(cin, this->ngayMuonNo);
	if (this->ngayMuonNo[2] != '/') {
		this->ngayMuonNo = '0' + this->ngayMuonNo;
	}
	if (this->ngayMuonNo[5] != '/') {
		this->ngayMuonNo.insert(3, "0");
	}
	cout << "Nhap so tien muon: ";
	cin >> this->tienNoGoc;
	this->ganLaiSuat();
}

//double NoNamRuoi::tinhTongNo()
//{
//	double tongNo = this->tienNoGoc;
//	for (int i = 0; i < this->laiSuat.size(); i++) {
//		tongNo += tongNo * this->laiSuat[i];
//	}
//	return tongNo;
//}

double NoNamRuoi::tinhTongNoSauXThang(int x)
{
	while (x < 0 || x>18) {
		cout << "Thoi gian truyen vao khong hop le, nhap lai: ";
		cin >> x;
	}
	double tongNo = this->tienNoGoc;
	for (int i = 0; i < x; i++) {
		tongNo += tongNo * this->laiSuat[i];
	}
	return tongNo;
}

double NoNamRuoi::laiNoSauXThang(int x)
{
	while (x < 0 || x>18) {
		cout << "Thoi gian truyen vao khong hop le, nhap lai: ";
		cin >> x;
	}
	return this->tinhTongNoSauXThang(x) - this->tienNoGoc;
}

void NoNamRuoi::xuatThongTinNo()
{
	cout << "Tien no goc: " << this->tienNoGoc << " trieu vnd" << endl;
	cout << "Lai suat "<<this->laiSuat.size()<<" thang lan luot la : " << endl;
	for (int i = 0; i < this->laiSuat.size(); i++) {
		cout << "Thang " << i + 1 << ": " << this->laiSuat[i]*100 << "%" << endl;
	}
	cout << "Ngay muon: " << this->ngayMuonNo << endl;
	cout << "Tong no: " << this->tinhTongNoSauXThang(18) << " trieu vnd" << endl;
	int ngay = stoi(this->ngayMuonNo.substr(0, 2));
	int thang = stoi(this->ngayMuonNo.substr(3, 2));
	int nam = stoi(this->ngayMuonNo.substr(6, 4));
	for (int i = 0; i < 18; i++) {
		thang += 1;
		if (thang > 12) {
			thang = 1;
			nam += 1;
		}
	}
	string ngayTra = to_string(ngay) + "/" + to_string(thang) + '/' + to_string(nam);
	cout << "Ngay dao han: " << ngayTra << endl;
}
