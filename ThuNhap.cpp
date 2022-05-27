#include "ThuNhap.h"

ThuNhap::ThuNhap()
{
	this->luongChong = 0;
	this->luongVo = 0;
	this->thuNhapKhac = 0;
}

ThuNhap::ThuNhap(double luongChong, double luongVo, double thuNhapKhac)
{
	this->luongChong = luongChong;
	this->luongVo = luongVo;
	this->thuNhapKhac = thuNhapKhac;
}

void ThuNhap::nhapLuongVoChong()
{
	cout << "Nhap luong chong: ";
	cin >> this->luongChong;
	cout << "Nhap luong vo: ";
	cin >> this->luongVo;
}

void ThuNhap::nhapThuNhapKhac()
{
	cout << "Nhap tong thu nhap khac: ";
	cin >> this->thuNhapKhac;
}

double ThuNhap::layLuongChong()
{
	return this->luongChong;
}

double ThuNhap::layLuongVo()
{
	return this->luongVo;
}

double ThuNhap::layThuNhapKhac()
{
	return this->thuNhapKhac;
}

double ThuNhap::tongLuongVoChong()
{
	return this->luongVo + this->luongChong;
}

void ThuNhap::nhapThuNhap()
{
	this->nhapLuongVoChong();
	this->nhapThuNhapKhac();
}

void ThuNhap::xuatThuNhap() {
	cout << "+ Luong chong: " << this->luongChong << " Trieu" << endl;
	cout << "+ Luong vo: " << this->luongVo << " Trieu" << endl;
	cout << "+ Thu nhap khac: " << this->thuNhapKhac << " Trieu" << endl;
}

ThuNhap::~ThuNhap(){}
