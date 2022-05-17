#include "TKTietKiem.h"

TKTietKiem::TKTietKiem()
{
	this->tienGui = 0;
	this->laiSuat = 0;
	this->thoiHan = 0;
	this->tienNhan = 0;
}

TKTietKiem::TKTietKiem(int thoiHan, double laiSuat, double tienGui)
{
	this->thoiHan = thoiHan;
	this->laiSuat = laiSuat;
	this->tienGui = tienGui;
}

void TKTietKiem::ganTienGui(double tienGui)
{
	this->tienGui = tienGui;
}

double TKTietKiem::layTienGui()
{
	return this->tienGui;
}

void TKTietKiem::ganLaiSuat(double laiSuat)
{
	this->laiSuat = laiSuat;
}

double TKTietKiem::tinhTienNhanDungKyHan()
{
	return this->tienGui * this->laiSuat + this->tienGui;
}

TKTietKiem::~TKTietKiem(){}
