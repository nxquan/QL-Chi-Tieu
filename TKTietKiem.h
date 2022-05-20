#pragma once
#ifndef TKTietKiem_h
#define TKTietKiem_h
#include<iostream>
using namespace std;

class TKTietKiem
{
private:
	int kiHan;
	double tienGui;
	double laiSuat;
	int soThangDaGui;
public:
	TKTietKiem();
	TKTietKiem(int, double, double);//kiHan, laiSuat, tienGui

	void ganTienGui(double);
	void ganLaiSuat(double);

	double layTienGui();
	int layKiHan();
	int laySoThangDaGui();

	double tattoanTKTietKiem();
	~TKTietKiem();
};

#endif // !TKTietKiem_h
