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
	void ganLaiSuat();
	void nhapKhoanNo();
	double tinhTongNo();
	double tinhTongNoSauXThang(int);
	double laiNoSauXThang(int);
};
#endif // !NoBaNam_h



