#include "NoBaNam.h"

NoBaNam::NoBaNam()
{
	this->laiSuat = 0;
}

void NoBaNam::ganLaiSuat()
{
	double lai;
	cout << "Nhap lai suat(%): ";
	cin >> lai;
	this->laiSuat = lai/100;
}

void NoBaNam::nhapKhoanNo()
{
	cout << "Nhap khoan no 3 nam" << endl;
	cin.ignore();
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

//double NoBaNam::tinhTongNo()
//{
//	return this->tienNoGoc*pow((1+this->laiSuat),3);
//}

double NoBaNam::tinhTongNoSauXThang(int x)
{
	while (x < 0 || x>36) {
		cout << "Thoi gian truyen vao khong hop le, nhap lai: ";
		cin >> x;
	}
	double laiSuatThang = this->laiSuat / 12;
	return this->tienNoGoc*pow((1+laiSuatThang),x);
}

double NoBaNam::laiNoSauXThang(int x)
{
	while (x < 0 || x>36) {
		cout << "Thoi gian truyen vao khong hop le, nhap lai: ";
		cin >> x;
	}
	return this->tinhTongNoSauXThang(x)-this->tienNoGoc;
}

void NoBaNam::xuatThongTinNo()
{
	cout << "Tien no goc: " << this->tienNoGoc << " trieu vnd" << endl;
	cout << "Lai suat " << this->laiSuat * 100 << "%" << endl;
	cout << "Ngay muon: " << this->ngayMuonNo << endl;
	cout << "Tong no: " << this->tinhTongNoSauXThang(36) << " trieu vnd" << endl;
	string namTra = this->ngayMuonNo.substr(6, 4);
	string ngayTra = this->ngayMuonNo;
	namTra = to_string(stoi(namTra) + 3);
	for (int i = 6; i < 10; i++) {
		ngayTra[i] = namTra[i - 6];
	}
	cout << "Ngay dao han: " << ngayTra << endl;
}
