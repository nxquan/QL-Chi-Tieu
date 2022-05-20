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
	TKTietKiem(int, double, double);
	void ganTienGui(double);
	double layTienGui();
	int layKiHan();
	int laySoThangDaGui();
	void ganLaiSuat(double);
	double tatToanTKTietKiem();
	~TKTietKiem();
};

#endif // !TKTietKiem_h
