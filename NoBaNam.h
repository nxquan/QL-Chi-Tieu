#ifndef NoBaNam_h
#define NoBaNam_h
#include "TienNo.h"
#include <iostream>
using namespace std;
class NoBaNam:public TienNo
{
private:
	double laiSuat;
public:
	NoBaNam();
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
#endif // !NoBaNam_h



