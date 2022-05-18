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
	void ganLaiSuat();
	double tinhTongNo();
	double tinhTongNoSauXThang(int);
};
#endif // !NoNamRuoi_h
