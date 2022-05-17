#pragma once
#ifndef TKTietKiem_h
#define TKTietKiem_h
#include<iostream>
using namespace std;

class TKTietKiem
{
private:
	int thoiHan;
	double tienGui;
	double laiSuat;
	double tienNhan;
public:
	TKTietKiem();
	TKTietKiem(int, double, double);//thoiHan, laiSuat, tienGui
	void ganTienGui(double);
	double layTienGui();
	void ganLaiSuat(double);
	double tinhTienNhanDungKyHan();
	~TKTietKiem();
};

#endif // !TKTietKiem_h
