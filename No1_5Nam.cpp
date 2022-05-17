#include "NoNamRuoi.h"

NoNamRuoi::NoNamRuoi()
{
	this->laiSuat.resize(18);
	for (int i = 0; i < this->laiSuat.size(); i++) {
		this->laiSuat[i] = 0;
	}
}

void NoNamRuoi::ganLaiSuatThang()
{
	for (int i = 0; i < this->laiSuat.size(); i++) {
		cout << "Nhap lai suat thang thu " << i + 1 << ": ";
		cin >> this->laiSuat[i];
	}
}

double NoNamRuoi::tinhTongNo()
{
	double tongNo = this->tienNoGoc;
	for (int i = 0; i < this->laiSuat.size(); i++) {
		tongNo += tongNo * this->laiSuat[i];
	}
	return tongNo;
}

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
