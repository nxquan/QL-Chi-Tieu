#include "TKTietKiem.h"

TKTietKiem::TKTietKiem()
{
	this->tienGui = 0;
	this->laiSuat = 0;
	this->kiHan = 0;
	this->soThangDaGui = 0;
}

TKTietKiem::TKTietKiem(int kiHan, double laiSuat, double tienGui)
{
	this->kiHan = kiHan;
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

int TKTietKiem::layKiHan()
{
	return this->kiHan;
}

int TKTietKiem::laySoThangDaGui()
{
	return this->soThangDaGui;
}

void TKTietKiem::ganLaiSuat(double laiSuat)
{
	this->laiSuat = laiSuat;
}


double TKTietKiem::tatToanTKTietKiem()
{
	return this->tienGui * this->laiSuat + this->tienGui;
}

TKTietKiem::~TKTietKiem(){}
