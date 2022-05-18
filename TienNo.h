#ifndef TienNo_h
#define TienNo_h
#include <iostream>
using namespace std;
class TienNo
{
protected:
	double tienNoGoc;
	string ngayMuonNo;
public:
	TienNo();
	void ganTienNoGoc(double);
	void ganNgayMuonNo(string);
	virtual void ganLaiSuat() = 0;
	virtual double tinhTongNo() = 0;
	virtual double tinhTongNoSauXThang(int x) = 0;
};
#endif // !TienNo_h
