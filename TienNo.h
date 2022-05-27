#ifndef TienNo_h
#define TienNo_h
#include <iostream>
#include <string>
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
	virtual void nhapKhoanNo() = 0;
	/*virtual double tinhTongNo() = 0;*/
	virtual double tinhTongNoSauXThang(int) = 0;
	virtual double laiNoSauXThang(int) = 0;
	virtual void xuatThongTinNo() = 0;
};
#endif // !TienNo_h



