#pragma once
#ifndef TKTietKiem_h
#define TKTietKiem_h
#include<iostream>
#include <string>
using namespace std;

class TKTietKiem
{
private:
	int kiHan;
	double tienGui;
	double laiSuat;
	int soThangDaGui;
	string ngayGui;
public:
	TKTietKiem();
	TKTietKiem(int, double, double,int,string);//kiHan, laiSuat, tienGui, soThangDaGui

	void ganTienGui(double);
	void ganLaiSuat(double);
	void capNhatSoThangDaGui();

	double layTienGui();
	int layKiHan();
	int laySoThangDaGui();
	void xuatThongTin();

	double tattoanTKTietKiem();
	~TKTietKiem();
};

#endif // !TKTietKiem_h
