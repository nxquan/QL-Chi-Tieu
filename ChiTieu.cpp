#include "ChiTieu.h"

ChiTieu::ChiTieu()
{
	this->anUong = 0;
	this->dienNuoc = 0;
	this->khac = 0;
}

void ChiTieu::nhapChiTieu()
{
	cout << "Nhap tien an uong(Trieu VND): ";
	cin >> this->anUong;
	cout << "Nhap tien dien nuoc(Trieu VND): ";
	cin >> this->dienNuoc;
	cout << "Nhap khoan tien khac(Trieu VND): ";
	cin >> this->khac;
}
void ChiTieu::xuatChiTieu() {
	cout << "- Tien an, uong: " << this->anUong << " trieu" << endl;
	cout << "- Tien dien, nuoc: " << this->dienNuoc << " trieu" << endl;
	cout << "- Chi tieu khac: " << this->khac << " trieu" << endl;
}
double ChiTieu::tinhTongChiTieu()
{
	return this->anUong + this->dienNuoc + this->khac;
}
double ChiTieu::layTienAnUong() {
	return this->anUong;
}
double ChiTieu::layTienDienNuoc() {
	return this->dienNuoc;
}
double ChiTieu::layChiTieuKhac() {
	return this->khac;
}
ChiTieu::~ChiTieu(){}
