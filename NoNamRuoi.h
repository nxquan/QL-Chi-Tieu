#ifndef NoNamRuoi_h
#define NoNamRuoi_h
#include "TienNo.h"
#include <iostream>
#include <vector>
using namespace std;
class NoNamRuoi:public TienNo
{
private:
	vector<double>laiSuat;
public:
	NoNamRuoi();
	void nhapLaiSuat();
	void ganLaiSuat(vector<double>);

	vector<double> layLaiSuat();

	void nhapKhoanNo();
	double layTienNoOThangThuX(int);
	double tinhTongNoSauXThang(int);
	double laiNoSauXThang(int);
	void xuatThongTinNo();
	string layNgayDaoHan();
	void ghiFile(ostream&);
};
#endif // !NoNamRuoi_h



