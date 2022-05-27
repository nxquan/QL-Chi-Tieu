#pragma once
#ifndef ThuNhap_h
#define ThuNhap_h
#include<iostream>
using namespace std;

class ThuNhap
{
private:
	double luongChong;
	double luongVo;
	double thuNhapKhac;
public:
	ThuNhap();
	ThuNhap(double,double, double);//luongChong, luongVo, thuNhapKhac
	void nhapLuongVoChong();
	void nhapThuNhapKhac();

	double layLuongChong();
	double layLuongVo();
	double layThuNhapKhac();
	double tongLuongVoChong();

	void xuatThuNhap();
	void nhapThuNhap();
	~ThuNhap();
};

#endif // !ThuNhap_h

