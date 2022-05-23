#pragma once
#include <iostream>
#include <math.h>
using namespace std;

class Date
{
private:
	unsigned int ngay;
	unsigned int thang;
	unsigned int nam;
public:
	Date();
	Date(unsigned int, unsigned int, unsigned int);
	~Date();

	//setter
	void ganNgay(unsigned int);
	void ganThang(unsigned int);
	void ganNam(unsigned int);

	//getter
	unsigned int layNgay();
	unsigned int layThang();
	unsigned int layNam();

	//thang = thang + 1
	void tangThemThang();

	friend istream& operator >> (istream& in, Date& d);
	friend ostream& operator <<(ostream& out, Date& d);
};

