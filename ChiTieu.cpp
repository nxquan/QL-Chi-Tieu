#include "ChiTieu.h"

ChiTieu::ChiTieu()
{
	this->anUong = 0;
	this->dienNuoc = 0;
	this->khac = 0;
}

void ChiTieu::nhapChiTieu()
{
	cout << "Nhap tien an uong: ";
	cin >> this->anUong;
	cout << "Nhap tien dien nuoc: ";
	cin >> this->dienNuoc;
	cout << "Nhap khoan tien khac: ";
	cin >> this->khac;
}

double ChiTieu::tinhTongChiTieu()
{
	return this->anUong + this->dienNuoc + this->khac;
}

ChiTieu::~ChiTieu(){}
