#include "ThuNhap.h"

ThuNhap::ThuNhap()
{
	this->luong = 0;
	this->thuNhapKhac = 0;
}

ThuNhap::ThuNhap(double luong, double thuNhapKhac)
{
	this->luong = luong;
	this->thuNhapKhac = thuNhapKhac;
}

void ThuNhap::nhapLuong()
{
	cout << "Nhap tong luong 2 vo chong: ";
	cin >> this->luong;
}

void ThuNhap::nhapThuNhapKhac()
{
	cout << "Nhap tong thu nhap khac: ";
	cin >> this->thuNhapKhac;
}

double ThuNhap::layLuong()
{
	return this->luong;
}

double ThuNhap::layThuNhapKhac()
{
	return this->thuNhapKhac;
}

ThuNhap::~ThuNhap(){}
