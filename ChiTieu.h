
#pragma once
#ifndef ChiTieu_h
#define ChiTieu_h
#include<iostream>
using namespace std;

class ChiTieu
{
private:
	double anUong;
	double dienNuoc;
	double khac;
public:
	ChiTieu();
	void nhapChiTieu();
	void xuatChiTieu();

	double layTienAnUong();
	double layTienDienNuoc();
	double layChiTieuKhac();

	double tinhTongChiTieu();
	~ChiTieu();
};

#endif // !ChiTieu_h
