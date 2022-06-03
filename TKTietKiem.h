#pragma once
#ifndef TKTietKiem_h
#define TKTietKiem_h
#include<iostream>
#include <string>
#include <fstream>
using namespace std;

class TKTietKiem
{
private:
	int kiHan;
	double tienGui;
	double laiSuat;
	int soThangDaGui;
	string ngayGui;
	string ngayDaoHan;
	bool daTatToan;
public:
	TKTietKiem();
	TKTietKiem(int, double, double,int,string);//kiHan, laiSuat, tienGui, soThangDaGui

	void ganTienGui(double);
	void ganLaiSuat(double);
	void capNhatSoThangDaGui();
	void capNhatTinhTrang();
	bool kiemTraTinhTrang();

	double layTienGui();
	int layKiHan();
	int laySoThangDaGui();
	string layNgayGui();
	void xuatThongTin();
	void ghiFile(ostream&);

	double tattoanTKTietKiem();
	~TKTietKiem();
};

#endif // !TKTietKiem_h
