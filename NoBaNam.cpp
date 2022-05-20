#include "NoBaNam.h"

NoBaNam::NoBaNam()
{
	this->laiSuat = 0;
}

void NoBaNam::ganLaiSuat()
{
	double lai;
	cout << "Nhap lai suat: ";
	cin >> lai;
	this->laiSuat = lai;
}

void NoBaNam::nhapKhoanNo()
{
	cout << "Nhap khoan no 3 nam" << endl;
	cin.ignore();
	cout << "Nhap ngay muon: ";
	getline(cin, this->ngayMuonNo);
	cout << "Nhap so tien muon: ";
	cin >> this->tienNoGoc;
	this->ganLaiSuat();
}

double NoBaNam::tinhTongNo()
{
	return this->tienNoGoc*pow((1+this->laiSuat),3);
}

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
