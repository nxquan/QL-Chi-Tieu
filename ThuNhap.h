#pragma once
#ifndef ThuNhap_h
#define ThuNhap_h
#include<iostream>
using namespace std;

class ThuNhap
{
private:
	double luong;
	double thuNhapKhac;
public:
	ThuNhap();
	ThuNhap(double,double);//luong, thuNhapKhac
	void nhapLuong();
	void nhapThuNhapKhac();
	double layLuong();
	double layThuNhapKhac();
	~ThuNhap();
};

#endif // !ThuNhap_h

